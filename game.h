#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "player.h"

class game{
private:

	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event event;

	void initVar();
	void initWindow();

	//player
	player p = player("assets/white_square.png");

public:
	game();
	~game();

	bool running();

	void pollEvent();
	void update();
	void render();
};

