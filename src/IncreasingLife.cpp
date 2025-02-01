#include "IncreasingLife.h"
#include "Player.h"
#include <iostream>

IncreasingLife::IncreasingLife(sf::Vector2f position, const sf::Texture& texture, float CELL_WIDTH, float CELL_HEIGHT)
	: StaticObject(position, texture, CELL_WIDTH, CELL_HEIGHT)
{}
//--------------------------------
void IncreasingLife::collide(GameObject& /*otherObject*/)
{
}
void IncreasingLife::guardCollide(Guard& /*otherObject*/)
{
}
//------------------------------------------
void IncreasingLife::playerCollide(Player& otherObject)
{
	otherObject.incLife();
	this->setLife(true);
}