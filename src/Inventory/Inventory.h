#ifndef INVENTORY_H
#define INVENTORY_H
#pragma once

#include "../TextManager/TextManager.h"
#include "../Inventory/InventoryItems.h"
#include "../Inventory/InventoryControl.h"
#include "DataStructs/data.h"

class InventoryItems;
class InventoryControl;

class Inventory : public sf::Drawable, public sf::Transformable
{
private:
	InventoryControl* invControl;
	InventoryItems* invItems;
	std::vector<box> m_boxes;
	sf::VertexArray m_vertices;
	sf::Texture m_texture;

	std::string path = "content/Inventory/inventorysheet.png";

	valuesForDrawing settingsBox; //data
	valuesForDrawing inventoryBox; //data
	valuesForDrawing backgroundStorageBox; //data
	valuesForDrawing backgroundDescBox; //data
	valuesForDrawing storageBoxes; //data
	valuesForDrawing equipsBoxes; //data
	valuesForDrawing armourBoxes; //data

public:
	bool open = false;
private:

	void initVectors();

	int initInv(sf::Vector2f pos);

	int setSettingsBox(std::vector<sf::Vector2f>& positions, int startingIndex, sf::Vector2f pos);

	int setInventoryBox(std::vector<sf::Vector2f>& positions, int startingIndex, sf::Vector2f pos);

	int setBackgroundForBoxes(std::vector<sf::Vector2f>& positions, int startingIndex, sf::Vector2f pos);

	int setBackgroundForDescription(std::vector<sf::Vector2f>& positions, int startingIndex, sf::Vector2f pos);

	int setEquips(std::vector<sf::Vector2f>& positions, int startingIndex, sf::Vector2f pos);

	int setArmours(std::vector<sf::Vector2f>& positions, int startingIndex, sf::Vector2f pos);

	int setBoxes(std::vector<sf::Vector2f>& positions, int startingIndex, sf::Vector2f pos);

	void setVertices(std::vector<sf::Vector2f>& positions, sf::Vertex* quad, int index);

	void setStartingValues();

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		states.transform *= getTransform();

		states.texture = &m_texture;

		target.draw(m_vertices, states);

	}

public:

	Inventory(InventoryItems* IItems, InventoryControl* IControl);

	void openInventory(sf::Vector2f pos, ItemManager& itemman);

	valuesForDrawing& getSettingsBox() { return settingsBox; };
	valuesForDrawing& getInventoryBox() { return inventoryBox; };
	valuesForDrawing& getBackgroundStorageBox() { return backgroundStorageBox; };
	valuesForDrawing& getBackgroundDescBox() { return backgroundDescBox; };
	valuesForDrawing& getStorageBoxes() { return storageBoxes; };
	valuesForDrawing& getEquipBoxes() { return equipsBoxes; };
	valuesForDrawing& getArmourBoxes() { return armourBoxes; };

	~Inventory();

	InventoryItems& getRefToInvItems() { return *invItems; };
	InventoryControl& getRefToInvControl() { return *invControl; };
};


#endif
