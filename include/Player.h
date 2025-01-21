#pragma once
#include "UpdateableObject.h"

class Player : public UpdateableObject
{
public:
	Player(sf::Vector2f position, const sf::Texture& texture, float CELL_WIDTH, float CELL_HEIGHT);
	void update() override;
	~Player() = default ;
private:
	sf::Vector2f m_position;
};