#ifndef TEST1_HPP
#define TEST1_HPP

#include "scene.hpp"
#include "ejemplo-2-game.hpp"
#include <iostream>

class Test1 : public Scene {
public:
	Test1(Game& game);
	~Test1() final;

	void onInit() final;
	void onResume() final;
	void onPause() final;
	void onEnd() final;

	void event(const sf::Event& event) final;
};

#endif