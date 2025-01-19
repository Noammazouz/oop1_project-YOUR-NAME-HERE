#pragma once

#include <SFML/Graphics.hpp>

class GameObject
{
public:
	virtual ~GameObject() = default;
	virtual void draw(sf::RenderWindow& window);
	virtual sf::Vector2f getPosition() const = 0;
	virtual void setSprite(const sf::Sprite& sprite) = 0;
};