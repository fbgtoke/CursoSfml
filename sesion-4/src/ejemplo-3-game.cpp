#include "ejemplo-3-game.hpp"

const int Game::screenWidth  = 432;
const int Game::screenHeight = 264;
const std::string Game::screenTitle = "Hello World";

const std::string Game::FONT_FILE = "res/fonts/font.ttf";

Game::~Game() {
  for (Coin* coin : coins)
    delete coin;

  coins.clear();
}

void Game::run() {
  init();
  mainLoop();
}

void Game::init() {
  window.create(sf::VideoMode(screenWidth, screenHeight), screenTitle);
  window.setKeyRepeatEnabled(false);

  initTilemap();
  initCoins();
  
  font.loadFromFile(FONT_FILE);

  clk.restart();
}

void Game::initTilemap() {
  tilemap.create(27, 25);

  for (unsigned int i = 0; i < 27; ++i) {
    tilemap.setTile(i, 12, 1);
    tilemap.setTile(i, 13, 1);
  }

  tilemap.setBackground("res/img/background.png");
  tilemap.setTilesheet("res/img/tilesheet.png");
}

void Game::initCoins() {
  for (int i = 5; i < 12; ++i) {
    coins.push_back(new Coin({ i,  8 }));
    coins.push_back(new Coin({ i,  9 }));
    coins.push_back(new Coin({ i, 10 }));
    coins.push_back(new Coin({ i, 11 }));
  }
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
  
  tilemap.draw(window);

  for (Coin* coin : coins)
    coin->draw(window);

  drawScore();

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

        default:
          break;
      }
    }

    for (Coin* coin : coins)
      coin->event(event);
  }
}

unsigned int Game::getScore() {
  unsigned int score = 0;

  for (const Coin* coin : coins)
    if (coin->isClicked())
      score++;

  return score;
}

void Game::drawScore() {
  sf::Text text;
  text.setFont(font);
  text.setColor(sf::Color::White);
  text.setPosition(0, 232);

  std::string score;
  score += "score x ";
  score += std::to_string(getScore());
  text.setString(score);

  window.draw(text);
}