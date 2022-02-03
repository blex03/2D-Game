#pragma once
#include <iostream>
#include "character.h"

class game{
private:
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event event;

	float height = 600;
	float width = 800;

	//player
	character player = character("assets/NinjaSheet.png");
	attack basic = attack("assets/Attack.png");
	
public:
	game();

	bool running();

	void pollEvent();
	void update();
	void render();
};

