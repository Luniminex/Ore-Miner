#include "TextManager.h"



TextManager::TextManager()
{

}

void TextManager::draw(sf::RenderWindow& win) {
	for (Texts* n : texts) {
		win.draw(n->getText());
	}
}

TextManager::~TextManager()
{
}


Texts::Texts(){

}

void Texts::createTextOnMap(sf::Vector2f mapPosition, unsigned int charSize, sf::Vector2f scale, const std::string& constText) {
	font.loadFromFile("FFFFORWA.TTF");
	sf::Texture& tex = const_cast<sf::Texture&>(font.getTexture(charSize));
	this->constText = constText;
	tex.setSmooth(false);
	text.setFont(font);
	text.setCharacterSize(charSize);
	text.setScale(scale);
	text.setPosition(mapPosition);
	text.setString(this->constText);
}

void Texts::createTextOnScreen(sf::Vector2f mapPosition, unsigned int charSize, sf::Vector2f scale, 
	sf::RenderWindow& win, const std::string& constText) {
	font.loadFromFile("FFFFORWA.TTF");
	this->constText = constText;
	sf::Texture& tex = const_cast<sf::Texture&>(font.getTexture(charSize));
	tex.setSmooth(false);
	text.setFont(font);
	text.setCharacterSize(charSize);
	text.setScale(scale);
	text.setString(this->constText);
	pos = (sf::Vector2f)win.mapCoordsToPixel(mapPosition);
	text.setPosition(pos);
}

void Texts::updateText(std::string text_, sf::Vector2f pos) {
	this->pos = pos;
	text.setPosition(this->pos);
	text.setString(constText + text_);
}

void Texts::draw(sf::RenderWindow& win) {
	win.draw(text);
}

Texts::~Texts() {

}