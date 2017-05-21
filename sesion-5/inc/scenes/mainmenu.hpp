#ifndef MAIN_MENU_HPP
#define MAIN_MENU_HPP

#include "scene.hpp"
#include "ejemplo-2-game.hpp"
#include <iostream>

class MainMenu : public Scene {
public:
	MainMenu(Game& game);
	~MainMenu() final;

	void onInit() final;
	void onResume() final;
	void onPause() final;
	void onEnd() final;

	void update(const sf::Time& deltatime) final;
	void draw(sf::RenderWindow& window) final;
	void event(const sf::Event& event) final;

private:
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

	void drawTexts(sf::RenderWindow& window);
	void drawCursor(sf::RenderWindow& window);
};

#endif