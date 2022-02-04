#include "object.h"

//object
object::object(std::string imgDirectory) {
	texture.loadFromFile(imgDirectory);
	sprite.setTexture(texture);
	sprite.setScale(sf::Vector2f(scale.x, scale.y));
}

void object::render(sf::RenderWindow &window, float posX, float posY) {
	size.y = sprite.getLocalBounds().height * scale.y;
	size.x = sprite.getLocalBounds().width * scale.x;

	sprite.setPosition(sf::Vector2f(posX - size.x/2, posY - size.y/2));
	window.draw(sprite);
}

//character
void character::movement()
{
	//NEW
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			pos.y -= float(sqrt(pow(speed, 2) / 2));
			pos.x += float(sqrt(pow(speed, 2) / 2));
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			pos.y -= float(sqrt(pow(speed, 2) / 2));
			pos.x -= float(sqrt(pow(speed, 2) / 2));
		}
		else {
			pos.y -= speed;
		}
	}

	//SEW
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			pos.y += float(sqrt(pow(speed, 2) / 2));
			pos.x += float(sqrt(pow(speed, 2) / 2));
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			pos.y += float(sqrt(pow(speed, 2) / 2));
			pos.x -= float(sqrt(pow(speed, 2) / 2));
		}
		else {
			pos.y += speed;
		}
	}

	//W
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		pos.x -= speed;
	}

	//E
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		pos.x += speed;
		
	}
}

void character::collision(float windowX, float windowY)
{
	//window
	if (pos.x <= 0 + size.x / 2) {
		pos.x = 0 + size.x / 2;
	}

	if (pos.x >= windowX - size.x / 2) {
		pos.x = windowX - size.x / 2;
	}

	if (pos.y <= size.y / 2) {
		pos.y = size.y / 2;
	}

	if (pos.y >= windowY - size.y / 2) {
		pos.y = windowY - size.y / 2;
	}
}

void character::direction(int mouseX, int mouseY)
{
	//convert degrees to radians
	double rad = (atan(1) * 4) / 180;

	float relativeX = mouseX - pos.x;
	float relativeY = pos.y - mouseY;
	float ratio;

	bool quad1 = false;
	bool quad2 = false;
	bool quad3 = false;
	bool quad4 = false;

	//Mouse Quadrant with Character at origin
	if (relativeX > 0 && relativeY > 0) {
		quad1 = true;
	}
	if (relativeX < 0 && relativeY > 0) {
		quad2 = true;
	}
	if (relativeX < 0 && relativeY < 0) {
		quad3 = true;
	}
	if (relativeX > 0 && relativeY < 0) {
		quad4 = true;
	}

	if (relativeX != 0) {
		ratio = relativeY / relativeX;
	}
	else {
		ratio = 0;
	}
	
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

void character::update(float x, float y, int mouseX, int mouseY) {
	movement();
	collision(x, y);
	direction(mouseX, mouseY);
}

//attack
bool attack::click() {
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)){
		return true;
	}
	else {
		return false;
	}
}

void attack::direction(float playerX, float playerY, int mouseX, int mouseY) {
	sprite.setOrigin(sf::Vector2f(size.x / 2, size.y / 2));

	//Position
	float relativeX = mouseX - playerX;
	float relativeY = playerY - mouseY;
	float ratio;
	if (relativeX != 0) {
		ratio = relativeY / relativeX;
	}
	else {
		ratio = 0;
	}

	float circle_size = sqrt(pow(relativeX, 2) + pow(relativeY, 2));
	float circle_factor = circle_size / radius;

	pos.x = playerX + relativeX / circle_factor + 15;
	pos.y = playerY - (relativeY / circle_factor) + 25;

	//Angle
	float radians = atan(ratio);
	float degrees = radians * (180 / (atan(1) * 4));

	if (relativeX < 0) {
		rotation = -degrees;
	}
	else if (relativeX > 0) {
		rotation = -degrees - 180;
	}
	
	sprite.setRotation(rotation);
}

void attack::update(float playerX, float playerY, int mouseX, int mouseY) {
	direction(playerX, playerY, mouseX, mouseY);
}

