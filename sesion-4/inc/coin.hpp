#ifndef COIN_HPP
#define COIN_HPP

#include <SFML/Graphics.hpp>

class Coin {
public:
	Coin(const sf::Vector2i& position);

	void setPosition(const sf::Vector2i& position);

	bool isClicked() const;

	void draw(sf::RenderWindow& window);
	void event(const sf::Event& event);

private:
	static const unsigned int TILE_SIZE;

	static const std::string TEXTURE_NAME;
	sf::Texture texture;

	sf::Vector2i position;
	bool clicked;
};

#endif