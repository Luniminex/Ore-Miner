#ifndef DATASTRUCT_H
#define DATASTRUCT_H
#pragma once
struct box {
	std::vector<sf::Vector2f> pos;
};

struct valuesForDrawing {
	sf::Vector2f playerPos;
	box defaultPosition;
	box texCoords;
	sf::Vector2f horzOffset;
	sf::Vector2f vertOffset;
	int horCount = 0;
	int vertCount = 0;
};
#endif