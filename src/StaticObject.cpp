#include "StaticObject.h"

StaticObject::StaticObject(sf::Vector2f position, const sf::Texture& texture, float CELL_WIDTH, float CELL_HEIGHT)
	: GameObject(texture, position, CELL_WIDTH, CELL_HEIGHT)
{}
//-------------------------------------
StaticObject::StaticObject()
	: GameObject()
{}