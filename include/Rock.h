#pragma once
#include "StaticObject.h"

class Rock : public StaticObject
{
public:
	Rock(sf::Vector2f position, const sf::Texture& texture, float CELL_WIDTH, float CELL_HEIGHT);
	//virtual void staticCollide(GameObject& otherObject) = 0;
	//virtual void updateableCollide(GameObject& otherObject) = 0;
	//virtual bool doorCollide(Door& otherObject) = 0;
	//virtual bool wallCollide(Wall& otherobject) = 0;
	//virtual bool guardCollide(Guard& otherObject) = 0;
	//virtual bool bombCollide(Bombs& otherobject) = 0;
	//virtual bool playerCollide(Player& otherObject) = 0;
	~Rock() = default;
};