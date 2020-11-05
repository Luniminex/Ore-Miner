#pragma once
#include "../Entities/Player.h"
#include "../Entities/Manager.h"
#include "../Subsystems/Collider.h"
#include "../Subsystems/MouseClass.h"
#include "../TextManager/TextManager.h"
#include "../map/Objects.h"
#include "../map/Tilemap.h"
#include "../Inventory/InventoryControl.h"
#include "../Inventory/InventoryItems.h"
#include "../Inventory/Inventory.h"
#include "../Global/Global.h"

class Game
{
private:
	sf::RenderWindow win;
	sf::View view;
	MouseClass m1;
	ItemManager itemmanager;
	Inventory inv;

public:
	Game(sf::VideoMode videoMode, std::string title,sf::Vector2f viewSize);

	void gameLoop();

	~Game();

};

