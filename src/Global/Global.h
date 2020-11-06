#pragma once
#ifndef GLOBAL_H
#define GLOBAL_H
#include "../Subsystems/ParticleSystem.h"

extern ParticleSystem particles;

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