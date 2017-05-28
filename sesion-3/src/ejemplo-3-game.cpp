#include "ejemplo-3-game.hpp"

const int Game::screenWidth  = 480;
const int Game::screenHeight = 480;
const std::string Game::screenTitle = "Hello World";

void Game::run() {
  init();
  mainLoop();
}

void Game::init() {
  window.create(sf::VideoMode(screenWidth, screenHeight), screenTitle);
  window.setKeyRepeatEnabled(false);

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

  quote.update(deltatime);
}

void Game::draw() {
  window.clear(sf::Color::Magenta);
  quote.draw(window);   
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

    quote.event(event);
  }
}