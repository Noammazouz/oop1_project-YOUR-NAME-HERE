#include "UpdateableObject.h"



UpdateableObject::UpdateableObject()
	: GameObject()
{}
UpdateableObject::UpdateableObject(sf::Vector2f position, const sf::Texture& texture, float CELL_WIDTH, float CELL_HEIGHT)
	: GameObject(texture, position, CELL_WIDTH, CELL_HEIGHT)
{}
UpdateableObject::UpdateableObject(const sf::Texture& texture, sf::Vector2f position)
	: GameObject(texture, position)
{}