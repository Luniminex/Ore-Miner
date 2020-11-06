#include "MouseClass.h"
#include "../Inventory/Inventory.h"

MouseClass::MouseClass()
{
}

void MouseClass::calcJi(sf::RenderWindow& win, ObjectManager* objMan, Player& player) {
pos = (sf::Vector2i)win.mapPixelToCoords(pos);
	if (pos.x >= player.getPos().x - 100.f && pos.x <= player.getPos().x + 100.f &&
		pos.y >= player.getPos().y - 100.f  && pos.y <= player.getPos().y + 100.f) {
		for (ConcreteTileObject* n : objMan->objects) {
			if (n->Concretebody.getGlobalBounds().contains((sf::Vector2f)pos) && click() == true) {
				if (n->shared->resourceDropID <= 12) { // ID objektu ktery nedropuje nic
					player.getRefToItemman().resources.at(n->shared->resourceDropID)->add(n->shared->amountDrop);
					particles.generateParticlesByID(3, (sf::Vector2f)pos, n->shared->resourceDropID);
				}
			}
		}
	}
}

MouseClass::~MouseClass()
{
}
