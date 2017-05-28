#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>

class Player {
public:
	Player();

	void update(const sf::Time& deltatime);
	void draw(sf::RenderWindow& window) const;

private:
};

#endif