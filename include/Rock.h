#pragma once
#include "StaticObject.h"

class Rock : public StaticObject
{
public:
	Rock(sf::Vector2f position, const sf::Texture& texture, float CELL_WIDTH, float CELL_HEIGHT);
	virtual void collide(GameObject& otherObject) {};
	//virtual bool doorCollide(Door& otherObject) = 0;
	//virtual bool wallCollide(Wall& otherobject) = 0;
	virtual void guardCollide(Guard& otherObject) override;
	//virtual bool bombCollide(Bombs& otherobject) = 0;
	virtual void playerCollide(Player& otherObject) override;
	~Rock() = default;
};