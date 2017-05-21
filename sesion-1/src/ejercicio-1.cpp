#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

/**
  Ejercicio 1 - Cambio de color
  Complete el codigo añadiendo las siguientes funcionalidades:
    1.- El circulo podrá tomar 4 colores distintos que cambiarán de manera 
    ciclica de acuerdo con una secuencia establecida.
    2.- Cuando el usuario pulse la tecla D, la secuencia avanzara
    3.- Cuando el usuario pulse la tecla A, la secuencia retrocedera
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
