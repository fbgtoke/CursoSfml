#include "canica.hpp"

const float Canica::GRAVITY = 98.0f; // pixels/(s^2)
const float Canica::FRICTION = 0.8;

const float Canica::LEFT_BOUNDARY  = 0.0f;   // pixels
const float Canica::RIGHT_BOUNDARY = 480.0f; // pixels
const float Canica::FLOOR = 480;             // pixels

const float Canica::RADIUS = 15.0f; // pixels
const float Canica::HALF_RADIUS = Canica::RADIUS * 0.5f; // pixels
const float Canica::DIAMETER = Canica::RADIUS * 2.0f; // pixels

const float Canica::EPSILON = 0.0025f;

Canica::Canica() {
	setPosition({0, 0});
	setVelocity({0, 0});
	setAcceleration({0, Canica::GRAVITY});
}

Canica::Canica(const sf::Vector2f& position)
	: pos(position) {
	
	setVelocity({0, 0});
	setAcceleration({0, Canica::GRAVITY});	
}

void Canica::update(const sf::Time& deltatime) {
	float seconds = deltatime.asSeconds();

	vel.x += acc.x * seconds;
	vel.y += acc.y * seconds;

	pos.x += vel.x * seconds;
	pos.y += vel.y * seconds;

	// Lower boundary
	if (pos.y > Canica::FLOOR - Canica::RADIUS) {
		pos.y = Canica::FLOOR - Canica::RADIUS;

		if (vel.y > 0) {
			vel.y *= Canica::FRICTION * (-1);
		}
	}

	// Left Boundary
	if (pos.x < Canica::LEFT_BOUNDARY + Canica::RADIUS) {
		pos.x = Canica::LEFT_BOUNDARY + Canica::RADIUS;

		if (vel.x < 0) {
			vel.x *= Canica::FRICTION * (-1);
		}
	}

	// Right Boundary
	if (pos.x > Canica::RIGHT_BOUNDARY - Canica::RADIUS) {
		pos.x = Canica::RIGHT_BOUNDARY - Canica::RADIUS;

		if (vel.x > 0) {
			vel.x *= Canica::FRICTION * (-1);
		}
	}

	if (vel.y * vel.y < Canica::EPSILON * Canica::EPSILON) {
		vel.y = 0;
	}
}

void Canica::draw(sf::RenderWindow& window) const {
	sf::CircleShape circle;
	circle.setRadius(Canica::RADIUS);
	circle.setPosition(pos.x - Canica::RADIUS, pos.y - Canica::RADIUS);
	circle.setFillColor(sf::Color::Green);

	window.draw(circle);
}

void Canica::setPosition(const sf::Vector2f& position) { pos = position; }

void Canica::setVelocity(const sf::Vector2f& velocity) { vel = velocity; }

void Canica::setAcceleration(const sf::Vector2f& acceleration) { 
	acc = acceleration;
}

sf::Vector2f Canica::getPosition() const { return pos; }