#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>


class player{
private:	
	sf::Sprite sprite;
	sf::Texture texture;

	float x_scale = 1;
	float y_scale = 1;

public:
	player(std::string imgDirectory);

	//Sprite Dimensions
	int height;
	int width;

	//Sprite Position
	float x;
	float y;

	void draw(sf::RenderWindow& window, float posX, float posY);

	
};

