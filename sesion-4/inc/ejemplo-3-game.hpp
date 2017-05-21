#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

#include <list>

#include "tilemap.hpp"
#include "coin.hpp"

class Game  {
public:
  ~Game();

  void run();

private:
  static const int screenWidth;
  static const int screenHeight;
  static const char screenTitle[];

  sf::RenderWindow window;
  sf::Clock clk;

  Tilemap tilemap;
  std::list<Coin*> coins;

  static const std::string FONT_FILE;
  sf::Font font;

  void init();
  void initTilemap();
  void initCoins();

  void mainLoop();

  void update();
  void draw();
  void events();

  unsigned int getScore();
  void drawScore();
};

#endif