#ifndef CANICA_HPP
#define CANICA_HPP

#include <SFML/Graphics.hpp>

class Canica {
public:
	Canica();
	Canica(const sf::Vector2f& position);

	void update(const sf::Time& deltatime);
	void draw(sf::RenderWindow& window) const;

	void setPosition(const sf::Vector2f& position);
	void setVelocity(const sf::Vector2f& velocity);
	void setAcceleration(const sf::Vector2f& acceleration);

	sf::Vector2f getPosition() const;

private:
	static const float GRAVITY;
	static const float FRICTION;

	static const float LEFT_BOUNDARY;
	static const float RIGHT_BOUNDARY;
	static const float FLOOR;

	static const float RADIUS;
	static const float HALF_RADIUS;
	static const float DIAMETER;

	static const float EPSILON;

	sf::Vector2f pos;
	sf::Vector2f vel;
	sf::Vector2f acc;
};

#endif