#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>


class player{
private:	
	sf::Sprite sprite;
	sf::Texture texture;

public:
	player(std::string imgDirectory);

	//Sprite Dimensions
	int height;
	int width;

	void draw(sf::RenderWindow& window, float posX, float posY);

	
};

