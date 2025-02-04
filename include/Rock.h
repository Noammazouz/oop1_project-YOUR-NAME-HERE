#pragma once
#include "StaticObject.h"

class Rock : public StaticObject
{
public:
	Rock(sf::Vector2f position, const sf::Texture& texture, float CELL_WIDTH, float CELL_HEIGHT);

	virtual void collide(GameObject& otherObject) override;
	virtual void guardCollide(Guard& otherObject) override;
	virtual void explosionCollide(Explosion& otherobject) override;
	virtual void playerCollide(Player& otherObject) override;

	~Rock() = default;
};