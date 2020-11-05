#pragma once
#ifndef GLOBAL_H
#define GLOBAL_H
#include "../Subsystems/ParticleSystem.h"

extern ParticleSystem particles;

struct box {
	std::vector<sf::Vector2f> pos;
};

struct valuesForDrawing {
	sf::Vector2f playerPos;
	box defaultPosition;
	box texCoords;
	sf::Vector2f horzOffset;
	sf::Vector2f vertOffset;
	int horCount = 0;
	int vertCount = 0;
};
namespace EarmourTypes {
	enum armourTypes {
		chestplate, helm, shoulder, pant, ring, glove, boots
	};
}

namespace Eresources {
	enum Eresources {
		goldOre, ironOre, copperOre,
		stone, log, vines,
		ruby, emerald, sapphire, sticks,
		yellowFlower, redFlower, defaultItem
	};
}

namespace Eflags {
	enum Eflags {
		resources, pickaxes, chestplates
	};
}
#endif