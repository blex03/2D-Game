#include "player.h"
#include <iostream>
#include <cmath>

player::player(std::string imgDirectory) {
	if (!texture.loadFromFile(imgDirectory)) {
		std::cout << "Could not find texture" << std::endl;
	}
	sprite.setTexture(texture);
	sprite.setScale(sf::Vector2f(x_scale, y_scale));
}

void player::draw(sf::RenderWindow &window, float posX, float posY) {
	height = sprite.getTextureRect().height * y_scale;
	width = sprite.getTextureRect().width * x_scale;

	sprite.setPosition(sf::Vector2f(posX - width/2, posY - height/2));
	window.draw(sprite);
}

void player::movement()
{
	//NEW
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			y -= float(sqrt(pow(speed, 2) / 2));
			x += float(sqrt(pow(speed, 2) / 2));
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			y -= float(sqrt(pow(speed, 2) / 2));
			x -= float(sqrt(pow(speed, 2) / 2));
		}
		else {
			y -= speed;
		}
	}

	//SEW
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			y += float(sqrt(pow(speed, 2) / 2));
			x += float(sqrt(pow(speed, 2) / 2));
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			y += float(sqrt(pow(speed, 2) / 2));
			x -= float(sqrt(pow(speed, 2) / 2));
		}
		else {
			y += speed;
		}
	}

	//W
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		x -= speed;
	}

	//E
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		x += speed;
		
	}
}

void player::collision(float windowX, float windowY)
{
	//window
	if (x <= 0 + width / 2) {
		x = 0 + width / 2;
	}

	if (x >= windowX - width / 2) {
		x = windowX - width / 2;
	}

	if (y <= height / 2) {
		y = height / 2;
	}

	if (y >= windowY - height / 2) {
		y = windowY - height / 2;
	}
}

void player::mousePosition(int mouseX, int mouseY)
{
	//convert degrees to radians
	float rad = (atan(1) * 4) / 180;

	float relativeX = mouseX - x;
	float relativeY = y - mouseY;
	float ratio;

	bool quad1 = false;
	bool quad2 = false;
	bool quad3 = false;
	bool quad4 = false;

	if (relativeX > 0 && relativeY > 0) {
		quad1 = true;
		std::cout << "QUAD[1]";
	}
	if (relativeX < 0 && relativeY > 0) {
		quad2 = true;
		std::cout << "QUAD[2]";
	}
	if (relativeX < 0 && relativeY < 0) {
		quad3 = true;
		std::cout << "QUAD[3]";
	}
	if (relativeX > 0 && relativeY < 0) {
		quad4 = true;
		std::cout << "QUAD[4]";
	}

	if (relativeX != 0) {
		ratio = relativeY / relativeX;
	}
	else {
		ratio = 0;
	}

	std::cout << relativeX << ", " << relativeY << ", " << ratio << std::endl;
	
	if (ratio != 0) {
		
		//S
		if (ratio <= tan(292.5 * rad) && quad4 || ratio >= tan(247.5 * rad) && quad3) {
			sprite.setTextureRect(sf::IntRect(0, 0, 50, 80));
		}

		//SW
		if ((ratio < tan(247.5 * rad) && ratio > tan(202.5 * rad)) && quad3) {
			sprite.setTextureRect(sf::IntRect(50, 0, 50, 80));
		}

		//W
		if (ratio <= tan(202.5 * rad) && quad3 || ratio >= tan(157.5 * rad) && quad2) {
			sprite.setTextureRect(sf::IntRect(100, 0, 50, 80));
		}

		//NW
		if ((ratio < tan(157.5 * rad) && ratio > tan(112.5 * rad)) && quad2) {
			sprite.setTextureRect(sf::IntRect(150, 0, 50, 80));
		}
		//N
		if (ratio <= tan(112.5 * rad) && quad2|| ratio >= tan(67.5 * rad) && quad1) {
			sprite.setTextureRect(sf::IntRect(200, 0, 50, 80));
		}

		//NE
		if ((ratio < tan(67.5 * rad) && ratio > tan(22.5 * rad)) && quad1) {
			sprite.setTextureRect(sf::IntRect(250, 0, 50, 80));
		}

		//E
		if (ratio <= tan(22.5 * rad) && quad1 || ratio >= tan(337.5 * rad) && quad4) {
			sprite.setTextureRect(sf::IntRect(300, 0, 50, 80));
		}

		//SE
		if ((ratio < tan(337.5 * rad) && ratio > tan(292.5 * rad)) && quad4) {
			sprite.setTextureRect(sf::IntRect(350, 0, 50, 80));
		}
	}
}

void player::update(float x, float y, int mouseX, int mouseY) {
	movement();
	collision(x, y);
	mousePosition(mouseX, mouseY);
}