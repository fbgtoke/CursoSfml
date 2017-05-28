#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

#include <iostream>

/**
  Ejemplo 1 - Mouse Events
  Crea una ventana SFML con unas dimensiones y titulo determinado
  Captura y procesa eventos de raton
  Muestra por linea de comandos el boton del raton pulsado y su posicion
*/
int main() {
  const int screenWidth  = 480;
  const int screenHeight = 480;
  const std::string screenTitle = "Hello World";

  sf::RenderWindow window;
  window.create(sf::VideoMode(screenWidth, screenHeight), screenTitle);

  sf::Event event;

  while (window.isOpen()) {
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();

      else if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Escape) {
          window.close();
        }
      }

      else if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
          std::cout << "Left mouse button pressed ";
        } else if (event.mouseButton.button == sf::Mouse::Right) {
          std::cout << "Right mouse button pressed ";
        }

        sf::Vector2i position = { event.mouseButton.x, event.mouseButton.y };
        std::cout << "(" << position.x 
                  << "," << position.y 
                  << ")" << std::endl;
      }
    }

    window.clear(sf::Color::Black);
    window.display();
  }

  return 0;
}
