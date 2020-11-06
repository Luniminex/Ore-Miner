#pragma once
#include "../Entities/Entity.h"
#include "../Subsystems/Collider.h"
class Tile : public Entity
{
private:
	sf::Vector2u currentImage;
	sf::Texture tex;
	sf::IntRect uvRect;
	sf::Vector2u imageCount;
	Collider coll;
	sf::Vector2u type;

public:
	Tile();
	Tile(sf::Vector2f pos, sf::Vector2f size, sf::Vector2u imageCount,
		sf::Vector2u type, sf::Vector2u IJ);
	void initTile(sf::Vector2f pos, sf::Vector2f size, sf::Vector2u imageCount,
		sf::Vector2u type, sf::Vector2u IJ);

	void createTile(sf::Vector2f pos, sf::Vector2f size,
		sf::Vector2u imageCount, sf::Vector2u type, sf::Vector2u IJ);

	Collider& getCollider() { return coll; };

	sf::Vector2u getType() { return type; };

	~Tile();
public:
	sf::Vector2u JI;
};

