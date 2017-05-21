#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

#include "scene.hpp"

class Game  {
public:
  Game();
  ~Game();

  void run();

  void setActiveScene(Scene* scene);
  void setBackgroundScene(Scene* scene);

private:
  static const int screenWidth;
  static const int screenHeight;
  static const char screenTitle[];

  sf::RenderWindow window;
  sf::Clock clk;

  Scene* activeScene;
  Scene* backgroundScene;
  
  void init();
  void mainLoop();

  void update();
  void draw();
  void events();
  void scene();

  void pauseActiveScene();
  void terminateActiveScene();
};

#endif