#include "scenes/test1.hpp"

Test1::Test1(Game& game) : Scene(game) {}
Test1::~Test1() {}

void Test1::onInit() {
	Scene::onInit();
	std::cout << "onInit: Test1" << std::endl;
}

void Test1::onResume() {
	Scene::onResume();
	std::cout << "onResume: Test1" << std::endl;
}

void Test1::onPause()  {
	Scene::onPause();
	std::cout << "onPause: Test1" << std::endl;
}

void Test1::onEnd()    {
	Scene::onEnd();
	std::cout << "onEnd: Test1" << std::endl;
}

void Test1::event(const sf::Event& event) {
	if (event.type == sf::Event::KeyPressed) {
    if (event.key.code == sf::Keyboard::Q) {
        end();
    }
  }
}