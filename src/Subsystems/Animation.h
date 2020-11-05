#pragma once
#include <SFML/Graphics.hpp>
class Animation
{
	sf::Vector2u imageCount;
	sf::Vector2u currentImage;

	float totalTime;
	float switchTime;

public:
	sf::IntRect uvRect;
	Animation(sf::Texture* tex, sf::Vector2u imageCount, float switchTime);
	void createAnimation(sf::Texture* tex, sf::Vector2u imageCount, float switchTime);
	void update(int row, float deltaTime);

	~Animation();
};

