#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>

class object{
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

public:
	object(std::string imgDirectory);

	measure pos = { 0, 0 };

	void render(sf::RenderWindow& window, float posX, float posY);
};

class character : public object {
private:
	using object::object;
	void direction(int mouseX, int mouseY);
	void movement();
	void collision(float windowX, float windowY);

	measure scale = { 5, 5 };

public:
	void update(float windowX, float windowY, int mouseX, int mouseY);
};

class attack : public object {
private:
	using object::object;
	void direction(float playerX, float playerY, int mouseX, int mouseY);

	float radius = 75;
	float rotation = 0;

	

public:
	//Is attack activated?
	bool click();
	void update(float playerX, float playerY, int mouseX, int mouseY);

};



