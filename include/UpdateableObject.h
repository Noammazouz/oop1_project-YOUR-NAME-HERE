#pragma once

#include "GameObject.h"


class UpdateableObject : public GameObject
{
public:
	UpdateableObject();
	UpdateableObject(sf::Vector2f position, const sf::Texture& texture, float CELL_WIDTH, float CELL_HEIGHT);
	virtual sf::Vector2f getStartingPosition() const;
	virtual void update(sf::Time deltaTime) = 0;
	virtual void setDirection(sf::Vector2f position) = 0;
	virtual ~UpdateableObject() = default;
	virtual bool checkCollision(GameObject& otherObject);
	sf::Vector2f getPrevLocation() const;

	virtual sf::Time getTimer() const;

	virtual bool getExpo() const;

protected:
	void setPrevLocation(sf::Vector2f position);
private:
	sf::Vector2f m_starting_position;
	sf::Vector2f m_prev_location;
};
