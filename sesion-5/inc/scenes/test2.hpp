#ifndef TEST2_HPP
#define TEST2_HPP

#include "scene.hpp"
#include "ejemplo-2-game.hpp"
#include <iostream>

class Test2 : public Scene {
public:
	Test2(Game& game);
	~Test2() final;

	void onInit() final;
	void onResume() final;
	void onPause() final;
	void onEnd() final;

	void event(const sf::Event& event) final;
};

#endif