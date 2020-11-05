#include "Objects.h"

void ConcreteTileObject::initConcreteObject(SharedTileObject* shared) {
	this->shared = shared;
	Concretebody.setSize(shared->size);
	Concretebody.setOrigin(shared->size / 2.0f);
	Concretebody.setTexture(&shared->tex);
	Concretebody.setTextureRect(shared->uvRect);
	Concretebody.setScale(shared->scale);
}

sf::Vector2f ConcreteTileObject::getPosRelativeToGrid(sf::Vector2f pos) {
	pos.x = pos.x - ((int)pos.x % 32);
	pos.y = pos.y - ((int)pos.y % 32);
	return pos;
}

ConcreteTileObject::ConcreteTileObject(SharedTileObject* shared, sf::Vector2f pos, int life) {
	
	initConcreteObject(shared);

	Concretebody.setPosition(getPosRelativeToGrid(pos));

	coll.setCollider(Concretebody.getPosition(), Concretebody.getSize(), shared->scale);

	Concretebody.setOutlineColor(sf::Color::Blue);
	Concretebody.setOutlineThickness(0.5f);

	this->life = life;
}

ConcreteTileObject::~ConcreteTileObject() {

}

SharedTileObject::SharedTileObject(sf::Vector2u imageCount, sf::Vector2u type, std::string path,
	sf::Vector2f scale, unsigned int resourceDropID, unsigned int amountDrop) {
	tex.loadFromFile(path);
	this->imageCount = imageCount;
	this->type = type;
	this->scale = scale;
	this->resourceDropID = resourceDropID;
	this->amountDrop = amountDrop;

	uvRect.width = tex.getSize().x / (float)imageCount.x;
	uvRect.height = tex.getSize().y / (float)imageCount.y;
	uvRect.left = uvRect.width * type.x;
	uvRect.top = uvRect.height * type.y;

}

SharedTileObject::SharedTileObject(sf::Vector2u type, sf::Vector2f scale, unsigned int resourceDropID, unsigned int amountDrop) {
	tex.loadFromFile(this->path);
	this->type = type;
	this->scale = scale;
	this->type = type;
	this->resourceDropID = resourceDropID;
	this->amountDrop = amountDrop;

	uvRect.width = tex.getSize().x / (float)this->imageCount.x;
	uvRect.height = tex.getSize().y / (float)this->imageCount.y;
	uvRect.left = uvRect.width * type.x;
	uvRect.top = uvRect.height * type.y;
}

SharedTileObject::~SharedTileObject() {

}

sf::Vector2i ObjectGenerator::getPlayerJI(sf::Vector2f pos) {
	pos.x = (pos.x - ((int)pos.x % 32)) / 32;
	pos.y = (pos.y - ((int)pos.y % 32)) / 32;
	return (sf::Vector2i)pos;
}


bool ObjectGenerator::isPlayerNear(sf::Vector2f playerPos, sf::Vector2f objectPos) {
	if (objectPos.x >= playerPos.x + 100.f)
		return false;
	if (objectPos.x <= playerPos.x - 100.f) //check checks
		return false;
	if (objectPos.y >= playerPos.y + 100.f)
		return false;
	if (objectPos.y <= playerPos.y - 100.f)
		return false;

	return true;
}

ObjectGenerator::ObjectGenerator() {

}

void ObjectGenerator::generateObjects(Player& player) {
	sf::Vector2i left;
	playerPos = getPlayerJI(player.getPos());

	left.x = playerPos.x - (range.x / 2);
	if (left.x < 0) left.x = 0;
	if (left.x > mapWidth - 1) left.x = mapWidth - 1;
	left.y = playerPos.y - (range.y / 2);
	if (left.y < 0) left.y = 0;
	if (left.y > mapHeight - 1) left.y = mapHeight - 1;
	sf::Vector2i border = { playerPos.x + (range.x / 2), playerPos.y + (range.y / 2) };

	if (playerLastPos != playerPos) {
		for (int i = left.y; i < border.y; i++) {
			for (int j = left.x; j < border.x; j++) {
				if (rand() % 280 < 10 && scannedTiles[j][i] == notScanned) {
					objMan.spawnObject(rand() % 22, sf::Vector2f(j * offset, i * offset));
					scannedTiles[j][i] = spawned;
				}
				else {
					scannedTiles[j][i] = scanned;
				}
			}
			
		}
	}
}

void ObjectGenerator::checkColl(Player& player) {
	for (ConcreteTileObject* n : objMan.objects) {
		if (isPlayerNear(player.getPos(), n->Concretebody.getPosition())) {
			n->coll.checkCollision(player.getBody(), 1.0f);
		}
	}
}

void ObjectGenerator::drawMap(sf::RenderWindow& win) {
	objMan.drawObjects(win);
}

ObjectGenerator::~ObjectGenerator()
{
}

ObjectManager::ObjectManager() {

}

void ObjectManager::spawnObject(int type, sf::Vector2f pos) {

	switch (type) {
	case 0: objects.push_back(new ConcreteTileObject(wideRock, pos, 1));
		break;
	case 1:objects.push_back(new ConcreteTileObject(penis, pos, 1));
		break;
	case 2:objects.push_back(new ConcreteTileObject(smallRock, pos, 1));
		break;
	case 3:objects.push_back(new ConcreteTileObject(anotherWideRock, pos, 1));
		break;
	case 4:objects.push_back(new ConcreteTileObject(wierdRock, pos, 1));
		break;
	case 5:objects.push_back(new ConcreteTileObject(bigRock, pos, 2));
		break;
	case 6:objects.push_back(new ConcreteTileObject(tree, pos, 10));
		break;
	case 7:objects.push_back(new ConcreteTileObject(bush, pos, 5));
		break;
	case 8:objects.push_back(new ConcreteTileObject(redFlower, pos, 1));
		break;
	case 9:objects.push_back(new ConcreteTileObject(yellowFlower, pos, 1));
		break;
	case 10:objects.push_back(new ConcreteTileObject(log, pos, 4));
		break;
	case 11:objects.push_back(new ConcreteTileObject(goldOre, pos, 6));
		break;
	case 12:objects.push_back(new ConcreteTileObject(ironOre, pos, 6));
		break;
	case 13:objects.push_back(new ConcreteTileObject(ruby, pos, 3));
		break;
	case 14:objects.push_back(new ConcreteTileObject(emerald, pos, 3));
		break;
	case 15:objects.push_back(new ConcreteTileObject(sapphire, pos, 3));
		break;
	case 16:objects.push_back(new ConcreteTileObject(copperOre, pos, 6));
		break;
	case 17:objects.push_back(new ConcreteTileObject(stone, pos, 15));
		break;
	case 18:objects.push_back(new ConcreteTileObject(brokenOre, pos, 100));
		break;
	case 19:objects.push_back(new ConcreteTileObject(brokenStone, pos, 100));
		break;
	case 20:objects.push_back(new ConcreteTileObject(smallRedFlower, pos, 1));
		break;
	case 21:objects.push_back(new ConcreteTileObject(smallOrangeFlower, pos, 1));
		break;
	}
}

void ObjectManager::drawObjects(sf::RenderWindow& win) {
	for (ConcreteTileObject* n : objects) {
		win.draw(n->Concretebody);
	}
}

ObjectManager::~ObjectManager() {
	objects.clear();
}
