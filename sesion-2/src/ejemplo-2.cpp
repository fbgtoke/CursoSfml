#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

#include <iostream>

/**
  Ejemplo 2 - Encapsulacion
  Distribuye el codigo del ejemplo-1 en diversas funciones
*/
const int screenWidth    = 480;
const int screenHeight   = 480;
const char screenTitle[] = "Hello World";

sf::RenderWindow window;
sf::Clock clk;

void init() {
  window.create(sf::VideoMode(screenWidth, screenHeight), screenTitle);
  clk.restart();
}

void update() {
  sf::Time deltatime;

  deltatime = clk.getElapsedTime();
  std::cout << deltatime.asMilliseconds() << std::endl;
}

void draw() {
  window.clear(sf::Color::Black);
  window.display();
}

void events() {
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

int main(int arg, char* argv[]) {
  init();

  while (window.isOpen()) {
    // Logica de estado
    update();

    // Logica de dibujo
    draw();

    // Gestion de eventos
    events();
  }

  return 0;
}
