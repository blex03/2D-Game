#include "game.h"

//Initialize in constructor 
void game::initVar()
{
	window = nullptr;
	
}

void game::initWindow()
{
	videoMode.height = 600;
	videoMode.width = 800;
	window = new sf::RenderWindow(sf::VideoMode(videoMode), "Window", sf::Style::Titlebar | sf::Style::Close);
}

//constructor / destructor
game::game()
{
	initVar();
	initWindow();
}

game::~game()
{
	delete window;
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
		if (event.type == sf::Event::Closed)
			window->close();
	}
}

void game::update()
{
	pollEvent();
}

void game::render()
{
	window->clear(sf::Color(25, 25, 25));
	
	p.draw(*window);

	window->display();
}
