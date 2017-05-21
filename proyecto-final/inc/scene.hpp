#ifndef SCENE_HPP
#define SCENE_HPP

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

class Game;

class Scene {
public:
	Scene(Game& game);
	virtual ~Scene();

	virtual void onInit();
	virtual void onResume();
	virtual void onPause();
	virtual void onEnd();

	virtual void update(const sf::Time& deltatime);
	virtual void draw(sf::RenderWindow& window);
	virtual void event(const sf::Event& event);

	void init();
	void pause();
	void resume();
	void end();

	void restart();

	enum SceneState {
		UNINITIALIZED,
		INITIALIZED,
		RUNNING,
		PAUSED,
		ENDED
	};
	Scene::SceneState getCurrentState() const;

	enum SceneType {
		NO_SCENE
	};
	static Scene* create(Game& game, Scene::SceneType sceneType);

protected:
	Game& game;

private:
	SceneState currentState;
};

#endif