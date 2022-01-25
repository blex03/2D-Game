#include "game.h"



//constructor / destructor
game::game()
{
	window = nullptr;

	videoMode.height = int(height);
	videoMode.width = int(width);

	window = new sf::RenderWindow(sf::VideoMode(videoMode), "Window", sf::Style::Titlebar | sf::Style::Close);

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
	
	p.draw(*window, (width - p.width) / 2, (height - p.height) / 2);
	
	window->display();
}
