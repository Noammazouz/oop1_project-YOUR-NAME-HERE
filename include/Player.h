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
	virtual void staticCollide(GameObject& otherObject) override;
	//virtual void updateableCollide(GameObject& otherObject) override;
	//virtual bool doorCollide(Door& otherObject) override;
	//virtual bool wallCollide(Wall& otherobject) override;
	//virtual bool guardCollide(Guard& otherObject) override;
	//virtual bool bombCollide(Bombs& otherobject) override;
	virtual ReturnType playerCollide(Player& otherObject) override { return DOOR; };  //CHANGE THIS ITS NOT SUPPOSED TO BE EMPTY
	~Player() = default ;
private:
	sf::Vector2f m_direction;
	sf::Vector2f m_prevlocation;
	int m_lives = 3;
	int m_score = 0;
};