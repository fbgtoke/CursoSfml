#include "scene.hpp"

Scene::Scene(Game& game) : game(game), currentState(UNINITIALIZED) {}
Scene::~Scene() {}

void Scene::onInit()   {}
void Scene::onResume() {}
void Scene::onPause()  {}
void Scene::onEnd()    {}

void Scene::update(const sf::Time& deltatime) {}
void Scene::draw(sf::RenderWindow& window)    {}
void Scene::event(const sf::Event& event)     {}

void Scene::init() {
	currentState = INITIALIZED;
	onInit();
}

void Scene::resume() {
	currentState = RUNNING;
	onResume();
}

void Scene::pause() {
	currentState = PAUSED;
	onPause();
}

void Scene::end() {
	currentState = ENDED;
	onEnd();
}

void Scene::restart() {
	end();
	init();
}

Scene::SceneState Scene::getCurrentState() const { return currentState; }

Scene* Scene::create(Game& game, Scene::SceneType sceneType) {
	Scene* scene;

	switch (sceneType) {
		default:
			scene = nullptr;
			break;
	};

	return scene;
}