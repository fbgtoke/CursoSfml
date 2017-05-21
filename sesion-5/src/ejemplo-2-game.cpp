#include "ejemplo-2-game.hpp"

const int Game::screenWidth    = 480;
const int Game::screenHeight   = 480;
const char Game::screenTitle[] = "Hello World";

Game::Game()
  : activeScene(nullptr), backgroundScene(nullptr) {}

Game::~Game() {
  if (activeScene != nullptr)
    delete activeScene;

  if (backgroundScene != nullptr)
    delete backgroundScene;
}

void Game::run() {
  init();
  mainLoop();
}

void Game::setActiveScene(Scene* scene) {
  if (activeScene != nullptr)
    delete activeScene;

  activeScene = scene;
}

void Game::setBackgroundScene(Scene* scene) {
  if (backgroundScene != nullptr)
    delete backgroundScene;

  backgroundScene = scene;
}

void Game::init() {
  window.create(sf::VideoMode(screenWidth, screenHeight), screenTitle);
  window.setKeyRepeatEnabled(false);

  Scene* scene = Scene::create(*this, Scene::MAIN_MENU);
  setActiveScene(scene);

  clk.restart();
}

void Game::mainLoop() {
  while (window.isOpen()) {
    // Logica de estado
    update();

    // Logica de dibujo
    draw();

    // Gestion de eventos
    events();

    // Gestion de escenas
    scene();
  }

  std::cout << "Exit main loop" << std::endl;
}

void Game::update() {
  sf::Time deltatime;
  deltatime = clk.restart();

  if (activeScene != nullptr)
    activeScene->update(deltatime);
}

void Game::draw() {
  window.clear(sf::Color::Black);
  
  if (activeScene != nullptr)
    activeScene->draw(window);

  window.display();
}

void Game::events() {
  sf::Event event;

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

    if (activeScene != nullptr)
      activeScene->event(event);
  }
}

void Game::scene() {
  if (activeScene != nullptr) {
    switch (activeScene->getCurrentState()) {
      case Scene::UNINITIALIZED:
        activeScene->init();
        break;

      case Scene::INITIALIZED:
        activeScene->resume();
        break;

      case Scene::RUNNING:
        break;

      case Scene::PAUSED:
        pauseActiveScene();
        break;

      case Scene::ENDED:
        terminateActiveScene();
        break;
    }
  }
}

void Game::pauseActiveScene() {
  if (backgroundScene != nullptr) {
    Scene* aux = activeScene;
    activeScene = backgroundScene;
    backgroundScene = aux;
  } else {
    activeScene->resume();
  }
}

void Game::terminateActiveScene() {
  if (activeScene != nullptr) {
    delete activeScene;
    activeScene = nullptr;
  }

  if (backgroundScene != nullptr) {
    activeScene = backgroundScene;
    backgroundScene = nullptr;
  } else {
    window.close();
  }
}