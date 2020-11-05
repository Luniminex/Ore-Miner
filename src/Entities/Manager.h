#pragma once

#include "Entity.h"
class Manager
{

public:
	std::vector<Entity*> entities;
public:
	Manager();

	void update();

	void draw(sf::RenderWindow& win);

	~Manager();
};

