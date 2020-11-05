#include "Animation.h"



Animation::Animation(sf::Texture* tex, sf::Vector2u imageCount, float switchTime)
{
	this->switchTime = switchTime;
	this->imageCount = imageCount;
	totalTime = 0.0f;
	currentImage.x = 0;

	uvRect.width = tex->getSize().x / float(imageCount.x);
	uvRect.height = tex->getSize().y / float(imageCount.y);

}


void Animation::createAnimation(sf::Texture* tex, sf::Vector2u imageCount, float switchTime)
{
	this->switchTime = switchTime;
	this->imageCount = imageCount;
	totalTime = 0.0f;
	currentImage.x = 0;

	uvRect.width = tex->getSize().x / float(imageCount.x);
	uvRect.height = tex->getSize().y / float(imageCount.y);

}
void Animation::update(int row, float deltaTime) {
	currentImage.y = row;
	totalTime += deltaTime;

	if (totalTime >= switchTime) {
		totalTime -= switchTime;
		currentImage.x++;
		if (currentImage.x >= imageCount.x) {
			currentImage.x = 0;
		}
	}
	uvRect.left = currentImage.x * uvRect.width;
	uvRect.top = currentImage.y * uvRect.height;
}

Animation::~Animation()
{
}
