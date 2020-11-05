#ifndef ITEMMANAGER_H
#define ITEMMANAGER_H

#pragma once

#include "../Global/Global.h"
#include "Items.h"

class ItemManager
{

public:
	std::vector<Resources*> resources;
	std::vector<Pickaxe*> pickaxes;
	std::vector<Armour*> armours;

private:
	void initResources();
	void initPickaxes();
	void initArmours();

public:
	ItemManager();
	void initItems();

	unsigned int getNoResources()
	{
		return resources.size();
	};

	unsigned int getNoPickaxes()
	{
		return pickaxes.size();
	};

	unsigned int getNoArmours()
	{
		return armours.size();
	};
	~ItemManager();
};

#endif