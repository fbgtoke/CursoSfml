#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

class Game  {
public:
  void run();

private:
  static const int screenWidth;
  static const int screenHeight;
  static const char screenTitle[];

  sf::RenderWindow window;
  sf::Clock clk;

  static const std::string FONT_FILE;
  static const float FONT_SCALE;
  static const sf::Color FONT_COLOR;
  sf::Font font;

  static const sf::Vector2f PADDING;
  static const sf::Vector2f CURSOR_PADDING;
  static const float TITLE_MARGIN;
  static const float OPTIONS_MARGIN;

  static const std::string TEXT_TITLE;
  static const std::string TEXT_PLAY;
  static const std::string TEXT_ABOUT;
  static const std::string TEXT_EXIT;

  static const std::string TEXTURE_CURSOR;
  sf::Texture textureCursor;

  enum CursorState {
    PLAY,
    ABOUT,
    EXIT,
    NUM_STATES
  };
  CursorState cursorState;

  void init();
  void mainLoop();

  void update();
  void draw();
  void events();

  void drawTexts();
  void drawCursor();
};

#endif