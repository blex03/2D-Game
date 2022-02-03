#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>

class character{
protected:	
	sf::Sprite sprite;
	sf::Texture texture;

	struct measure {
		float x;
		float y;
	};

	measure size = { 0, 0 };
	measure scale = { 1, 1 };

	float speed = 5;

	void movement();
	void collision(float windowX, float windowY);
	
public:
	measure pos = { 0, 0 };

	character(std::string imgDirectory);

	void render(sf::RenderWindow& window, float posX, float posY);

	void direction(int mouseX, int mouseY);
	void update(float windowX, float windowY);
};

class attack : public character {
	using character::character;
};



