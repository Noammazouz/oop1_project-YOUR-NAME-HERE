#pragma once
#include "UpdateableObject.h"

class Guard : public UpdateableObject
{
public:
	Guard(sf::Vector2f position, const sf::Texture& texture, float CELL_WIDTH, float CELL_HEIGHT);
	void update(sf::Keyboard::Key key, sf::Vector2f position) override;
	void setDirection(sf::Vector2f position);

private:
	sf::Vector2f m_direction;
};