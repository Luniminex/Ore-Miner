#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class Collider
{
private:
	sf::RectangleShape rec;
public:
	Collider();

	sf::RectangleShape& getRec() { return rec; };

	void createCollider(sf::Vector2f pos, sf::Vector2f size);

	void setCollider(sf::Vector2f pos, sf::Vector2f size, sf::Vector2f scale);

	bool checkForCollider(sf::RectangleShape other);

	//collision


	bool checkCollision(sf::RectangleShape& other, float push);

	~Collider();
};

