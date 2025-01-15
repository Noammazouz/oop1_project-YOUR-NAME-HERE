#pragma once

#include <SFML/Graphics.hpp>

class GameObject
{
public:
	GameObject(sf::Sprite base_pic);
	virtual setSprite();
	//virtual sf::RectangleShape makeRectangle() const = 0;
private:
	sf::Sprite m_pic;
};