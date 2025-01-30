#include "Rock.h"
#include "Player.h"
#include "Guard.h"

Rock::Rock(sf::Vector2f position, const sf::Texture& texture, float CELL_WIDTH, float CELL_HEIGHT)
	: StaticObject(position, texture, CELL_WIDTH, CELL_HEIGHT)
{
}
//-------------------------------------
void Rock::playerCollide(Player& otherObject)
{
	otherObject.setPosition(otherObject.getPrevLocation());
}
//-------------------------------------
void Rock::guardCollide(Guard& otherObject)
{
	otherObject.setPosition(otherObject.getPrevLocation());
}
//-------------------------------------
void Rock::collide(GameObject& /*otherObject*/ )
{
}
//-------------------------------------
void Rock::explosionCollide(Explosion& otherobject)
{
	this->setLife(true);
}