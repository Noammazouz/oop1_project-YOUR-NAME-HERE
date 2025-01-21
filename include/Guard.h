#pragma once
#include "UpdateableObject.h"

class Guard : public UpdateableObject
{
public:
	Guard(sf::Vector2f position, const sf::Texture& texture, float CELL_WIDTH, float CELL_HEIGHT);
	void update() override;

private:
	sf::Vector2f m_position;
};