#include "Platform/Platform.hpp"
#include "MainSystems/Game.h"

int main()
{
	util::Platform platform;
#if defined(_DEBUG)
	std::cout << "Hello World!" << std::endl;
#endif
	Game game(sf::VideoMode(1920, 1080), "OreMiner",sf::Vector2f(640, 360));
	game.gameLoop();
	return 0;
}
