#ifndef QUOTE_HPP
#define QUOTE_HPP

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "animation.hpp"
#include "animatedsprite.hpp"

class Quote {
public:
	Quote();
	~Quote();

	void update(const sf::Time& deltatime);
	void draw(sf::RenderWindow& window);
	void event(const sf::Event& event);

private:
	static const int   SIZE;
	static const float VEL;

	static const sf::Time FRAME_TIME;

	static const float START_X;
	static const float START_Y;

	static const float SCALE;

	enum QuoteState {
		FACE_RIGHT = 0,
		FACE_LEFT,
		WALK_RIGHT,
		WALK_LEFT,
		NUM_STATES
	};

	QuoteState currentState;

	void setCurrentState(Quote::QuoteState state);

	static const char TEXTURE_FILE[];
	sf::Texture texture;

	Animation animations[NUM_STATES];
	AnimatedSprite* sprite;
};

#endif