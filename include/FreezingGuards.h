#pragma once

#include <SFML/Graphics.hpp>
#include "StaticObject.h"


class FreezingGuards : public StaticObject
{
public:
	FreezingGuards(sf::Vector2f position, const sf::Texture& texture, float CELL_WIDTH, float CELL_HEIGHT);

	virtual void collide(GameObject& otherObject) override;
	virtual void guardCollide(Guard& otherObject) override;
	virtual void playerCollide(Player& otherObject) override;
	virtual void explosionCollide(Explosion& otherobject) override;

	~FreezingGuards() = default;
};


