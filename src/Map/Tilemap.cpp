#include "Tilemap.h"

void Tilemap::setQuadsPositions(unsigned int i, unsigned int j, sf::Vector2u tileSize, sf::Vertex* quad) {
	quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
	quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
	quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
	quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);
}
void Tilemap::setQuadsTexture(int tu, int tv, sf::Vector2u tileSize, sf::Vertex* quad) {
	quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
	quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
	quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
	quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
}

bool Tilemap::load(const std::string& tileset, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height)
{
	if (!m_tileset.loadFromFile(tileset))
		return false;

	m_vertices.setPrimitiveType(sf::Quads);
	m_vertices.resize(width * height * 4);

	for (unsigned int i = 0; i < width; ++i)
		for (unsigned int j = 0; j < height; ++j)
		{
			int tileNumber = tiles[i + j * width];

			int tu = tileNumber % (m_tileset.getSize().x / tileSize.x);
			int tv = tileNumber / (m_tileset.getSize().x / tileSize.x);

			sf::Vertex* quad = &m_vertices[(i + j * width) * 4];

			setQuadsPositions(i, j, tileSize, quad);
			setQuadsTexture(tu, tv, tileSize, quad);
		}

	return true;
}

bool Tilemap::loadFromFile(const std::string& tileset, const std::string& _mapFile)
{
	if (!m_tileset.loadFromFile(tileset))
		return false;

	int width;
	int height;
	int tileNumber;
	sf::Vector2u tileSize;
	std::string temp;
	char tile;
	std::fstream mapFile;

	mapFile.open(_mapFile);

	std::getline(mapFile, temp);
	width = std::stoi(temp);
	std::getline(mapFile, temp);	//nacteni dat z mapy
	height = std::stoi(temp);
	std::getline(mapFile, temp);
	tileSize.x = std::stoi(temp);
	std::getline(mapFile, temp);
	tileSize.y = std::stoi(temp);

	m_vertices.setPrimitiveType(sf::Quads);
	m_vertices.resize(width * height * 4);

	for (int i = 0; i < width; ++i)
		for (int j = 0; j < height; ++j)
		{
			mapFile.get(tile);
			if(tile == ',') // na konci rakdu skipne ,
				mapFile.get(tile);
			tileNumber = std::atoi(&tile);

			int tu = tileNumber % (m_tileset.getSize().x / tileSize.x);
			int tv = tileNumber / (m_tileset.getSize().x / tileSize.x);

			sf::Vertex* quad = &m_vertices[(i + j * width) * 4];

			setQuadsPositions(i, j, tileSize, quad);
			setQuadsTexture(tu, tv, tileSize, quad);

			mapFile.ignore(); //skipuje carku v radku
		}
	return true;
}

void Tilemap::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	states.transform *= getTransform();
	states.texture = &m_tileset;
	target.draw(m_vertices, states);
}