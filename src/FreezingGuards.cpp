#include "FreezingGuards.h"
#include "Player.h"

FreezingGuards::FreezingGuards(sf::Vector2f position, const sf::Texture& texture, float CELL_WIDTH, float CELL_HEIGHT)
	: StaticObject(position, texture, CELL_WIDTH, CELL_HEIGHT)
{}
//--------------------------------
void FreezingGuards::collide(GameObject& /*otherObject*/)
{
}
//------------------------------------------
void FreezingGuards::guardCollide(Guard& /*otherObject*/)
{
}
//------------------------------------------
void FreezingGuards::playerCollide(Player& otherObject)
{
	otherObject.setPresent(FREEZE);
	this->setLife(true);
}
//-------------------------------------
void FreezingGuards::explosionCollide(Explosion& /*otherobject*/)
{
	this->setLife(true);
}