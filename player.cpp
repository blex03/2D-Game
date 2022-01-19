#include "player.h"


player::player(std::string imgDirectory) {
	if (!texture.loadFromFile(imgDirectory)) {
		std::cout << "Could not find texture" << std::endl;
	}
	playerSprite.setTexture(texture);
}

void player::drawPlayer(sf::RenderWindow &window) {
	playerSprite.setPosition(400 - 16, 300 - 16);
	window.draw(playerSprite);

}