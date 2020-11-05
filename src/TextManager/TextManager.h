#pragma once

class Texts
{

private:
	sf::Font font;
	sf::Vector2f pos;
	sf::Text text;
	std::string constText;

public:
	Texts();

	void createTextOnMap(sf::Vector2f mapPosition, unsigned int charSize, sf::Vector2f scale, const std::string& constText);

	void createTextOnScreen(sf::Vector2f mapPosition, unsigned int charSize, sf::Vector2f scale,
		sf::RenderWindow& win, const std::string& constText);

	void updateText(std::string text_, sf::Vector2f pos);

	void draw(sf::RenderWindow& win);

	sf::Text getText()
	{
		return text;
	};

	~Texts();
};

class TextManager
{
public:
	std::vector<Texts*> texts;

public:
	TextManager();

	void draw(sf::RenderWindow& win);

	~TextManager();
};
