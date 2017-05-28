#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

#include "animation.hpp"
#include "animatedsprite.hpp"

/**
  Ejemplo 2 - Animaciones
  Crea una ventana SFML con unas dimensiones y titulo determinado
  Carga una textura, la aplica sobre un AnimatedSprite
  Declara e inicializa una animación y la asocia al sprite
  Muestra el AnimatedSprite
*/
int main() {
  const int screenWidth  = 480;
  const int screenHeight = 480;
  const std::string screenTitle = "Cave Story time";

  const char TEXTURE_FILE[] = "res/img/quote-2.png";

  sf::RenderWindow window;
  window.create(sf::VideoMode(screenWidth, screenHeight), screenTitle);

  sf::Clock clk;

  sf::Texture texture;
  if (!texture.loadFromFile(TEXTURE_FILE)) {
    return 1;
  }

  Animation animation;
  animation.setFrameTime(sf::seconds(0.125f));
  animation.addFrame({0, 0, 16, 16});
  animation.addFrame({16, 0, 16, 16});

  AnimatedSprite sprite(texture, &animation);
  sprite.setPosition(screenWidth/2 + 20.0f, screenHeight/2);
  sprite.setScale(-4.0f, 4.0f);

  sf::Event event;
  sf::Time deltatime;

  while (window.isOpen()) {
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
    
    deltatime = clk.restart();
    sprite.update(deltatime);

    window.clear(sf::Color::Magenta);
    window.draw(sprite);
    window.display();
  }

  return 0;
}
