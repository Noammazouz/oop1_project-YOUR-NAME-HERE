#pragma once
#include "UpdateableObject.h"

class GameObject;

class Player : public UpdateableObject
{
public:
	Player();
	Player(sf::Vector2f position, const sf::Texture& texture, float CELL_WIDTH, float CELL_HEIGHT);
	void update(sf::Time deltaTime) override;
	void setDirectionFromKeyboard(sf::Keyboard::Key key);
	void setDirection(sf::Vector2f position) override;
	virtual void collide(GameObject& otherObject) override;
	virtual void guardCollide(Guard& otherObject) override;

	void decLife();
	int getLife() const;
	~Player() = default ;
private:
	sf::Vector2f m_direction;
	int m_lives = NUM_OF_LIVES;
};