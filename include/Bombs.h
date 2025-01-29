#pragma once

#include "UpdateableObject.h"


class Bombs : public UpdateableObject
{
public:
	Bombs(sf::Vector2f position, const sf::Texture& texture);
	void update(sf::Time deltaTime) override;
	void setDirection(sf::Vector2f position) override;
  //	bool checkCollision(GameObject& otherObject) override { return false; };
	void collide(GameObject& otherObject) override;
	void guardCollide(Guard& otherObject) override;
	//virtual void staticCollide(GameObject& otherObject) = 0;
	//virtual void updateableCollide(GameObject& otherObject) = 0;
	//virtual bool doorCollide(Door& otherObject) = 0;
	//virtual bool wallCollide(Wall& otherobject) = 0;
	//virtual bool bombCollide(Bombs& otherobject) = 0;
	//virtual bool playerCollide(Player& otherObject) = 0;
private:
	sf::Time m_timer;
};

