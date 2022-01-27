#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "player.h"

class game{
private:

	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event event;

	float height = 600;
	float width = 800;

	//player
	player p = player("assets/white_square.png");
	

public:

	game();

	bool running();

	void pollEvent();
	void update();
	void render();
};

