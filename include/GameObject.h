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
	/*virtual void collide(GameObject& otherObject) = 0;
	virtual void collide(Door& otherObject) = 0;
	virtual void collide(Guard& otherObject) = 0;
	virtual void collide(Bombs& otherobject) = 0;
	virtual void collide*/


protected:
	sf::Sprite m_pic;
	float m_cell_size[2];

private:
	void setTexture(const sf::Texture& texture);
	void setSprite(sf::Vector2f pos);
};