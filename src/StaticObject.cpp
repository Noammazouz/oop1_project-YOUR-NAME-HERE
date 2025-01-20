#include "StaticObject.h"

StaticObject::StaticObject(sf::Vector2f position, const sf::Texture& texture)
	: GameObject(texture, position)
{}
StaticObject::StaticObject()
	: GameObject()
{}