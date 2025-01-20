#pragma once
#include "StaticObject.h"

class Door : public StaticObject
{
public:
	Door(sf::Vector2f position);

	~Door() = default;
private:
	sf::Vector2f m_position;
};