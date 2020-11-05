#ifndef INVENTORYITEMS_H
#define INVENTORYITEMS_H
#pragma once

#include "../TextManager/TextManager.h"
#include "../Items/ItemManager.h"
#include "../Inventory/Inventory.h"

struct box;

class InventoryItems : public sf::Drawable, public sf::Transformable
{
private:
	std::vector<Texts*> texts;
	sf::VertexArray m_vertices;
	sf::Texture m_texture;
public:
	InventoryItems(int x);

	void loadItemsToSlots(std::vector<box> boxes, ItemManager& itemman, int startOfInventory);

	void drawText(sf::RenderWindow& win) {
		for (Texts* n : texts) {
			n->draw(win);
		}
	}

	void cleanUpTexts();

	~InventoryItems();
private:

	void initVectors();

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		states.transform *= getTransform();

		states.texture = &m_texture;

		target.draw(m_vertices, states);
	}

	void loadResources(const std::vector<box>& boxes, ItemManager& itemman,
		int& counterFornoTexts, int& lastBoxData, int& lastInvBox, sf::Vector2f itemTexOffset);
	void loadPickaxes(const std::vector<box>& boxes, ItemManager& itemman,
		int& lastBoxData, int& lastInvBox, sf::Vector2f itemTexOffset);
	void loadArmour(const std::vector<box>& boxes, ItemManager& itemman,
		int& lastBoxData, int& lastInvBox, sf::Vector2f itemTexOffset);
};
#endif