#pragma once
#include "UpdateableObject.h"

class Player : public UpdateableObject
{
public:
	Player();
	Player(sf::Vector2f position, const sf::Texture& texture, float CELL_WIDTH, float CELL_HEIGHT);
	void update(sf::Time deltaTime) override;
	void setDirectionFromKeyboard(sf::Keyboard::Key key);
	~Player() = default ;
private:
	sf::Vector2f m_direction;
};