#pragma once

#include <SFML/Graphics.hpp>
#include "Const.h"
class GameObject
{
public:
	GameObject();
	GameObject(const sf::Texture& texture, sf::Vector2f pos, float CELL_WIDTH, float CELL_HEIGHT);
	GameObject(const sf::Texture& texture, sf::Vector2f pos);
	virtual ~GameObject() = default;

	virtual void draw(sf::RenderWindow& window);
	virtual sf::Vector2f getPosition() const;
	sf::Vector2f getStartingPosition() const;


protected:
	void move(sf::Vector2f direction);

private:
	void setTexture(const sf::Texture& texture);
	void setSprite(sf::Vector2f pos);
	float m_cell_size[2];
	sf::Sprite m_pic;
	sf::Vector2f m_starting_position;
	//sf::Vector2f m_position;
};