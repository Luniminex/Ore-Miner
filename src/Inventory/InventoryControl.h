#ifndef INVENTORYCONTROL_H
#define INVENTORCONTROL_H
#pragma once

#include "../TextManager/TextManager.h"
#include "../Inventory/InventoryControl.h"
#include "DataStructs/data.h"

class Inventory;

class InventoryControl : public sf::Drawable, public sf::Transformable
{
private:
		enum invParts {
			Estorage, Eequipments, Earmour, Esettings, Einventory
		};

	valuesForDrawing values;

	sf::VertexArray m_vertices;
	std::vector<box> m_controlBoxes;

	sf::Vector2f m_posOfSelectedBox = { 0,0 };

	sf::Texture m_texture;

	const std::string m_path = "content/Inventory/InventoryControl.png";

	int m_selectedPartOfInvetory = 0;

	int m_countOfPartsInInventory = 4;
public:

	void ControllingInv(Inventory& inv);

private:
	valuesForDrawing& getValueByLocationInInv(Inventory* inv, int part);

	void initControl();

	void initVectors();

	void setVertices(std::vector<sf::Vector2f>& positions, sf::Vertex* quad);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		states.transform *= getTransform();

		states.texture = &m_texture;

		target.draw(m_vertices, states);
	}

	bool moveSelectBox(Inventory& inv); //returns true if something updated else false

public:
	InventoryControl();

	sf::Vector2f scanForInput();

	~InventoryControl();
};
#endif