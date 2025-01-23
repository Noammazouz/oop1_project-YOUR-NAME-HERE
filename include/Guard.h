#pragma once
#include "UpdateableObject.h"

class Guard : public UpdateableObject
{
public:
	Guard(sf::Vector2f position, const sf::Texture& texture, float CELL_WIDTH, float CELL_HEIGHT);
	void update(sf::Time deltaTime) override;
	void setDirection(sf::Vector2f position) override;
	//virtual void staticCollide(GameObject& otherObject) = 0;
	//virtual void updateableCollide(GameObject& otherObject) = 0;
	//virtual bool doorCollide(Door& otherObject) = 0;
	//virtual bool wallCollide(Wall& otherobject) = 0;
	//virtual bool guardCollide(Guard& otherObject) = 0;
	//virtual bool bombCollide(Bombs& otherobject) = 0;
	//virtual bool playerCollide(Player& otherObject) = 0;
private:
	sf::Vector2f m_direction;
	sf::Vector2f m_prevlocation;
	bool m_isAlive = true;
};