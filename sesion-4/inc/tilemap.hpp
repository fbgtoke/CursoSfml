#ifndef TILEMAP_HPP
#define TILEMAP_HPP

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>

#include <iostream>

class Tilemap {
public:
	Tilemap();
	Tilemap(unsigned int width, unsigned int height);

	void create(unsigned int width, unsigned int height);

	bool outOfBounds(unsigned int x, unsigned int y) const;

	void setTilesheet(const std::string& filename);
	void setBackground(const std::string& filename);

	void setTile(unsigned int x, unsigned int y, unsigned int blockIndex);
	unsigned int getTile(unsigned int x, unsigned int y) const;

	void draw(sf::RenderWindow& window);
private:
	static const unsigned int TILE_SIZE;

	unsigned int width;
	unsigned int height;

	typedef std::vector<unsigned int> tile_vector;
	typedef std::vector<tile_vector> tile_matrix;
	tile_matrix tiles;

	sf::Texture tilesheet;
	sf::Texture background;
};

#endif