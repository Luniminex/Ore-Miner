#include "ItemManager.h"



ItemManager::ItemManager()
{
	;
}

void ItemManager::initItems() {
	std::cout << "CREATING ITEMMANAGER" << std::endl;
	initResources();
	initArmours();
	initPickaxes();
}

void ItemManager::initResources() {
	std::cout << "INITING RESOURCES" << std::endl;
	resources.push_back(new Resources("Gold Ore","The beautiful shiny ore."));
	resources.push_back(new Resources("Iron Ore", "Sturdy material. Commonly used for forging tools and weapons."));
	resources.push_back(new Resources("Copper Ore", "Its green and yet it is orangish."));
	resources.push_back(new Resources("Stone", "Used as a basic building material. Or as a thing for throwing at people."));
	resources.push_back(new Resources("Log", "Material for building cottages or handles for tools."));
	resources.push_back(new Resources("Vines", "I guess you could make these into ropes..."));
	resources.push_back(new Resources("Ruby", "Kings would start wars for these."));
	resources.push_back(new Resources("Emerald", "Quite spectacular."));
	resources.push_back(new Resources("Sappire", "Blue like the oceans and sky above us combined."));
	resources.push_back(new Resources("Sticks", "Sticks and stones."));
	resources.push_back(new Resources("Red Flower", "Useful when you are in the pit of love"));
	resources.push_back(new Resources("Yellow Flower", "Gift like this never lets you down."));

}
void ItemManager::initPickaxes() {
	std::cout << "INITING PICKAXES" << std::endl;
	pickaxes.push_back(new Pickaxe("Basic Pickaxe","Pickaxe made of some rocks found on the ground.", 10));
	pickaxes.push_back(new Pickaxe("Iron Pickaxe", "The basic tool of every miner that ever lived!", 20));
	pickaxes.push_back(new Pickaxe("Reinforced Golden Pickaxe", "Well, not everyone can afford this beauty.", 100));
}
void ItemManager::initArmours() {
	std::cout << "INITING ARMOURS" << std::endl;
	armours.push_back(new Armour("Leather Chestplate", "Provides some basic protection against the evils in this world.",10 ,EarmourTypes::chestplate));
	armours.push_back(new Armour("Iron Chestplate", "Armour every fighter needs.", 50,EarmourTypes::chestplate));
	armours.push_back(new Armour("Gold Chestplate","Why do you need this? just hire bodyguards with this kind of money!", 100,EarmourTypes::chestplate));
}

ItemManager::~ItemManager() {
	resources.clear();
	armours.clear();
	pickaxes.clear();
}