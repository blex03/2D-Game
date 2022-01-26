#include "game.h"

//constructor / destructor
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
	pollEvent();

	//Player
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		p.y -= 5;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		p.x -= 5;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		p.y += 5;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		p.x += 5;
	}
}

void game::render()
{
	window->clear(sf::Color(25, 25, 25));
	
	p.draw(*window, p.x, p.y);
	
	window->display();
}
