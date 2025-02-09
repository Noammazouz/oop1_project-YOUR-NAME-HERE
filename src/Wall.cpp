#include "Wall.h"
#include "Player.h"
#include "Guard.h"
#include "Explosion.h"

Wall::Wall(sf::Vector2f position, const sf::Texture& texture, float CELL_WIDTH, float CELL_HEIGHT)
	: StaticObject(position, texture, CELL_WIDTH, CELL_HEIGHT)
{
}
//-------------------------------------
void Wall::playerCollide(Player& player)
{
	player.setPosition(player.getPrevLocation());
}
//-------------------------------------
void Wall::guardCollide(Guard& otherObject)
{
	otherObject.setPosition(otherObject.getPrevLocation());
}
//-------------------------------------
void  Wall::collide(GameObject& /*otherObject*/)
{
}
//-------------------------------------
void  Wall::explosionCollide(Explosion& otherobject)
{
	otherobject.setLife(true);
}