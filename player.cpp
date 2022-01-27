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

void player::update() {
	

	//NEW
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && y >= 0 + height * 5/9) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && x <= 800 - width * 5/9) {
			y -= sqrt(pow(speed, 2) / 2);
			x += sqrt(pow(speed, 2) / 2);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && x >= 0 + width * 5/9) {
			y -= sqrt(pow(speed, 2) / 2);
			x -= sqrt(pow(speed, 2) / 2);
		}
		else {
			y -= speed;
		}
	}

	//SEW
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && y <= 600 - height * 5/9) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && x <= 800 - width * 5/9) {
			y += sqrt(pow(speed, 2) / 2);
			x += sqrt(pow(speed, 2) / 2);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && x >= 0 + width * 5/9) {
			y += sqrt(pow(speed, 2) / 2);
			x -= sqrt(pow(speed, 2) / 2);
		}
		else {
			y += speed;
		}
	}

	//W
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && x >= 0 + width * 5/9) {
		x -= speed;
	}

	//E
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && x <= 800 - width * 5/9) {
		x += speed;
	}



}