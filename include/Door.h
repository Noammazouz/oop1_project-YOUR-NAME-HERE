#pragma once
#include "StaticObject.h"

class Door : public StaticObject
{
public:
	Door(sf::Vector2f position, const sf::Texture& texture, float CELL_WIDTH, float CELL_HEIGH);

	~Door() = default;
private:
	sf::Vector2f m_position;
};