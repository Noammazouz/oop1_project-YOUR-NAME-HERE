#pragma once

#include <SFML/Graphics.hpp>
#include "Const.h"
class GameObject
{
public:
	GameObject();
	GameObject(const sf::Texture& texture, sf::Vector2f pos, float CELL_WIDTH, float CELL_HEIGHT);
	virtual ~GameObject() = default;

	virtual void draw(sf::RenderWindow& window);
	virtual sf::Vector2f getPosition() const;
	//virtual void setPosition(const sf::Vector2f position);
protected:
	void move(sf::Vector2f direction);

private:
	void setTexture(const sf::Texture& texture);
	sf::Sprite m_pic;
	sf::Vector2f m_position;
};