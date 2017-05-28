#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

#include <iostream>

/**
  Ejemplo 1 - Update
  Anade un proceso mas al bucle principal encargado de la gestion de la logica 
  del videojuego
  Muestra por linea de comandos el tiempo transcurrido desde el inicio de la 
  ejecucion a cada iteracion del bucle principal
*/
int main() {
  const int screenWidth  = 480;
  const int screenHeight = 480;
  const std::string screenTitle = "Hello World";

  sf::RenderWindow window;
  window.create(sf::VideoMode(screenWidth, screenHeight), screenTitle);

  sf::Event event;

  sf::Clock clock;
  sf::Time elapsedTime;

  while (window.isOpen()) {
    // Gestion de eventos
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
    
    // Logica de estado
    elapsedTime = clock.getElapsedTime();
    std::cout << elapsedTime.asMilliseconds() << std::endl;

    // Logica de dibujo
    window.clear(sf::Color::Black);
    window.display();
  }

  return 0;
}
