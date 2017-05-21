#include "coin.hpp"

const unsigned int Coin::TILE_SIZE = 16;

const std::string Coin::TEXTURE_NAME = "res/img/coin.png";

Coin::Coin(const sf::Vector2i& position)
	: clicked(false) {

	texture.loadFromFile(Coin::TEXTURE_NAME);
	setPosition(position);
}

void Coin::setPosition(const sf::Vector2i& position) {
	this->position.x = position.x * TILE_SIZE;
	this->position.y = position.y * TILE_SIZE;
}

bool Coin::isClicked() const { return clicked; }

void Coin::draw(sf::RenderWindow& window) {
	if (!isClicked()) {
		sf::Sprite sprite(texture);
		sprite.setPosition(position.x, position.y);
		window.draw(sprite);
	}
}

void Coin::event(const sf::Event& event) {
	if (!isClicked()) {
		if (event.type == sf::Event::MouseButtonPressed) {
			if (event.mouseButton.button == sf::Mouse::Left) {
				const int mouseX = event.mouseButton.x;
				const int mouseY = event.mouseButton.y;
				const sf::Vector2u size = texture.getSize();

				const sf::IntRect rect(position.x, position.y, size.x, size.y);

				if (rect.contains(mouseX, mouseY)) {
					clicked = true;
				}
			}
		}
	}
}