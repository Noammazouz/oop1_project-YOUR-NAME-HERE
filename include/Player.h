#pragma once
#include "UpdateableObject.h"

class Player : public UpdateableObject
{
public:
	Player(sf::Vector2f position);
	void update() override;
	~Player() = default ;
private:
	sf::Vector2f m_position;
};