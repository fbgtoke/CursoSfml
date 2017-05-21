#include "scenes/test2.hpp"

Test2::Test2(Game& game) : Scene(game) {}
Test2::~Test2() {}

void Test2::onInit() {
	Scene::onInit();
	std::cout << "onInit: Test2" << std::endl;
}

void Test2::onResume() {
	Scene::onResume();
	std::cout << "onResume: Test2" << std::endl;
}

void Test2::onPause()  {
	Scene::onPause();
	std::cout << "onPause: Test2" << std::endl;
}

void Test2::onEnd()    {
	Scene::onEnd();
	std::cout << "onEnd: Test2" << std::endl;
}

void Test2::event(const sf::Event& event) {
	if (event.type == sf::Event::KeyPressed) {
    if (event.key.code == sf::Keyboard::Q) {
        end();
    }
  }
}