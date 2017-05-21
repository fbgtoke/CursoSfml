#include "tilemap.hpp"

const unsigned int Tilemap::TILE_SIZE = 16;

Tilemap::Tilemap() : width(0), height(0) {}

Tilemap::Tilemap(unsigned int width, unsigned int height)
	: width(width), height(height) {

	tiles = tile_matrix(height, tile_vector(width, 0));
}

void Tilemap::create(unsigned int width, unsigned int height) {
	this->width  = width;
	this->height = height;

	tiles = tile_matrix(height, tile_vector(width, 0));
}

bool Tilemap::outOfBounds(unsigned int x, unsigned int y) const {
	return x >= width || y >= height;
}

void Tilemap::setTilesheet(const std::string& filename) {
	tilesheet.loadFromFile(filename);
}

void Tilemap::setBackground(const std::string& filename) {
	background.loadFromFile(filename);
}

void Tilemap::setTile(unsigned int x, unsigned int y, unsigned int blockIndex) {
	if (!outOfBounds(x, y)) {
		tiles[y][x] = blockIndex;
	}
}

unsigned int Tilemap::getTile(unsigned int x, unsigned int y) const {
	if (outOfBounds(x, y)) {
		return 0;
	} else {
		return tiles[y][x];
	}
}

void Tilemap::draw(sf::RenderWindow& window) {
	sf::Sprite sprite;

	sprite.setTexture(background);
	window.draw(sprite);

	sprite.setTexture(tilesheet);
	sf::IntRect textureRect(0, 0, TILE_SIZE, TILE_SIZE);

	for (unsigned int i = 0; i < height; i++) {
		for (unsigned int j = 0; j < width; j++) {
			textureRect.left = tiles[i][j] * TILE_SIZE;
			sprite.setTextureRect(textureRect);

			sprite.setPosition(j * TILE_SIZE, i * TILE_SIZE);
			window.draw(sprite);
		}
	}
}