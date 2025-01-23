#pragma once
#include "StaticObject.h"

class Wall : public StaticObject
{
public:
	Wall(sf::Vector2f position, const sf::Texture& texture, float CELL_WIDTH, float CELL_HEIGHT);

	~Wall() = default;
};