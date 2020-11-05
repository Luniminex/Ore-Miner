#include "../Inventory/Inventory.h"
#include "../Entities/Player.h"
#include "../Items/ItemManager.h"

Inventory::Inventory(InventoryItems* IItems, InventoryControl* IControl)
{
	setStartingValues();
	initInv({ 0, 0 });
	std::cout << "Inintitititiit" << std::endl;
	invItems = IItems;
	invControl = IControl;
}

Inventory::~Inventory()
{
	delete invControl;
	delete invItems;
}

void Inventory::openInventory(sf::Vector2f pos, ItemManager& itemman)
{
	if (open == true)
	{
		open = false;
		invItems->cleanUpTexts();
	}
	else
	{
		int startOfInventoryBoxes = initInv(pos);
		invItems->loadItemsToSlots(m_boxes, itemman, startOfInventoryBoxes);
		open = true;
	}
}

void Inventory::setVertices(std::vector<sf::Vector2f>& positions, sf::Vertex* quad, int index)
{
	quad[0].position = positions.at(0);
	quad[1].position = positions.at(1);
	quad[2].position = positions.at(2);
	quad[3].position = positions.at(3);

	m_boxes.at(index).pos.at(0) = positions.at(0);
	m_boxes.at(index).pos.at(1) = positions.at(1);
	m_boxes.at(index).pos.at(2) = positions.at(2);
	m_boxes.at(index).pos.at(3) = positions.at(3);
}

void Inventory::initVectors()
{
	m_vertices.setPrimitiveType(sf::Quads);
	m_vertices.resize(1000);

	m_boxes.resize(600);
	for
		it(int i = 0; i < 600; i++)
		{
			m_boxes.at(i).pos.resize(4);
		}
}

int Inventory::initInv(sf::Vector2f pos)
{

	initVectors();

	std::vector<sf::Vector2f> positions;
	positions.resize(4);

	int lastIndex = 0;
	int startOfInvetoryBoxes = 0;

	m_texture.loadFromFile("inventorysheet.png");

	lastIndex = setInventoryBox(positions, lastIndex, pos);
	lastIndex = setSettingsBox(positions, lastIndex, pos);
	lastIndex = setBackgroundForBoxes(positions, lastIndex, pos);
	lastIndex = setBackgroundForDescription(positions, lastIndex, pos);
	lastIndex = setEquips(positions, lastIndex, pos);
	lastIndex = setArmours(positions, lastIndex, pos);

	startOfInvetoryBoxes = lastIndex;
	startOfInvetoryBoxes;
	lastIndex = setBoxes(positions, lastIndex, pos);

	return startOfInvetoryBoxes; // start of inventory boxes
}

int Inventory::setInventoryBox(std::vector<sf::Vector2f>& positions, int startingIndex, sf::Vector2f pos)
{

	int lastIndex = startingIndex;

	sf::Vertex* quad = &m_vertices[lastIndex * 4];

	positions.at(0) = pos + inventoryBox.defaultPosition.pos.at(0);
	positions.at(1) = pos + inventoryBox.defaultPosition.pos.at(1);
	positions.at(2) = pos + inventoryBox.defaultPosition.pos.at(2);
	positions.at(3) = pos + inventoryBox.defaultPosition.pos.at(3);

	setVertices(positions, quad, lastIndex);

	quad[0].texCoords = inventoryBox.texCoords.pos.at(0);
	quad[1].texCoords = inventoryBox.texCoords.pos.at(1);
	quad[2].texCoords = inventoryBox.texCoords.pos.at(2);
	quad[3].texCoords = inventoryBox.texCoords.pos.at(3);

	inventoryBox.playerPos = pos;
	lastIndex++;
	return lastIndex;
}

int Inventory::setSettingsBox(std::vector<sf::Vector2f>& positions, int startingIndex, sf::Vector2f pos)
{
	int lastIndex = startingIndex;

	sf::Vertex* quad = &m_vertices[lastIndex * 4];

	positions.at(0) = pos + settingsBox.defaultPosition.pos.at(0);
	positions.at(1) = pos + settingsBox.defaultPosition.pos.at(1);
	positions.at(2) = pos + settingsBox.defaultPosition.pos.at(2);
	positions.at(3) = pos + settingsBox.defaultPosition.pos.at(3);

	setVertices(positions, quad, lastIndex);

	quad[0].texCoords = settingsBox.texCoords.pos.at(0);
	quad[1].texCoords = settingsBox.texCoords.pos.at(1);
	quad[2].texCoords = settingsBox.texCoords.pos.at(2);
	quad[3].texCoords = settingsBox.texCoords.pos.at(3);

	settingsBox.playerPos = pos;
	lastIndex++;
	return lastIndex;
}

int Inventory::setBackgroundForBoxes(std::vector<sf::Vector2f>& positions, int startingIndex, sf::Vector2f pos)
{
	int lastIndex = startingIndex;

	sf::Vertex* quad = &m_vertices[lastIndex * 4];

	positions.at(0) = pos + backgroundStorageBox.defaultPosition.pos.at(0);
	positions.at(1) = pos + backgroundStorageBox.defaultPosition.pos.at(1);
	positions.at(2) = pos + backgroundStorageBox.defaultPosition.pos.at(2);
	positions.at(3) = pos + backgroundStorageBox.defaultPosition.pos.at(3);

	setVertices(positions, quad, lastIndex);

	quad[0].texCoords = backgroundStorageBox.texCoords.pos.at(0);
	quad[1].texCoords = backgroundStorageBox.texCoords.pos.at(1);
	quad[2].texCoords = backgroundStorageBox.texCoords.pos.at(2);
	quad[3].texCoords = backgroundStorageBox.texCoords.pos.at(3);

	backgroundStorageBox.playerPos = pos;
	lastIndex++;
	return lastIndex;
}

int Inventory::setBackgroundForDescription(std::vector<sf::Vector2f>& positions, int startingIndex, sf::Vector2f pos)
{
	int lastIndex = startingIndex;

	sf::Vertex* quad = &m_vertices[lastIndex * 4];

	positions.at(0) = pos + backgroundDescBox.defaultPosition.pos.at(0);
	positions.at(1) = pos + backgroundDescBox.defaultPosition.pos.at(1);
	positions.at(2) = pos + backgroundDescBox.defaultPosition.pos.at(2);
	positions.at(3) = pos + backgroundDescBox.defaultPosition.pos.at(3);

	setVertices(positions, quad, lastIndex);

	quad[0].texCoords = backgroundDescBox.texCoords.pos.at(0);
	quad[1].texCoords = backgroundDescBox.texCoords.pos.at(1);
	quad[2].texCoords = backgroundDescBox.texCoords.pos.at(2);
	quad[3].texCoords = backgroundDescBox.texCoords.pos.at(3);

	backgroundDescBox.playerPos = pos;
	lastIndex++;
	return lastIndex;
}

int Inventory::setEquips(std::vector<sf::Vector2f>& positions, int startingIndex, sf::Vector2f pos) //pos - where was inv opened
{

	const int noBoxes = startingIndex + 8;
	int lastIndex = startingIndex; // to know where to start from
	equipsBoxes.horCount = 4;
	equipsBoxes.vertCount = 2;
	float noBoxesInRow = 0.f;
	float currentCollumn = 0.f;

	equipsBoxes.playerPos = pos;
	equipsBoxes.horzOffset = { 50.f, 0.f };
	equipsBoxes.vertOffset = { 0.f, 50.f };

	for (int i = lastIndex; i < noBoxes; i++)
	{
		sf::Vertex* quad = &m_vertices[i * 4];

		positions.at(0) = pos + equipsBoxes.defaultPosition.pos.at(0) + (equipsBoxes.horzOffset * noBoxesInRow) + (equipsBoxes.vertOffset * currentCollumn);
		positions.at(1) = pos + equipsBoxes.defaultPosition.pos.at(1) + (equipsBoxes.horzOffset * noBoxesInRow) + (equipsBoxes.vertOffset * currentCollumn);
		positions.at(2) = pos + equipsBoxes.defaultPosition.pos.at(2) + (equipsBoxes.horzOffset * noBoxesInRow) + (equipsBoxes.vertOffset * currentCollumn);
		positions.at(3) = pos + equipsBoxes.defaultPosition.pos.at(3) + (equipsBoxes.horzOffset * noBoxesInRow) + (equipsBoxes.vertOffset * currentCollumn);

		setVertices(positions, quad, i);

		quad[0].texCoords = equipsBoxes.texCoords.pos.at(0);
		quad[1].texCoords = equipsBoxes.texCoords.pos.at(1);
		quad[2].texCoords = equipsBoxes.texCoords.pos.at(2);
		quad[3].texCoords = equipsBoxes.texCoords.pos.at(3);

		noBoxesInRow++;
		if ((int)noBoxesInRow % equipsBoxes.horCount == 0)
		{ // set offset for next column
			currentCollumn++;
			noBoxesInRow = 0;
		}
		lastIndex = i;
	}
	lastIndex++;

	return lastIndex; //next fc must know last index to start from
}

int Inventory::setArmours(std::vector<sf::Vector2f>& positions, int startingIndex, sf::Vector2f pos) //pos - where was inv opened
{

	const int noBoxes = startingIndex + 11;

	int lastIndex = startingIndex;
	float noBoxesInRow = 0.f;
	float currentCollumn = 0.f;
	armourBoxes.horCount = 3;
	armourBoxes.vertCount = 4;
	armourBoxes.playerPos = pos;
	armourBoxes.horzOffset = { 50.f, 0.f };
	armourBoxes.vertOffset = { 0.f, 50.f };

	std::cout << "INDEX:" << startingIndex << std::endl;

	for (int i = lastIndex; i < noBoxes; i++)
	{
		sf::Vertex* quad = &m_vertices[i * 4];

		if (i == 22) // zvysit offset u posledniho radku aby tam bylo misto
			noBoxesInRow++;

		positions.at(0) = pos + armourBoxes.defaultPosition.pos.at(0) + (armourBoxes.horzOffset * noBoxesInRow) + (armourBoxes.vertOffset * currentCollumn);
		positions.at(1) = pos + armourBoxes.defaultPosition.pos.at(1) + (armourBoxes.horzOffset * noBoxesInRow) + (armourBoxes.vertOffset * currentCollumn);
		positions.at(2) = pos + armourBoxes.defaultPosition.pos.at(2) + (armourBoxes.horzOffset * noBoxesInRow) + (armourBoxes.vertOffset * currentCollumn);
		positions.at(3) = pos + armourBoxes.defaultPosition.pos.at(3) + (armourBoxes.horzOffset * noBoxesInRow) + (armourBoxes.vertOffset * currentCollumn);

		setVertices(positions, quad, i);

		quad[0].texCoords = armourBoxes.texCoords.pos.at(0);
		quad[1].texCoords = armourBoxes.texCoords.pos.at(1);
		quad[2].texCoords = armourBoxes.texCoords.pos.at(2);
		quad[3].texCoords = armourBoxes.texCoords.pos.at(3);

		noBoxesInRow++;

		if ((int)noBoxesInRow % armourBoxes.horCount == 0)
		{
			currentCollumn++;
			noBoxesInRow = 0;
		}
		lastIndex = i;
	}
	lastIndex++;
	return lastIndex;
}

int Inventory::setBoxes(std::vector<sf::Vector2f>& positions, int startingIndex, sf::Vector2f pos)
{

	const int noBoxes = startingIndex + 84;
	int lastIndex = startingIndex;
	float noBoxesInRow = 0.f;
	float currentCollumn = 0.f;

	storageBoxes.horCount = 7;
	storageBoxes.vertCount = 12;

	storageBoxes.playerPos = pos;
	storageBoxes.horzOffset = { 22, 0 };
	storageBoxes.vertOffset = { 0, 24 };

	for (int i = lastIndex; i < noBoxes; i++)
	{
		sf::Vertex* quad = &m_vertices[i * 4];

		positions.at(0) = pos + storageBoxes.defaultPosition.pos.at(0) + (storageBoxes.horzOffset * noBoxesInRow)
			+ (storageBoxes.vertOffset * currentCollumn);
		positions.at(1) = pos + storageBoxes.defaultPosition.pos.at(1) + (storageBoxes.horzOffset * noBoxesInRow)
			+ (storageBoxes.vertOffset * currentCollumn);
		positions.at(2) = pos + storageBoxes.defaultPosition.pos.at(2) + (storageBoxes.horzOffset * noBoxesInRow)
			+ (storageBoxes.vertOffset * currentCollumn);
		positions.at(3) = pos + storageBoxes.defaultPosition.pos.at(3) + (storageBoxes.horzOffset * noBoxesInRow)
			+ (storageBoxes.vertOffset * currentCollumn);

		setVertices(positions, quad, i);

		quad[0].texCoords = storageBoxes.texCoords.pos.at(0);
		quad[1].texCoords = storageBoxes.texCoords.pos.at(1);
		quad[2].texCoords = storageBoxes.texCoords.pos.at(2);
		quad[3].texCoords = storageBoxes.texCoords.pos.at(3);

		noBoxesInRow++;
		if ((int)noBoxesInRow % storageBoxes.horCount == 0)
		{
			currentCollumn++;
			noBoxesInRow = 0;
		}
		lastIndex = i;
	}
	lastIndex++;
	return lastIndex;
}

void Inventory::setStartingValues()
{
	settingsBox.defaultPosition.pos.resize(4);
	settingsBox.defaultPosition.pos.at(0) = sf::Vector2f(320.f, 50.f);
	settingsBox.defaultPosition.pos.at(1) = sf::Vector2f(320.f, 0.f);
	settingsBox.defaultPosition.pos.at(2) = sf::Vector2f(640.f, 0.f);
	settingsBox.defaultPosition.pos.at(3) = sf::Vector2f(640.f, 50.f);
	settingsBox.texCoords.pos.resize(4);
	settingsBox.texCoords.pos.at(0) = sf::Vector2f(0.f, 100.f);
	settingsBox.texCoords.pos.at(1) = sf::Vector2f(0.f, 50.f);
	settingsBox.texCoords.pos.at(2) = sf::Vector2f(320.f, 50.f);
	settingsBox.texCoords.pos.at(3) = sf::Vector2f(320.f, 100.f);

	inventoryBox.defaultPosition.pos.resize(4);
	inventoryBox.defaultPosition.pos.at(0) = sf::Vector2f(0, 50);
	inventoryBox.defaultPosition.pos.at(1) = sf::Vector2f(0, 0);
	inventoryBox.defaultPosition.pos.at(2) = sf::Vector2f(320, 0);
	inventoryBox.defaultPosition.pos.at(3) = sf::Vector2f(320, 50);
	inventoryBox.texCoords.pos.resize(4);
	inventoryBox.texCoords.pos.at(0) = sf::Vector2f(0.f, 150.f);
	inventoryBox.texCoords.pos.at(1) = sf::Vector2f(0.f, 100.f);
	inventoryBox.texCoords.pos.at(2) = sf::Vector2f(320.f, 100.f);
	inventoryBox.texCoords.pos.at(3) = sf::Vector2f(320.f, 150.f);

	backgroundStorageBox.defaultPosition.pos.resize(4);
	backgroundStorageBox.defaultPosition.pos.at(0) = sf::Vector2f(0.f, 360.f);
	backgroundStorageBox.defaultPosition.pos.at(1) = sf::Vector2f(0.f, 50.f);
	backgroundStorageBox.defaultPosition.pos.at(2) = sf::Vector2f(160.f, 50.f);
	backgroundStorageBox.defaultPosition.pos.at(3) = sf::Vector2f(160.f, 360.f);
	backgroundStorageBox.texCoords.pos.resize(4);
	backgroundStorageBox.texCoords.pos.at(0) = sf::Vector2f(0.f, 200.f);
	backgroundStorageBox.texCoords.pos.at(1) = sf::Vector2f(0.f, 150.f);
	backgroundStorageBox.texCoords.pos.at(2) = sf::Vector2f(320.f, 150.f);
	backgroundStorageBox.texCoords.pos.at(3) = sf::Vector2f(320.f, 200.f);

	backgroundDescBox.defaultPosition.pos.resize(4);
	backgroundDescBox.defaultPosition.pos.at(0) = sf::Vector2f(160.f, 230.f);
	backgroundDescBox.defaultPosition.pos.at(1) = sf::Vector2f(160.f, 50.f);
	backgroundDescBox.defaultPosition.pos.at(2) = sf::Vector2f(360.f, 50.f);
	backgroundDescBox.defaultPosition.pos.at(3) = sf::Vector2f(360.f, 230.f);
	backgroundDescBox.texCoords.pos.resize(4);
	backgroundDescBox.texCoords.pos.at(0) = sf::Vector2f(0.f, 200.f);
	backgroundDescBox.texCoords.pos.at(1) = sf::Vector2f(0.f, 150.f);
	backgroundDescBox.texCoords.pos.at(2) = sf::Vector2f(320.f, 150.f);
	backgroundDescBox.texCoords.pos.at(3) = sf::Vector2f(320.f, 200.f);

	equipsBoxes.defaultPosition.pos.resize(4);
	equipsBoxes.defaultPosition.pos.at(0) = sf::Vector2f(170.f, 280.f);
	equipsBoxes.defaultPosition.pos.at(1) = sf::Vector2f(170.f, 240.f);
	equipsBoxes.defaultPosition.pos.at(2) = sf::Vector2f(210.f, 240.f);
	equipsBoxes.defaultPosition.pos.at(3) = sf::Vector2f(210.f, 280.f);
	equipsBoxes.texCoords.pos.resize(4);
	equipsBoxes.texCoords.pos.at(0) = sf::Vector2f(0.f, 40.f);
	equipsBoxes.texCoords.pos.at(1) = sf::Vector2f(0.f, 0.f);
	equipsBoxes.texCoords.pos.at(2) = sf::Vector2f(40.f, 0.f);
	equipsBoxes.texCoords.pos.at(3) = sf::Vector2f(40.f, 40.f);

	armourBoxes.defaultPosition.pos.resize(4);
	armourBoxes.defaultPosition.pos.at(0) = sf::Vector2f(430.f, 140.f);
	armourBoxes.defaultPosition.pos.at(1) = sf::Vector2f(430.f, 100.f);
	armourBoxes.defaultPosition.pos.at(2) = sf::Vector2f(470.f, 100.f);
	armourBoxes.defaultPosition.pos.at(3) = sf::Vector2f(470.f, 140.f);
	armourBoxes.texCoords.pos.resize(4);
	armourBoxes.texCoords.pos.at(0) = sf::Vector2f(0.f, 40.f);
	armourBoxes.texCoords.pos.at(1) = sf::Vector2f(0.f, 0.f);
	armourBoxes.texCoords.pos.at(2) = sf::Vector2f(40.f, 0.f);
	armourBoxes.texCoords.pos.at(3) = sf::Vector2f(40.f, 40.f);

	storageBoxes.defaultPosition.pos.resize(4);
	storageBoxes.defaultPosition.pos.at(0) = sf::Vector2f(4.f, 80.f);
	storageBoxes.defaultPosition.pos.at(1) = sf::Vector2f(4.f, 58.f);
	storageBoxes.defaultPosition.pos.at(2) = sf::Vector2f(24.f, 58.f);
	storageBoxes.defaultPosition.pos.at(3) = sf::Vector2f(24.f, 80.f);
	storageBoxes.texCoords.pos.resize(4);
	storageBoxes.texCoords.pos.at(0) = sf::Vector2f(0.f, 40.f);
	storageBoxes.texCoords.pos.at(1) = sf::Vector2f(0.f, 0.f);
	storageBoxes.texCoords.pos.at(2) = sf::Vector2f(40.f, 0.f);
	storageBoxes.texCoords.pos.at(3) = sf::Vector2f(40.f, 40.f);
}