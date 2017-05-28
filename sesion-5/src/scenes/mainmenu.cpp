#include "scenes/mainmenu.hpp"

const std::string MainMenu::FONT_FILE = "res/fonts/font.ttf";
const float MainMenu::FONT_SCALE = 1.5f;
const sf::Color MainMenu::FONT_COLOR = sf::Color::White;

const sf::Vector2f MainMenu::PADDING = { 40.0f, 10.0f };
const sf::Vector2f MainMenu::CURSOR_PADDING = { -40.0f, 15.0f };
const float MainMenu::TITLE_MARGIN   = 80.0f;
const float MainMenu::OPTIONS_MARGIN = 50.0f;

const std::string MainMenu::TEXT_TITLE = "VGA - Curso SFML";
const std::string MainMenu::TEXT_PLAY  = "PLAY!";
const std::string MainMenu::TEXT_ABOUT = "ABOUT";
const std::string MainMenu::TEXT_EXIT  = "EXIT";

const std::string MainMenu::TEXTURE_CURSOR = "res/img/cursor.png";

MainMenu::MainMenu(Game& game) : Scene(game) {}
MainMenu::~MainMenu() {}

void MainMenu::onInit() {
	Scene::onInit();
	std::cout << "onInit: MainMenu" << std::endl;

	font.loadFromFile(FONT_FILE);
	textureCursor.loadFromFile(TEXTURE_CURSOR);

  cursorState = MainMenu::PLAY;
}

void MainMenu::onResume() {
	Scene::onResume();
	std::cout << "onResume: MainMenu" << std::endl;
}

void MainMenu::onPause()  {
	Scene::onPause();
	std::cout << "onPause: MainMenu" << std::endl;
}

void MainMenu::onEnd()    {
	Scene::onEnd();
	std::cout << "onEnd: MainMenu" << std::endl;
}

void MainMenu::update(const sf::Time& deltatime) {

}

void MainMenu::draw(sf::RenderWindow& window) const {
	drawTexts(window);
	drawCursor(window);
}

void MainMenu::event(const sf::Event& event) {
	if (event.type == sf::Event::KeyPressed) {
    switch (event.key.code) {
      case sf::Keyboard::Up:
        if (cursorState == MainMenu::PLAY)
          cursorState = MainMenu::EXIT;
        else if (cursorState == MainMenu::ABOUT)
          cursorState = MainMenu::PLAY;
        else if (cursorState == MainMenu::EXIT)
          cursorState = MainMenu::ABOUT;
        break;

      case sf::Keyboard::Down:
        if (cursorState == MainMenu::PLAY)
          cursorState = MainMenu::ABOUT;
        else if (cursorState == MainMenu::ABOUT)
          cursorState = MainMenu::EXIT;
        else if (cursorState == MainMenu::EXIT)
          cursorState = MainMenu::PLAY;
        break;

      case sf::Keyboard::Return:
      	if (cursorState == MainMenu::PLAY) {
      		game.setBackgroundScene(Scene::create(game, Scene::TEST_1));
      		pause();
      	} else if (cursorState == MainMenu::ABOUT) {
      		game.setBackgroundScene(Scene::create(game, Scene::TEST_2));
      		pause();
      	} else if (cursorState == MainMenu::EXIT) {
          end();
      	}
        break;

      default:
        break;
    }
  }
}

void MainMenu::drawTexts(sf::RenderWindow& window) const {
  sf::Text text;
  text.setFont(font);
  text.setColor(FONT_COLOR);
  text.setScale(FONT_SCALE, FONT_SCALE);

  // Draw title
  text.move(PADDING);
  text.setString(TEXT_TITLE);
  window.draw(text);

  // Draw options
  text.move(0, TITLE_MARGIN);
  text.setString(TEXT_PLAY);
  window.draw(text);
  text.move(0, OPTIONS_MARGIN);
  text.setString(TEXT_ABOUT);
  window.draw(text);
  text.move(0, OPTIONS_MARGIN);
  text.setString(TEXT_EXIT);
  window.draw(text);
}

void MainMenu::drawCursor(sf::RenderWindow& window) const {
  sf::Sprite sprite(textureCursor);

  sprite.move(PADDING);
  sprite.move(CURSOR_PADDING);
  sprite.move(0, TITLE_MARGIN);

  if (cursorState == MainMenu::ABOUT) {
    sprite.move(0, OPTIONS_MARGIN);
  } else if (cursorState == MainMenu::EXIT) {
    sprite.move(0, OPTIONS_MARGIN);
    sprite.move(0, OPTIONS_MARGIN);
  }

  window.draw(sprite);
}