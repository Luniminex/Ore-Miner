#pragma once

class Tilemap : public sf::Drawable, public sf::Transformable
{

private:
	sf::VertexArray m_vertices;
	sf::Texture m_tileset;

private:
	void setQuadsPositions(unsigned int i, unsigned int j, sf::Vector2u tileSize, sf::Vertex* quad);
	void setQuadsTexture(int tu, int tv, sf::Vector2u tileSize, sf::Vertex* quad);

public:
	bool loadFromFile(const std::string& tileset, const std::string& _mapFile);

	bool load(const std::string& tileset, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height);

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};
