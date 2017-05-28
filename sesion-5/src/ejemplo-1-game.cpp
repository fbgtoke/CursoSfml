#include "ejemplo-1-game.hpp"

const int Game::screenWidth  = 480;
const int Game::screenHeight = 480;
const std::string Game::screenTitle = "Hello World";

const std::string Game::FONT_FILE = "res/fonts/font.ttf";
const float Game::FONT_SCALE = 1.5f;
const sf::Color Game::FONT_COLOR = sf::Color::White;

const sf::Vector2f Game::PADDING = { 40.0f, 10.0f };
const sf::Vector2f Game::CURSOR_PADDING = { -40.0f, 15.0f };
const float Game::TITLE_MARGIN   = 80.0f;
const float Game::OPTIONS_MARGIN = 50.0f;

const std::string Game::TEXT_TITLE = "VGA - Curso SFML";
const std::string Game::TEXT_PLAY  = "PLAY!";
const std::string Game::TEXT_ABOUT = "ABOUT";
const std::string Game::TEXT_EXIT  = "EXIT";

const std::string Game::TEXTURE_CURSOR = "res/img/cursor.png";

void Game::run() {
  init();
  mainLoop();
}

void Game::init() {
  window.create(sf::VideoMode(screenWidth, screenHeight), screenTitle);
  window.setKeyRepeatEnabled(false);

  font.loadFromFile(FONT_FILE);
  textureCursor.loadFromFile(TEXTURE_CURSOR);

  cursorState = Game::PLAY;

  clk.restart();
}

void Game::mainLoop() {
  while (window.isOpen()) {
    // Gestion de eventos
    events();
    
    // Logica de estado
    update();

    // Logica de dibujo
    draw();
  }
}

void Game::update() {
  sf::Time deltatime;
  deltatime = clk.restart();
}

void Game::draw() {
  window.clear(sf::Color::Black);
  
  drawTexts();
  drawCursor();

  window.display();
}

void Game::events() {
  sf::Event event;

  while (window.pollEvent(event)) {
    if (event.type == sf::Event::Closed)
      window.close();

    else if (event.type == sf::Event::KeyPressed) {
      switch (event.key.code) {
        case sf::Keyboard::Escape:
          window.close();
          break;

        case sf::Keyboard::Up:
          if (cursorState == Game::PLAY)
            cursorState = Game::EXIT;
          else if (cursorState == Game::ABOUT)
            cursorState = Game::PLAY;
          else if (cursorState == Game::EXIT)
            cursorState = Game::ABOUT;
          break;

        case sf::Keyboard::Down:
          if (cursorState == Game::PLAY)
            cursorState = Game::ABOUT;
          else if (cursorState == Game::ABOUT)
            cursorState = Game::EXIT;
          else if (cursorState == Game::EXIT)
            cursorState = Game::PLAY;
          break;

        case sf::Keyboard::Return:
          if (cursorState == Game::EXIT)
            window.close();
          break;

        default:
          break;
      }
    }
  }
}

void Game::drawTexts() {
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

void Game::drawCursor() {
  sf::Sprite sprite(textureCursor);

  sprite.move(PADDING);
  sprite.move(CURSOR_PADDING);
  sprite.move(0, TITLE_MARGIN);

  if (cursorState == Game::ABOUT) {
    sprite.move(0, OPTIONS_MARGIN);
  } else if (cursorState == Game::EXIT) {
    sprite.move(0, OPTIONS_MARGIN);
    sprite.move(0, OPTIONS_MARGIN);
  }

  window.draw(sprite);
}