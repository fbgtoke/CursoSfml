#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

#include <iostream>

/**
  Ejemplo 4 - Keyboard Events
  Crea una ventana SFML con unas dimensiones y titulo determinado
  Dibuja un circulo blanco en la ventana
  La ventana responde al evento de cerrar (click sobre X)
  Responde a eventos de teclado
*/
int main() {
  const int screenWidth  = 480;
  const int screenHeight = 480;
  const std::string screenTitle = "Hello World";

  sf::RenderWindow window;
  window.create(sf::VideoMode(screenWidth, screenHeight), screenTitle);

  sf::CircleShape circle;
  circle.setRadius(10.f);
  circle.setPosition(235.0f, 235.0f);
  circle.setFillColor(sf::Color::White);

  sf::Event event;

  while (window.isOpen()) {
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();

      else if (event.type == sf::Event::KeyPressed) {
        switch (event.key.code) {
          case sf::Keyboard::Escape:
            window.close();
            break;

          case sf::Keyboard::Left:
            std::cout << "Left Pressed" << std::endl;
            break;

          case sf::Keyboard::Right:
            std::cout << "Right Pressed" << std::endl;
            break;

          case sf::Keyboard::Up:
            std::cout << "Up Pressed" << std::endl;
            break;

          case sf::Keyboard::Down:
            std::cout << "Down Pressed" << std::endl;
            break;

          default:
            break;
        }
      }
    }

    window.clear(sf::Color::Black);
    window.draw(circle);
    window.display();
  }

  return 0;
}
