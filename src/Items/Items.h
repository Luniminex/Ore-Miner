#pragma once
#include "../Global/Global.h"

class Items
{
public:
	std::vector<bool> m_flags;

protected:
	unsigned int m_ID = 0;
	std::string m_name = "default";
	std::string m_description = "";

public:
	Items(const std::string& name, const std::string& desc);

	void setDescription(const std::string& desc)
	{
		this->m_description = desc;
	};

	std::string& getDescription()
	{
		return m_description;
	};

	unsigned int getID()
	{
		return m_ID;
	};

	template <typename T>
	void setFlags(const T& v)
	{
		m_flags[v] = true;
	}

	template <typename T, typename... types>
	void setFlags(const T& first, const types&... args)
	{
		m_flags[first] = true;
		setFlags(args...);
	}
	~Items();
};
//**********************************************************//
class Resources : public Items
{
private:
	static int m_noResources;
	size_t m_amount = 0;

public:
	Resources(const std::string& name, const std::string& desc);

	void add(int amount)
	{
		this->m_amount += amount;
	};

	void remove(int amount)
	{
		this->m_amount -= amount;
	};

	void set(int amount)
	{
		this->m_amount = amount;
	};

	size_t getAmount()
	{
		return m_amount;
	};

	~Resources();
};
//**********************************************************//
class Equipable
{
protected:
	bool m_equiped = false;

public:
	void equip()
	{
		m_equiped = true;
	}

	void unequip()
	{
		m_equiped = false;
	};

	bool isEquiped()
	{
		return m_equiped;
	};
};
//**********************************************************//
class Pickaxe : public Items, public Equipable
{
private:
	static int m_noEquipment;

	int m_miningPower = 0;
	bool m_owned = false;

public:
	Pickaxe(const std::string& name, const std::string& desc, int miningPower);

	void givePickaxe()
	{
		m_owned = true;
	};

	void takePickaxe()
	{
		m_owned = false;
	};

	bool isOWned()
	{
		return m_owned;
	};

	~Pickaxe();
};
//**********************************************************//
class Armour : public Items, public Equipable
{
private:
	static int m_noArmour;

	unsigned int m_armour = 0;
	int m_armourType = 0;
	bool m_owned = 0;

public:
	Armour(const std::string& name, const std::string& desc, unsigned int armour, int type);

	void giveArmour()
	{
		m_owned = true;
	};

	void takeArmour()
	{
		m_owned = false;
	};

	bool isOWned()
	{
		return m_owned;
	};

	~Armour();
};