#include "ejemplo-4-game.hpp"

const int Game::screenWidth    = 480;
const int Game::screenHeight   = 480;
const char Game::screenTitle[] = "Hello World";

void Game::run() {
  init();
  mainLoop();
}

void Game::init() {
  window.create(sf::VideoMode(screenWidth, screenHeight), screenTitle);
  clk.restart();

  canica.setVelocity({ 100.0f, 0.0f });
}

void Game::mainLoop() {
  while (window.isOpen()) {
    // Logica de estado
    update();

    // Logica de dibujo
    draw();

    // Gestion de eventos
    events();
  }
}

void Game::update() {
  sf::Time deltatime;
  deltatime = clk.restart();

  canica.update(deltatime);
}

void Game::draw() {
  window.clear(sf::Color::Black);
  canica.draw(window);
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
  }
}