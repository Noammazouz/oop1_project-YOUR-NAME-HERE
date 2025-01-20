#pragma once

#include <SFML/Graphics.hpp>
#include "Const.h"
class GameObject
{
public:
	GameObject();
	GameObject(const sf::Texture texture, sf::Vector2f pos);
	virtual ~GameObject() = default;
	virtual void draw(sf::RenderWindow& window);
	virtual sf::Vector2f getPosition() const;
	virtual void setPosition(const sf::Vector2f position);
	virtual void setTexture(const sf::Texture texture);
private:
	sf::Sprite m_pic;
	sf::Vector2f m_position;
};