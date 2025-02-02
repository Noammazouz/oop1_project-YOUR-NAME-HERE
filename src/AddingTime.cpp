#include "AddingTIme.h"
#include "Player.h"
#include <iostream>

AddingTime::AddingTime(sf::Vector2f position, const sf::Texture& texture, float CELL_WIDTH, float CELL_HEIGHT)
	: StaticObject(position, texture, CELL_WIDTH, CELL_HEIGHT)
{}
//--------------------------------
void AddingTime::collide(GameObject& /*otherObject*/)
{
}
void AddingTime::guardCollide(Guard& /*otherObject*/)
{
}
//------------------------------------------
void AddingTime::playerCollide(Player& otherObject)
{
	otherObject.setPresent(TIME);
	this->setLife(true);
}
//-------------------------------------
void AddingTime::explosionCollide(Explosion& /*otherobject*/)
{
	this->setLife(true);
}