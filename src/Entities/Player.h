#ifndef PLAYER_H
#define PLAYER_H
#pragma once

#include "Entity.h"
#include "../Subsystems/Animation.h"
#include "../Items/Items.h"
#include "../Global/Global.h"
#include "../Items/ItemManager.h"

class Inventory;

class Player : public Entity
{
private:
	sf::Texture tex;
	std::string name;
	Animation anim;
	ItemManager* m_itemman;


	float speed = 50.f;

public:
	Player(std::string name, std::string path, sf::Vector2f pos,
		sf::Vector2f size, ItemManager* itemman);

	void update(float deltaTime);

	void draw();

	~Player();

	sf::Vector2f getPos() { return getBody().getPosition(); };

	ItemManager& getRefToItemman() { return *m_itemman; };
public:
	sf::Vector2i JI;
};
#endif