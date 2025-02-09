#include "UpdateableObject.h"
#include <iostream>


UpdateableObject::UpdateableObject()
	: GameObject()
{}
//-------------------------------------
UpdateableObject::UpdateableObject(sf::Vector2f position, const sf::Texture& texture, float CELL_WIDTH, float CELL_HEIGHT)
	: GameObject(texture, position, CELL_WIDTH, CELL_HEIGHT), m_starting_position(position.x + CELL_WIDTH / 2, position.y + CELL_HEIGHT / 2)
{}
//-------------------------------------
sf::Vector2f UpdateableObject::getStartingPosition() const
{
	return m_starting_position;
}
//-------------------------------------
bool UpdateableObject::checkCollision(GameObject & otherObject)
{
	if (getBounds().intersects(otherObject.getBounds()))
	{
		return true;
	}
	return false;
}
//-------------------------------------
void UpdateableObject::setPrevLocation(sf::Vector2f position)
{
	m_prev_location = position;
}
//-------------------------------------
sf::Vector2f UpdateableObject::getPrevLocation() const
{
	return m_prev_location;
}
//-------------------------------------
sf::Time UpdateableObject::getTimer() const
{
	return sf::Time (sf::seconds(0));
}
//-------------------------------------
bool UpdateableObject::getExpo() const
{
	return false;
}
//-------------------------
void  UpdateableObject::setFreezing(bool /*freeze*/)
{
}