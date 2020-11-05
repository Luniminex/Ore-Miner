#include "Items.h"

Items::Items(const std::string& name,const std::string& desc)
{
	m_flags.resize(3);
	this->m_name = name;
	this->m_description = desc;
}

Items::~Items()
{
}
//**********************************************************//
int Resources::m_noResources = 0;
Resources::Resources(const std::string& name, const std::string& desc) : Items(name,desc)
{
	m_flags[Eflags::resources] = true;
	m_flags[Eflags::pickaxes] = false;
	m_flags[Eflags::chestplates] = false;
	m_noResources++;
	m_ID = m_noResources;
}

Resources::~Resources(){

}
//**********************************************************//
int Pickaxe::m_noEquipment = 0;
Pickaxe::Pickaxe(const std::string& name, const std::string& desc, int miningPower) : Items(name,desc) {
	m_flags[Eflags::resources] = false;
	m_flags[Eflags::pickaxes] = true;
	m_flags[Eflags::chestplates] = false;
	m_noEquipment++;
	m_ID = m_noEquipment;
	m_miningPower = miningPower;
	m_owned = false;
}

Pickaxe::~Pickaxe() {

}
//**********************************************************//
int Armour::m_noArmour = 0;
Armour::Armour(const std::string& name, const std::string& desc, unsigned int armour, int type) : Items(name,desc) {
	m_flags[Eflags::resources] = false;
	m_flags[Eflags::pickaxes] = false;
	m_flags[Eflags::chestplates] = true;
	m_noArmour++;
	m_ID = m_noArmour;
	m_armour = armour;
	m_armourType = type;
}

Armour::~Armour() {

}