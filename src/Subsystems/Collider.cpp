#include "Collider.h"



Collider::Collider()
{
}


void Collider::createCollider(sf::Vector2f pos, sf::Vector2f size){
	rec.setPosition(pos);
	rec.setSize(size);
}

bool Collider::checkForCollider(sf::RectangleShape other) {
	sf::Vector2f otherPos = other.getPosition();
	sf::Vector2f thisPos = rec.getPosition();

	sf::Vector2f otherSize = other.getSize();
	sf::Vector2f thisSize = rec.getSize();

	if (thisPos.x + thisSize.x >= otherPos.x &&
		otherPos.x + otherSize.x >= thisPos.x &&
		thisPos.y + thisSize.y >= otherPos.y &&
		otherPos.y + otherSize.y >= thisPos.y) {

		std::cout << "Hit" << std::endl;

		return true;
	}
	return false;
}

void Collider::setCollider(sf::Vector2f pos, sf::Vector2f size, sf::Vector2f scale) {
	rec.setPosition(pos);
	rec.setSize(sf::Vector2f(size.x * scale.x,size.y * scale.y));
	rec.setOrigin(size / 2.0f);
}


//Collision

bool Collider::checkCollision(sf::RectangleShape& other, float push) {
	sf::Vector2f otherPosition = other.getPosition();
	sf::Vector2f otherHalfSize;
	otherHalfSize.x = other.getSize().x / 2.0f;
	otherHalfSize.y = other.getSize().y / 2.0f;
	sf::Vector2f thisPosition = rec.getPosition();
	sf::Vector2f thisHalfSize;
	thisHalfSize.x = rec.getSize().x / 2.0f;
	thisHalfSize.y = rec.getSize().y / 2.0f;


	float deltaX = otherPosition.x - thisPosition.x;
	float deltaY = otherPosition.y - thisPosition.y;
	float intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
	float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);

	if (intersectX < 0.0f && intersectY < 0.0f) {
		push = std::min(std::max(push, 0.0f), 1.0f);

		if (intersectX > intersectY) {

			if (deltaX > 0.0f) {
				rec.move(intersectX * (1.0f - push), 0.0f);
				other.move(-intersectX * push, 0.0f);
			}
			else {
				rec.move(-intersectX * (1.0f - push), 0.0f);
				other.move(intersectX * push, 0.0f);
			}
		}
		else {
			if (deltaY > 0.0f) {
				rec.move(0.0f, intersectY * (1.0f - push));
				other.move(0.0f, -intersectY * push);
			}
			else {
				rec.move(0.0f, -intersectY * (1.0f - push));
				other.move(0.0f, intersectY * push);
			}
		}
		return true;
	}

	return false;
}

Collider::~Collider()
{
}
