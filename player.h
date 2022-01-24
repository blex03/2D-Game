#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>


class player{
private:
	sf::Texture texture;
	sf::Sprite playerSprite;

public:
	
	player(std::string imgDirectory);

	void draw(sf::RenderWindow& window);
};

