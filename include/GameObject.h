#pragma once

#include <SFML/Graphics.hpp>
#include "Const.h"

class Door;
class Bombs;
class Presents;
class Player;
class Wall;
class Guard;

class GameObject
{
public:
	GameObject();
	GameObject(const sf::Texture& texture, sf::Vector2f pos, float CELL_WIDTH, float CELL_HEIGHT);
	GameObject(const sf::Texture& texture, sf::Vector2f pos);
	virtual ~GameObject() = default;

	sf::FloatRect getBounds() const;

	virtual void draw(sf::RenderWindow& window);
	virtual sf::Vector2f getPosition() const;
	virtual void staticCollide(GameObject& otherObject) = 0;
	virtual ReturnType playerCollide(Player& otherObject) = 0;
	//virtual void updateableCollide(GameObject& otherObject) = 0;
	//virtual ReturnType doorCollide(Door& otherObject) = 0;
	//virtual ReturnType guardCollide(Guard& otherObject) = 0;
	//virtual ReturnType bombCollide(Bombs& otherobject) = 0;
	// virtual ReturnType wallCollide(Wall& otherobject) = 0;
	////virtual void collide(presents& otherObject) = 0;


protected:
	void updatePosition(sf::Vector2f direction);
	void setPosition(const sf::Vector2f& position);

private:
	void setTexture(const sf::Texture& texture);
	void setSprite(sf::Vector2f pos);
	sf::Sprite m_pic;
	float m_cell_size[2];
};