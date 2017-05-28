#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

/**
  Ejemplo 1 - Recursos del sistema
  Crea una ventana SFML con unas dimensiones y titulo determinado
  Carga una textura, la aplica sobre un sprite y la muestra
  Carga una pista de audio y la reproduce
*/
int main() {
  const int screenWidth  = 480;
  const int screenHeight = 480;
  const std::string screenTitle = "Cave Story time";

  const char TEXTURE_FILE[] = "res/img/quote-1.png";
  const char MUSIC_FILE[]   = "res/audio/cave-story.ogg";

  sf::RenderWindow window;
  window.create(sf::VideoMode(screenWidth, screenHeight), screenTitle);

  sf::Texture texture;
  if (!texture.loadFromFile(TEXTURE_FILE)) {
    return 1;
  }

  sf::Music music;
  if (!music.openFromFile(MUSIC_FILE)) {
    return 1;
  }
  music.play();

  sf::Sprite sprite(texture);
  sprite.setPosition(screenWidth/2 + 20.0f, screenHeight/2);
  sprite.setScale(-4.0f, 4.0f);

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

          default:
            break;
        }
      }
    }

    window.clear(sf::Color::Magenta);
    window.draw(sprite);
    window.display();
  }

  return 0;
}
