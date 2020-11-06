#include "Game.h"

ParticleSystem particles(300);

Game::Game(sf::VideoMode videoMode, std::string title, sf::Vector2f viewSize) :
	win(videoMode, title, sf::Style::Fullscreen),
	view(sf::Vector2f(0.0f, 0.0f), viewSize),
	itemmanager(),
	inv(new InventoryItems(0), new InventoryControl())
{
	win.setFramerateLimit(60);
	win.setVerticalSyncEnabled(true);
	win.setKeyRepeatEnabled(false);
	itemmanager.initItems();
}

void Game::gameLoop() {
	//init

	float deltaTime = 0.0f;

	sf::Clock clock;
	sf::Clock ParticleClock;

	Tilemap tilemap;

	TextManager* textManager = new TextManager();

	Texts framerateText;
	framerateText.createTextOnScreen((sf::Vector2f)win.mapCoordsToPixel(sf::Vector2f(100,100)), 100, sf::Vector2f(0.04f, 0.04f), win, "Framerate:");

	Manager* manager = new Manager;

	tilemap.loadFromFile("content/Map/ground.png","content/Map/TheMap.txt");

	Player player("Johny", "content/Player/animplayer.png", sf::Vector2f(0.f, 0.f),
		sf::Vector2f(16.0f, 16.0f),&itemmanager);

	ObjectGenerator objGenerator;

	manager->entities.push_back(&player);
	//events
	float currentTime = 0;
	float fps = 0;

	inv.openInventory({ 0.f,0.f }, player.getRefToItemman()); // VZDYCKY INIT INV PRED PRIDAVANI ITEMU, JINAK BLBNE, TEMP RESENI
	inv.openInventory({ 0.f,0.f }, player.getRefToItemman());

	while (win.isOpen()) {

		deltaTime = clock.restart().asSeconds();
		sf::Time elapsed = ParticleClock.restart();

		sf::Event evnt;
		while (win.pollEvent(evnt)) {
			switch (evnt.type) {
			case sf::Event::Closed:
				win.close();
				break;
			case sf::Event::TextEntered:
				std::cout << (char)evnt.text.unicode;
				break;
			case sf::Event::MouseButtonPressed:
				m1.pos = sf::Mouse::getPosition(win);
				break;
			case sf::Event::MouseButtonReleased:
				m1.clicked = true;
				if (evnt.mouseButton.button == sf::Mouse::Left) {
					m1.pos = sf::Mouse::getPosition(win);
					m1.calcJi(win, &objGenerator.getObjectManager(), player);
					m1.pos = sf::Mouse::getPosition(win);
					std::cout << "MOUSE POSxy:" << m1.pos.x << "," << m1.pos.y << std::endl;
				}
				break;
			case sf::Event::KeyReleased:
				if (evnt.key.code == sf::Keyboard::E) {
					inv.openInventory(player.getPos() - (sf::Vector2f)(view.getSize() / 2.f), player.getRefToItemman());
				}
				if (evnt.key.code == sf::Keyboard::Q) { itemmanager.pickaxes.at(0)->givePickaxe(); }
					if(evnt.key.code == sf::Keyboard::R){ itemmanager.pickaxes.at(2)->givePickaxe(); }
					if (evnt.key.code == sf::Keyboard::T) { itemmanager.armours.at(0)->giveArmour(); }
					if (evnt.key.code == sf::Keyboard::Z) { itemmanager.armours.at(2)->giveArmour(); }
				break;
			default:
				break;
			}
		}
		//updates
		if (!inv.open) {
			objGenerator.generateObjects(player);
			player.update(deltaTime);

			objGenerator.checkColl(player);

			particles.updateParticles(elapsed, deltaTime);

			view.setCenter((std::floor(player.getPos().x)),
				(std::floor(player.getPos().y)));

			//clear, then drawaaad
			win.clear(sf::Color(150, 150, 150));
			//draw

			win.draw(tilemap);
			objGenerator.drawMap(win);
			manager->draw(win);
			win.draw(particles);

		}
		//
		framerateText.updateText(std::to_string((int)fps), win.mapPixelToCoords(sf::Vector2i(100, 100)));
		//
		if (inv.open) {
			inv.getRefToInvControl().ControllingInv(inv);
			win.draw(inv);//background
			win.draw(inv.getRefToInvItems());//items
			win.draw(inv.getRefToInvControl());//select box
			inv.getRefToInvItems().drawText(win);//text
		}

		win.draw(framerateText.getText());
		currentTime = clock.getElapsedTime().asSeconds();
		fps = 1.f / currentTime;
		//set view
		win.setView(view);
		//display
		win.display();

	}

	delete manager;
	delete textManager;
}

Game::~Game()
{
}
