#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

/**
  Ejemplo 3 - Closed Event
  Crea una ventana SFML con unas dimensiones y titulo determinado
  Dibuja un circulo blanco en la ventana
  La ventana responde al evento de cerrar (click sobre X)
*/
int main(int arg, char* argv[]) {
  const int screenWidth    = 480;
  const int screenHeight   = 480;
  const char screenTitle[] = "Hello World";

  sf::RenderWindow window;
  window.create(sf::VideoMode(screenWidth, screenHeight), screenTitle);

  sf::CircleShape circle;
  circle.setRadius(10.f);
  circle.setPosition(235.0f, 235.0f);
  circle.setFillColor(sf::Color::White);

  sf::Event event;

  while (window.isOpen()) {
    window.clear(sf::Color::Black);
    window.draw(circle);
    window.display();

    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();
    }
  }

  return 0;
}
