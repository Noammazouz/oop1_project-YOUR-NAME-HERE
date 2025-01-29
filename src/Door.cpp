#include "Door.h"

Door::Door(sf::Vector2f position, const sf::Texture& texture, float CELL_WIDTH, float CELL_HEIGHT)
	: StaticObject(position, texture, CELL_WIDTH, CELL_HEIGHT)
{}

void Door::collide(GameObject& /*otherObject*/)
{
}
void Door::guardCollide(Guard& /*otherObject*/)
{
}