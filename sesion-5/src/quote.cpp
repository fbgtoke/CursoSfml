#include "quote.hpp"

const int   Quote::SIZE = 16; // pixels
const float Quote::VEL  = 120.0f; // pixels/s

const sf::Time Quote::FRAME_TIME = sf::seconds(0.125f);

const float Quote::START_X =   0.0f; // pixels
const float Quote::START_Y = 128.0f; // pixels

const float Quote::SCALE = 4.0f;

const char Quote::TEXTURE_FILE[] = "res/img/quote-2.png";

Quote::Quote()
	: sprite(nullptr) {
	setCurrentState(FACE_RIGHT);

	texture.loadFromFile(Quote::TEXTURE_FILE);

	animations[FACE_RIGHT].addFrame({0, SIZE, SIZE, SIZE});

	animations[FACE_LEFT].addFrame({0, 0, SIZE, SIZE});

	animations[WALK_RIGHT].addFrame({SIZE, SIZE, SIZE, SIZE});
	animations[WALK_RIGHT].addFrame({   0, SIZE, SIZE, SIZE});
	animations[WALK_RIGHT].setFrameTime(Quote::FRAME_TIME);

	animations[WALK_LEFT].addFrame({SIZE, 0, SIZE, SIZE});
	animations[WALK_LEFT].addFrame({   0, 0, SIZE, SIZE});
	animations[WALK_LEFT].setFrameTime(Quote::FRAME_TIME);

	sprite = new AnimatedSprite(texture, &animations[currentState]);
	sprite->setPosition(Quote::START_X, Quote::START_Y);
	sprite->setScale(Quote::SCALE, Quote::SCALE);
}

Quote::~Quote() {
	delete sprite;
}
	
void Quote::update(const sf::Time& deltatime) {
	sprite->update(deltatime);

	float seconds = deltatime.asSeconds();

	if (currentState == WALK_RIGHT)
		sprite->move(50 * seconds, 0.0f);
	else if (currentState == WALK_LEFT)
		sprite->move(-50 * seconds, 0.0f);
}

void Quote::draw(sf::RenderWindow& window) const {
	window.draw(*sprite);
}

void Quote::event(const sf::Event& event) {
	if (event.type == sf::Event::KeyPressed) {
		switch (event.key.code) {
			case sf::Keyboard::Left:
				setCurrentState(WALK_LEFT);
				break;

			case sf::Keyboard::Right:
				setCurrentState(WALK_RIGHT);
				break;

			default:
				break;
		}
	} else if (event.type == sf::Event::KeyReleased) {
		switch (event.key.code) {
			case sf::Keyboard::Left:
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
					setCurrentState(WALK_RIGHT);
				else
					setCurrentState(FACE_LEFT);
				break;
				
			case sf::Keyboard::Right:
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
					setCurrentState(WALK_LEFT);
				else
					setCurrentState(FACE_RIGHT);
				break;

			default:
				break;
		}
	}
}

void Quote::setCurrentState(Quote::QuoteState state) {
	if (sprite != nullptr && currentState != state) {
		animations[currentState].stop();
		currentState = state;
		animations[currentState].play();

		sprite->setAnimation(&animations[currentState]);
	}
}