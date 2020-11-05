#include "InventoryItems.h"


InventoryItems::InventoryItems(int x) {
	x--;
	initVectors();
	m_texture.loadFromFile("oneitemsheet.png");
}

void InventoryItems::initVectors() {
	m_vertices.setPrimitiveType(sf::Quads);
	m_vertices.resize(1000);
}

void InventoryItems::cleanUpTexts() {
	for (Texts* n : texts) {
		delete n;
	}
	texts.resize(0);
}

void InventoryItems::loadItemsToSlots(std::vector<box> boxes, ItemManager& itemman, int startOfInventory) {
	initVectors();

	int lastBoxData = startOfInventory; //start of inventory boxes
	int LastInventoryBox = 0; //variable for tracking where the last load of type item ended;
	int counterFornoTexts = 0; //variable for tracking no texts

	sf::Vector2f itemTexOffset = { 0,32 };

	loadResources(boxes, itemman, counterFornoTexts, lastBoxData, LastInventoryBox, itemTexOffset);
	loadPickaxes(boxes, itemman, lastBoxData, LastInventoryBox, itemTexOffset);
	loadArmour(boxes, itemman, lastBoxData, LastInventoryBox, itemTexOffset);
}

void InventoryItems::loadResources(const std::vector<box>& boxes, ItemManager& itemman,
	int& counterFornoTexts, int& lastBoxData, int& lastInvBox, sf::Vector2f itemTexOffset) {

	for (int i = lastInvBox; i < itemman.getNoResources(); i++)
	{
		if (itemman.resources.at(i)->getAmount() > 0) {

			sf::Vertex* quad = &m_vertices[i * 4];

			texts.push_back(new Texts);
			texts.at(counterFornoTexts)->createTextOnMap(boxes[lastBoxData].pos.at(3) - sf::Vector2f(6.f, 6.f), 100,
				sf::Vector2f(0.035f, 0.035f), std::to_string(itemman.resources.at(i)->getAmount()));

			counterFornoTexts++;

			quad[0].position = boxes[lastBoxData].pos.at(0) + sf::Vector2f(3.f, -3.f);
			quad[1].position = boxes[lastBoxData].pos.at(1) + sf::Vector2f(3.f, 3.f);;
			quad[2].position = boxes[lastBoxData].pos.at(2) + sf::Vector2f(-3.f, 3.f);;
			quad[3].position = boxes[lastBoxData].pos.at(3) + sf::Vector2f(-3.f, -3.f);;

			quad[0].texCoords = sf::Vector2f(0.f, 32) + itemTexOffset * (float)i;
			quad[1].texCoords = sf::Vector2f(0, 0) + itemTexOffset * (float)i;
			quad[2].texCoords = sf::Vector2f(32, 0) + itemTexOffset * (float)i;
			quad[3].texCoords = sf::Vector2f(32, 32) + itemTexOffset * (float)i;

			lastBoxData++;
			lastInvBox = i;
		}
	}
	lastInvBox++;
}
void InventoryItems::loadPickaxes(const std::vector<box>& boxes, ItemManager& itemman,
	int& lastBoxData, int& lastInvBox, sf::Vector2f itemTexOffset) {

	int itemIndex = 0;
	int size = lastInvBox; // must be different cuz the other one gets incremented

	for (int i = lastInvBox; i < (size + itemman.getNoPickaxes()); i++) // size + last
	{
		itemIndex = i - size; // from 0 to size of pickaxes
		if (itemman.pickaxes.at(itemIndex)->isOWned() && !itemman.pickaxes.at(itemIndex)->isEquiped()) {

			sf::Vertex* quad = &m_vertices[i * 4];

			quad[0].position = boxes[lastBoxData].pos.at(0) + sf::Vector2f(3.f, -3.f);
			quad[1].position = boxes[lastBoxData].pos.at(1) + sf::Vector2f(3.f, 3.f);;
			quad[2].position = boxes[lastBoxData].pos.at(2) + sf::Vector2f(-3.f, 3.f);;
			quad[3].position = boxes[lastBoxData].pos.at(3) + sf::Vector2f(-3.f, -3.f);;

			quad[0].texCoords = sf::Vector2f(32.f, 32) + itemTexOffset * (float)itemIndex;
			quad[1].texCoords = sf::Vector2f(32, 0) + itemTexOffset * (float)itemIndex;
			quad[2].texCoords = sf::Vector2f(64, 0) + itemTexOffset * (float)itemIndex;
			quad[3].texCoords = sf::Vector2f(64, 32) + itemTexOffset * (float)itemIndex;
			lastBoxData++;
			lastInvBox = i;
		}
		lastInvBox++;
	}
}
void InventoryItems::loadArmour(const std::vector<box>& boxes, ItemManager& itemman,
	int& lastBoxData, int& lastInvBox, sf::Vector2f itemTexOffset) {
	int itemIndex = 0;
	int size = lastInvBox;

	for (int i = lastInvBox; i < (size + itemman.getNoArmours()); i++)
	{
		itemIndex = i - size;
		if (itemman.armours.at(itemIndex)->isOWned() && !itemman.armours.at(itemIndex)->isEquiped()) {

			sf::Vertex* quad = &m_vertices[i * 4];


			quad[0].position = boxes[lastBoxData].pos.at(0) + sf::Vector2f(3.f, -3.f);
			quad[1].position = boxes[lastBoxData].pos.at(1) + sf::Vector2f(3.f, 3.f);;
			quad[2].position = boxes[lastBoxData].pos.at(2) + sf::Vector2f(-3.f, 3.f);;
			quad[3].position = boxes[lastBoxData].pos.at(3) + sf::Vector2f(-3.f, -3.f);;

			quad[0].texCoords = sf::Vector2f(64.f, 32) + itemTexOffset * (float)itemIndex;
			quad[1].texCoords = sf::Vector2f(64, 0) + itemTexOffset * (float)itemIndex;
			quad[2].texCoords = sf::Vector2f(96, 0) + itemTexOffset * (float)itemIndex;
			quad[3].texCoords = sf::Vector2f(96, 32) + itemTexOffset * (float)itemIndex;
			lastBoxData++;
			lastInvBox = i;
		}
		lastInvBox++;
	}

}

InventoryItems::~InventoryItems() {

}
