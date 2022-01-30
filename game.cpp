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
	p.x = width / 2;
	p.y = height / 2;
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
	p.update(width, height, mouseX, mouseY);

	
}

void game::render()
{
	window->clear(sf::Color(60, 60, 60));
	
	p.draw(*window, p.x, p.y);
	
	window->display();
}
