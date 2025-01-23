#include "UpdateableObject.h"
#include <iostream>


UpdateableObject::UpdateableObject()
	: GameObject()
{}
UpdateableObject::UpdateableObject(sf::Vector2f position, const sf::Texture& texture, float CELL_WIDTH, float CELL_HEIGHT)
	: GameObject(texture, position, CELL_WIDTH, CELL_HEIGHT), m_starting_position(position.x + CELL_WIDTH / 2, position.y + CELL_HEIGHT / 2)
{}
UpdateableObject::UpdateableObject(const sf::Texture& texture, sf::Vector2f position)
	: GameObject(texture, position)
{}

sf::Vector2f UpdateableObject::getStartingPosition(sf::Vector2f position) const
{
	return m_starting_position;
}

bool UpdateableObject::checkCollision(GameObject & otherObject)
{
	if (getBounds().intersects(otherObject.getBounds()))
	{
		return true;
	}
	return false;
}

void UpdateableObject::setPrevLocation(sf::Vector2f position)
{
	m_prev_location = position;
}
sf::Vector2f UpdateableObject::getPrevLocation() const
{
	return m_prev_location;
}