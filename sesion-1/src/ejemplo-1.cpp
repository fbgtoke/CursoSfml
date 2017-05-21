#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

/**
  Ejemplo 1 - Hello World
  Crea una ventana SFML con unas dimensiones y titulo determinado
*/
int main(int arg, char* argv[]) {
  const int screenWidth    = 480;
  const int screenHeight   = 480;
  const char screenTitle[] = "Hello World";

  sf::RenderWindow window;
  window.create(sf::VideoMode(screenWidth, screenHeight), screenTitle);

  while (window.isOpen()) {
    window.clear(sf::Color::Black);
    window.display();
  }

  return 0;
}
