#include "InventoryControl.h"
#include "../Inventory/Inventory.h"


InventoryControl::InventoryControl()
{
	initControl();
}

void InventoryControl::ControllingInv(Inventory& inv) {

	moveSelectBox(inv);
}

void InventoryControl::initControl() {//musis pouzit
	initVectors();
	m_texture.loadFromFile(m_path);

	sf::Vertex* quad = &m_vertices[0];

	quad[0].texCoords = { 0.f,32.f };
	quad[1].texCoords = { 0.f,0.f };
	quad[2].texCoords = { 32.f,0.f };
	quad[3].texCoords = { 32.f, 32.f };

	values.defaultPosition.pos.resize(4);
	values.horCount = 0;
	values.vertCount = 0;
	values.playerPos = { 0,0 };
	values.texCoords.pos.resize(4);
	values.horzOffset = { 0,0 };
	values.vertOffset = { 0,0 };

}


void InventoryControl::initVectors() {
	m_vertices.setPrimitiveType(sf::Quads);
	m_vertices.resize(200);
	m_controlBoxes.resize(50);
	for (int i = 0; i < 50; i++) {
		m_controlBoxes.at(i).pos.resize(4);
	}
}

bool InventoryControl::moveSelectBox(Inventory& inv) {
	sf::Vector2f input = scanForInput();
	if (input == sf::Vector2f(1.f, 1.f)) {
		m_selectedPartOfInvetory++;
		if (m_selectedPartOfInvetory > m_countOfPartsInInventory)
			m_selectedPartOfInvetory = 0;
		values = getValueByLocationInInv(&inv, m_selectedPartOfInvetory);
		return true;
	}

	if (input == sf::Vector2f(-1.f, -1.f)) {
		m_selectedPartOfInvetory--;
		if (m_selectedPartOfInvetory < 0)
			m_selectedPartOfInvetory = m_countOfPartsInInventory;
		values = getValueByLocationInInv(&inv, m_selectedPartOfInvetory);
		return true;
	}

	sf::Vertex* quad = &m_vertices[0];

	sf::Vector2f LDC;
	sf::Vector2f LUC;
	sf::Vector2f RUC;
	sf::Vector2f RDC;

	m_posOfSelectedBox += input;
	if (m_posOfSelectedBox.x >= values.horCount)
		m_posOfSelectedBox.x = 0;
	if (m_posOfSelectedBox.x < 0)
		m_posOfSelectedBox.x = (values.horCount-1);
	if (m_posOfSelectedBox.y >= values.vertCount)
		m_posOfSelectedBox.y = 0;
	if (m_posOfSelectedBox.y < 0)
		m_posOfSelectedBox.y = (values.vertCount - 1);

	LDC = values.playerPos + values.defaultPosition.pos.at(0) +
		sf::Vector2f((values.horzOffset * m_posOfSelectedBox.x) +
		(values.vertOffset * m_posOfSelectedBox.y));
	LUC = values.playerPos + values.defaultPosition.pos.at(1) +
		sf::Vector2f((values.horzOffset * m_posOfSelectedBox.x) +
		(values.vertOffset * m_posOfSelectedBox.y));
	RUC = values.playerPos + values.defaultPosition.pos.at(2) +
		sf::Vector2f((values.horzOffset * m_posOfSelectedBox.x) +
		(values.vertOffset * m_posOfSelectedBox.y));
	RDC = values.playerPos + values.defaultPosition.pos.at(3) +
		sf::Vector2f((values.horzOffset * m_posOfSelectedBox.x) +
		(values.vertOffset * m_posOfSelectedBox.y));

	m_controlBoxes.at(0).pos.at(0) = LDC;
	m_controlBoxes.at(0).pos.at(1) = LUC;
	m_controlBoxes.at(0).pos.at(2) = RUC;
	m_controlBoxes.at(0).pos.at(3) = RDC;

	setVertices(m_controlBoxes.at(0).pos, quad);
	return 0;
}

sf::Vector2f InventoryControl::scanForInput() {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
			return sf::Vector2f(0.f, 1.f);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
			return sf::Vector2f(1.f, 0.f);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
			return sf::Vector2f(0.f, -1.f);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
			return sf::Vector2f(-1.f, 0.f);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q))
			return sf::Vector2f(1.f, 1.f);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Tab))
			return sf::Vector2f(-1.f, -1.f);

	return sf::Vector2f(0,0);
}

void InventoryControl::setVertices(std::vector<sf::Vector2f>& positions, sf::Vertex* quad) {

	quad[0].position = positions.at(0);
	quad[1].position = positions.at(1);
	quad[2].position = positions.at(2);
	quad[3].position = positions.at(3);
}

InventoryControl::~InventoryControl()
{
}

 valuesForDrawing& InventoryControl::getValueByLocationInInv(Inventory* inv, int part) {
	switch (part) {
	case Estorage:
		return inv->getStorageBoxes();
			break;
	case Eequipments:
		return inv->getEquipBoxes();
			break;
	case Earmour:
		return inv->getArmourBoxes();
			break;
	case Esettings:
		return inv->getSettingsBox();
			break;
	case Einventory:
		return inv->getInventoryBox();
			break;
	default:
		return inv->getStorageBoxes();
	}

}

