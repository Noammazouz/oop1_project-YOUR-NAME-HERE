#pragma once
#include "StaticObject.h"

class Door : public StaticObject
{
public:
	Door(sf::Vector2f position, const sf::Texture& texture, float CELL_WIDTH, float CELL_HEIGHT);

	virtual void collide(GameObject& otherObject) override;
	virtual void guardCollide(Guard& otherObject) override;
	virtual void playerCollide(Player& otherObject) override;

	~Door() = default;
};