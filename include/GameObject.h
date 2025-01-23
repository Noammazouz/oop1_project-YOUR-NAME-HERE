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
	virtual void collide(GameObject& otherObject) = 0;
	virtual void playerCollide(Player& otherObject) {};
	//virtual void updateableCollide(GameObject& otherObject) {};
	//virtual ReturnType doorCollide(Door& otherObject) {};
	virtual void guardCollide(Guard& otherObject) = 0;
	//virtual ReturnType bombCollide(Bombs& otherobject) {};
	// virtual ReturnType wallCollide(Wall& otherobject) {};
	////virtual void collide(presents& otherObject) = 0;
	void setPosition(const sf::Vector2f& position);


protected:
	void updatePosition(sf::Vector2f direction);

private:
	void setTexture(const sf::Texture& texture);
	void setSprite(sf::Vector2f pos);
	sf::Sprite m_pic;
	float m_cell_size[2];
};