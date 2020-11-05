#pragma once

#include "../Entities/Entity.h"
#include "../Entities/Player.h"
#include "../Subsystems/Collider.h"
#include "../Items/Items.h"

class SharedTileObject {	//flyweight
public:
	sf::Vector2u imageCount = { 1,22 };
	sf::Vector2u type = {1,1};
	sf::Texture tex;
	sf::Vector2f size = { 32.0f,32.0f };
	sf::IntRect uvRect;
	std::string path = "testicek.png";
	sf::Vector2f scale = {1.f,1.f};
	unsigned int resourceDropID = 0;
	unsigned int amountDrop = 0;
public:

	SharedTileObject(sf::Vector2u imageCount, sf::Vector2u type, std::string path,
		sf::Vector2f scale, unsigned int resourceDropID, unsigned int amountDrop);

	SharedTileObject(sf::Vector2u type, sf::Vector2f scale, unsigned int resourceDropID, unsigned int amountDrop);


	~SharedTileObject();
};

class ConcreteTileObject {
public:
	SharedTileObject* shared;
	sf::RectangleShape Concretebody;
	Collider coll;
	int life;
private:
	void initConcreteObject(SharedTileObject* shared);
	sf::Vector2f getPosRelativeToGrid(sf::Vector2f pos);
public:
	ConcreteTileObject(SharedTileObject* shared, sf::Vector2f pos, int life);
	sf::Vector2f getScaleForCollisionCheck() { return shared->scale; };
	~ConcreteTileObject();
};

class ObjectManager {

public:
	std::vector<ConcreteTileObject*> objects;

	SharedTileObject* wideRock = new SharedTileObject(sf::Vector2u(0,0),sf::Vector2f(0.5f,0.5f),Eresources::stone,1);
	SharedTileObject* penis = new SharedTileObject(sf::Vector2u(0, 1),sf::Vector2f(0.4f, 0.4f), Eresources::stone,1);
	SharedTileObject* smallRock = new SharedTileObject(sf::Vector2u(0, 2),sf::Vector2f(0.5f, 0.5f), Eresources::stone,1);
	SharedTileObject* anotherWideRock = new SharedTileObject(sf::Vector2u(0, 3), sf::Vector2f(0.5f, 0.5f), Eresources::stone,1);
	SharedTileObject* wierdRock = new SharedTileObject(sf::Vector2u(0, 4), sf::Vector2f(0.35f, 0.35f), Eresources::stone,1);
	SharedTileObject* bigRock = new SharedTileObject(sf::Vector2u(0, 5), sf::Vector2f(0.8f, 0.8f), Eresources::stone,1);
	SharedTileObject* tree = new SharedTileObject(sf::Vector2u(0, 6), sf::Vector2f(2.f, 2.f), Eresources::log,2);
	SharedTileObject* bush = new SharedTileObject(sf::Vector2u(0, 7), sf::Vector2f(0.7f, 0.7f), Eresources::sticks,2);
	SharedTileObject* redFlower = new SharedTileObject(sf::Vector2u(0, 8), sf::Vector2f(0.3f, 0.3f), Eresources::redFlower,1);
	SharedTileObject* yellowFlower = new SharedTileObject(sf::Vector2u(0, 9), sf::Vector2f(0.3f, 0.3f), Eresources::yellowFlower,1);
	SharedTileObject* log = new SharedTileObject(sf::Vector2u(0, 10), sf::Vector2f(0.6f,0.6f), Eresources::log,1);
	SharedTileObject* goldOre = new SharedTileObject(sf::Vector2u(0, 11), sf::Vector2f(1.0f, 1.0f), Eresources::goldOre,1);
	SharedTileObject* ironOre = new SharedTileObject(sf::Vector2u(0, 12), sf::Vector2f(1.0f, 1.0f), Eresources::ironOre,1);
	SharedTileObject* ruby = new SharedTileObject(sf::Vector2u(0, 13), sf::Vector2f(1.0f, 1.0f), Eresources::ruby,1);
	SharedTileObject* emerald = new SharedTileObject(sf::Vector2u(0, 14), sf::Vector2f(1.0f, 1.0f), Eresources::emerald,1);
	SharedTileObject* sapphire = new SharedTileObject(sf::Vector2u(0, 15), sf::Vector2f(1.0f, 1.0f), Eresources::sapphire,1);
	SharedTileObject* copperOre = new SharedTileObject(sf::Vector2u(0, 16), sf::Vector2f(1.0f, 1.0f), Eresources::copperOre,1);
	SharedTileObject* stone = new SharedTileObject(sf::Vector2u(0, 17), sf::Vector2f(1.2f, 1.2f), Eresources::stone,2);
	SharedTileObject* brokenOre = new SharedTileObject(sf::Vector2u(0, 18), sf::Vector2f(1.0f, 1.0f), Eresources::defaultItem,0);
	SharedTileObject* brokenStone = new SharedTileObject(sf::Vector2u(0, 19), sf::Vector2f(1.2f, 1.2f), Eresources::defaultItem,0);
	SharedTileObject* smallRedFlower = new SharedTileObject(sf::Vector2u(0, 20), sf::Vector2f(0.4f, 0.4f), Eresources::redFlower,1);
	SharedTileObject* smallOrangeFlower = new SharedTileObject(sf::Vector2u(0, 21), sf::Vector2f(0.4f, 0.4f), Eresources::yellowFlower,1);


public:

	ObjectManager();

	void spawnObject(int type, sf::Vector2f pos);

	void drawObjects(sf::RenderWindow& win);

	~ObjectManager();
};

class ObjectGenerator
{
private:
	std::ifstream mapStream;
	unsigned int mapWidth = 100;
	unsigned int mapHeight = 100;
	int offset = 32;
										 // MUSIS ZMENIT PODLE VEL. MAPY
	unsigned int scannedTiles[200][200];
	sf::Vector2i range = { 30,25 };
	sf::Vector2i playerPos;
	sf::Vector2i playerLastPos;

	ObjectManager objMan;

	enum scan {
		notScanned, spawned, scanned
	};
private:
	sf::Vector2i getPlayerJI(sf::Vector2f pos);
	bool isPlayerNear(sf::Vector2f playerPos, sf::Vector2f objectPos);
public:
	ObjectGenerator();

	void generateObjects(Player& player);

	void checkColl(Player& player);

	void drawMap(sf::RenderWindow& win);

	ObjectManager& getObjectManager() { return objMan; };

	~ObjectGenerator();
};