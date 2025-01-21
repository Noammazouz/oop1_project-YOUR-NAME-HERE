#pragma once
#include "StaticObject.h"

class Rock : public StaticObject
{
public:
	Rock(sf::Vector2f position, const sf::Texture& texture, float CELL_WIDTH, float CELL_HEIGHT);

	~Rock() = default;
private:
	sf::Vector2f m_position;
};