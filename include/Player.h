#pragma once
#include "UpdateableObject.h"

class Player : public UpdateableObject
{
public:
	Player(sf::Vector2f position, const sf::Texture& texture, float CELL_WIDTH, float CELL_HEIGHT);
	void update(sf::Keyboard::Key key, sf::Vector2f position) override;
	void setDirection(sf::Keyboard::Key key);
	~Player() = default ;
private:
	sf::Vector2f m_direction;
};