#include "Player.h"
#include "../Inventory/Inventory.h"

Player::Player(std::string name, std::string path, sf::Vector2f pos,
	sf::Vector2f size, ItemManager* itemman) :
	anim(&tex, sf::Vector2u(7, 1), 0.3f)

{
	this->name = name;
	m_itemman = itemman;
	getBody().setPosition(pos);
	getBody().setSize(size);

	tex.loadFromFile(path);

	getBody().setTexture(&tex);
	getBody().setOrigin(getBody().getSize() / 2.0f);

	anim.createAnimation(&tex, sf::Vector2u(7, 1), 0.1f);

	/*	getBody().setOutlineColor(sf::Color::Yellow);
	getBody().setOutlineThickness(2.0f);*/
}

void Player::update(float deltaTime)
{
	sf::Vector2f movement = { 0.f, 0.f };
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
		movement.x -= speed * deltaTime;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		movement.x += speed * deltaTime;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
		movement.y -= speed * deltaTime;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
		movement.y += speed * deltaTime;

	if (movement.x < 0.f)
	{
		movement.x = std::floor(movement.x);
	}
	else
	{
		movement.x = std::ceil(movement.x);
	}
	if (movement.y < 0.f)
	{
		movement.y = std::floor(movement.y);
	}
	else
	{
		movement.y = std::ceil(movement.y);
	}

	getBody().move(movement);

	movement = getPos();

	if (movement.x < 0.f)
	{
		movement.x = std::ceil(movement.x);
	}
	else
	{
		movement.x = std::floor(movement.x);
	}
	if (movement.y < 0.f)
	{
		movement.y = std::ceil(movement.y);
	}
	else
	{
		movement.y = std::floor(movement.y);
	}
	getBody().setPosition(movement.x, movement.y);

	anim.update(0, deltaTime);
	getBody().setTextureRect(anim.uvRect);

	JI.x = getBody().getPosition().x / 32;
	JI.y = getBody().getPosition().y / 32;

	//std::cout << "Player J:" << JI.x << " - Player I:" << JI.y<<std::endl;
}

void Player::draw()
{
}

Player::~Player()
{
}
