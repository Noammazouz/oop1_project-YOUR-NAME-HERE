#pragma once

#include "GameObject.h"


class UpdateableObject : public GameObject
{
public:
	UpdateableObject();
	UpdateableObject(sf::Vector2f position, const sf::Texture& texture, float CELL_WIDTH, float CELL_HEIGHT);
	virtual void update() = 0;

	virtual ~UpdateableObject() = default;
private:
};
