#include "Tile.h"


Tile::Tile(){}

Tile::Tile(sf::Vector2f pos, sf::Vector2f size, sf::Vector2u imageCount,
	sf::Vector2u type, sf::Vector2u JI)
{
	initTile(pos, size, imageCount, type, JI);
}

void Tile::createTile(sf::Vector2f pos, sf::Vector2f size,
	sf::Vector2u imageCount, sf::Vector2u type, sf::Vector2u JI) {
	initTile(pos, size, imageCount, type, JI);
}

void Tile::initTile(sf::Vector2f pos, sf::Vector2f size,
	sf::Vector2u imageCount, sf::Vector2u type, sf::Vector2u JI) {
	tex.loadFromFile("tilesTTTT (1).png");
	getBody().setSize(size);
	getBody().setPosition(pos);
	getBody().setTexture(&tex);
	this->imageCount = imageCount;
	this->currentImage = type;
	this->type = type;
	this->JI.x = JI.x;
	this->JI.y = JI.y;

	uvRect.width = tex.getSize().x / (float)imageCount.x;
	uvRect.height = tex.getSize().y / (float)imageCount.y;
	uvRect.left = uvRect.width * currentImage.x;
	uvRect.top = uvRect.height * currentImage.y;
	std::cout << "Width:" << uvRect.width << "Height:" << uvRect.height << "left:" << uvRect.left << "top:" << uvRect.top;
	coll.setCollider(getBody().getPosition(), getBody().getSize(), sf::Vector2f(1.f,1.f));
	getBody().setTextureRect(uvRect);
	getBody().setOutlineColor(sf::Color::Cyan);
	getBody().setOutlineThickness(2.0f);
	getBody().setOrigin(getBody().getSize() / 2.0f);
}

Tile::~Tile()
{
}
