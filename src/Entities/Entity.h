#pragma once
class Entity
{

private:
	sf::RectangleShape body;
public:
	Entity();

	virtual sf::RectangleShape& getBody() { return body; };

	virtual void setBody(sf::RectangleShape body) { this->body = body; };

	virtual void update();

	virtual void draw();

	~Entity();
};

