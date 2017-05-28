#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

#include "quote.hpp"

class Game  {
public:
  void run();

private:
  static const int screenWidth;
  static const int screenHeight;
  static const std::string screenTitle;

  sf::RenderWindow window;
  sf::Clock clk;

  Quote quote;

  void init();
  void mainLoop();

  void update();
  void draw();
  void events();
};

#endif