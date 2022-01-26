#include "player.h"
#include <iostream>


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