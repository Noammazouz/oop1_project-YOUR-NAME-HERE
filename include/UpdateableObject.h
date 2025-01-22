#pragma once

#include "GameObject.h"


class UpdateableObject : public GameObject
{
public:
	UpdateableObject();
	UpdateableObject(sf::Vector2f position, const sf::Texture& texture, float CELL_WIDTH, float CELL_HEIGHT);
	virtual void update(sf::Time deltaTime) = 0;
	virtual void setDirection(sf::Vector2f position) = 0;
	virtual ~UpdateableObject() = default;
};
