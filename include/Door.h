#pragma once
#include "StaticObject.h"

class Door : public StaticObject
{
public:
	Door(sf::Vector2f position, const sf::Texture& texture, float CELL_WIDTH, float CELL_HEIGHT);
	virtual void collide(GameObject& otherObject) override;
	//virtual bool doorCollide(Door& otherObject) = 0;
	//virtual bool wallCollide(Wall& otherobject) = 0;
	virtual void guardCollide(Guard& otherObject) override;
	//virtual bool bombCollide(Bombs& otherobject) = 0;
	//virtual bool playerCollide(Player& otherObject) = 0;
	~Door() = default;
};