#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>


class player{
private:	
	sf::Sprite sprite;
	sf::Texture texture;

	float x_scale = 1;
	float y_scale = 1;

	float speed = 5;

public:
	player(std::string imgDirectory);

	//Sprite Dimensions
	float height = 0;
	float width = 0;

	//Sprite Position
	float x = 0; 
	float y = 0;

	void setBounds(float width, float height) {

	}

	void draw(sf::RenderWindow& window, float posX, float posY);

	void movement();

	void collision(float windowX, float windowY);

	void update(float windowX, float windowY);
};

