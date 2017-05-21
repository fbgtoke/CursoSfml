#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

#include <iostream>
#include "canica.hpp"

class Game  {
public:
  void run();

private:
  static const int screenWidth;
  static const int screenHeight;
  static const char screenTitle[];

  sf::RenderWindow window;
  sf::Clock clk;

  Canica canica;

  void init();
  void mainLoop();

  void update();
  void draw();
  void events();
};

#endif