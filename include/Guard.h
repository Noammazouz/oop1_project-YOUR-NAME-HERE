#pragma once
#include "UpdateableObject.h"

class Guard : public UpdateableObject
{
public:
	Guard(sf::Vector2f position);
	void update() override;

private:
	sf::Vector2f m_position;
};