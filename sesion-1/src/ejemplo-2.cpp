#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

/**
  Ejemplo 2 - CircleShape
  Crea una ventana SFML con unas dimensiones y titulo determinado
  Dibuja un circulo blanco en la ventana
*/
int main() {
  const int screenWidth = 480;
  const int screenHeight = 480;
  const std::string screenTitle = "Hello World";

  sf::RenderWindow window;
  window.create(sf::VideoMode(screenWidth, screenHeight), screenTitle);

  sf::CircleShape circle;
  circle.setRadius(10.f);
  circle.setPosition(235.0f, 235.0f);
  circle.setFillColor(sf::Color::White);

  while (window.isOpen()) {
    window.clear(sf::Color::Black);
    window.draw(circle);
    window.display();
  }

  return 0;
}
