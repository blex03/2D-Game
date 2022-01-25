#include "player.h"
#include <iostream>


player::player(std::string imgDirectory) {
	if (!texture.loadFromFile(imgDirectory)) {
		std::cout << "Could not find texture" << std::endl;
	}
	sprite.setTexture(texture);

}

void player::draw(sf::RenderWindow &window, float posX, float posY) {
	
	height = texture.getSize().y;
	width = texture.getSize().x;

	sprite.setPosition(sf::Vector2f(posX, posY));
	window.draw(sprite);

	

	
	

}