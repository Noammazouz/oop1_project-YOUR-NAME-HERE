#pragma once
#include "UpdateableObject.h"

class Guard : public UpdateableObject
{
public:
	Guard(sf::Vector2f position, const sf::Texture& texture, float CELL_WIDTH, float CELL_HEIGHT);
	void update(sf::Time deltaTime) override;
	void setDirection(sf::Vector2f position) override;
	virtual void collide(GameObject& otherObject) override;
	//virtual bool doorCollide(Door& otherObject) = 0;
	//virtual bool wallCollide(Wall& otherobject) = 0;
	virtual void guardCollide(Guard& otherObject) override;
	virtual void bombCollide(Bombs& otherobject) override;
	virtual void playerCollide(Player& otherObject) override;
	static void resetNumOfGuards();
	static int getNumOfStartingGuards();
	static int getNumOfGuardsAlive();
	~Guard();
private:
	static int m_num_of_guards;
	static int m_num_of_guards_alive;
	sf::Vector2f m_direction;
	sf::Vector2f m_prevlocation;
};