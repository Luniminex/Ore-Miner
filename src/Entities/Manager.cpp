#include "Manager.h"



Manager::Manager()
{
}

void Manager::update() {
	for (Entity* n : entities) {
		n->update(/*deltaTime pokud to zjistis tak gl*/);
	}

}

void Manager::draw(sf::RenderWindow& win) {
	for (Entity* n : entities) {
		win.draw(n->getBody());
	}
}


Manager::~Manager()
{
}
