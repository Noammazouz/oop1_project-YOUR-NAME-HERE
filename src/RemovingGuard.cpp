#include "RemovingGuard.h"
#include "Player.h"
#include <iostream>

RemovingGuard::RemovingGuard(sf::Vector2f position, const sf::Texture& texture, float CELL_WIDTH, float CELL_HEIGHT)
	: StaticObject(position, texture, CELL_WIDTH, CELL_HEIGHT)
{}
//--------------------------------
void RemovingGuard::collide(GameObject& /*otherObject*/)
{
}
void RemovingGuard::guardCollide(Guard& /*otherObject*/)
{
}
//------------------------------------------
void RemovingGuard::playerCollide(Player& otherObject)
{
	otherObject.setPresent(KILL);
	this->setLife(true);
}
//-------------------------------------
void RemovingGuard::explosionCollide(Explosion& /*otherobject*/)
{
	this->setLife(true);
}