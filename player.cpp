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
	
	height = texture.getSize().y * y_scale;
	width = texture.getSize().x * x_scale;

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

void player::update(float x, float y) {
	
	movement();
	collision(x, y);

	
}