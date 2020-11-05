#ifndef MOUSE
#define MOUSE
#pragma once

#include "../Map/Objects.h"
#include "../Entities/Player.h"
#include "../Global/Global.h"
#include "../Items/ItemManager.h"

class Inventory;

class MouseClass
{
public:
	bool clicked;
	sf::Vector2i pos;
	sf::Vector2f JI;

	MouseClass();

	void calcJi(sf::RenderWindow& win, ObjectManager* objMan, Player& player);

	bool click() {
		if (clicked == true) {
			clicked = false;
			return true;
		}
		else {
			return false;
		}
	};

	~MouseClass();
};

#endif