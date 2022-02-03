#include "game.h"

//constructor
game::game()
{
	window = nullptr;

	videoMode.height = int(height);
	videoMode.width = int(width);

	window = new sf::RenderWindow(sf::VideoMode(videoMode), "Window", sf::Style::Titlebar | sf::Style::Close);

	window->setFramerateLimit(60);

	//player
	player.pos.x = width / 2;
	player.pos.y = height / 2;

	
}

//running
bool game::running()
{
	return window->isOpen();
}

//update & render
void game::pollEvent()
{
	while (window->pollEvent(event))
	{
		switch (event.type) 
		{
		case sf::Event::Closed:
			window->close();
			break;
		}
	}
}

void game::update()
{
	//mouse position
	int mouseX = sf::Mouse::getPosition(*window).x;
	int mouseY = sf::Mouse::getPosition(*window).y;

	//window
	pollEvent();

	//player
	player.update(width, height);
	player.direction(mouseX, mouseY);

	//attack
	basic.pos.x = player.pos.x - 50;
	basic.pos.y = player.pos.y;
	
}

void game::render()
{
	window->clear(sf::Color(60, 60, 60));
	
	player.render(*window, player.pos.x, player.pos.y);
	basic.render(*window, basic.pos.x, basic.pos.y);
	
	window->display();
}
