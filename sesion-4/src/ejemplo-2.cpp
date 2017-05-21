#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

#include <iostream>

/**
  Ejemplo 2 - Boton sencillo
  Crea una ventana SFML con unas dimensiones y titulo determinado
  Muestra un rectangulo en pantalla
  Si el usuario hace click izquierdo sobre el rectangulo, escribe un mensaje por 
  linea de comandos
*/
int main(int arg, char* argv[]) {
  const int screenWidth    = 480;
  const int screenHeight   = 480;
  const char screenTitle[] = "Hello World";

  sf::RenderWindow window;
  window.create(sf::VideoMode(screenWidth, screenHeight), screenTitle);

  sf::RectangleShape button({ 100.0f, 50.0f });
  button.setPosition(100, 100);
  button.setFillColor(sf::Color::Green);

  sf::Event event;

  while (window.isOpen()) {
    window.clear(sf::Color::Black);
    window.draw(button);
    window.display();

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
          const int mouseX = event.mouseButton.x;
          const int mouseY = event.mouseButton.y;

          sf::FloatRect rect = button.getGlobalBounds();
          if (rect.contains(mouseX, mouseY)) {
            std::cout << "Clicked!" << std::endl;
          }
        }
      }
    }
  }

  return 0;
}
