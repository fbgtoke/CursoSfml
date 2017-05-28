#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

/**
  Ejercicio 2 - Movimiento
  Complete el codigo añadiendo las siguientes funcionalidades:
    1.- El circulo se movera en las 4 direcciones cardinales cuando el usuario 
    pulse la respectiva flecha directora sobre el teclado
    2.- El circulo se detendra cuando el usuario suelte cualquier tecla

  Implemente el control de movimiento a partir unicamente de la gestion de 
  eventos de teclado.
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
    }

    window.clear(sf::Color::Black);
    window.draw(circle);
    window.display();
  }

  return 0;
}
