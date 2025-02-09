#include "Explosion.h"
#include <iostream>

Explosion::Explosion(sf::Vector2f position, const sf::Texture& texture)
	: UpdateableObject(sf::Vector2f(position.x - DEFUALT_WIDTH / 2, position.y - DEFUALT_WIDTH / 2), texture, DEFUALT_WIDTH, DEFUALT_HEIGHT), m_explosion(texture), m_timeToLive(sf::seconds(0.5))
{
}
//-------------------------------------
void Explosion::update(sf::Time deltaTime)
{
	m_timeToLive -= deltaTime;
	if (m_timeToLive.asSeconds() <= 0.f)
	{
		this->setLife(true);
	}
}
//-------------------------------------
void Explosion::collide(GameObject& otherObject)
{
	otherObject.explosionCollide(*this);
}
//-------------------------------------
void Explosion::guardCollide(Guard& /*otherObject*/)
{
}
//-------------------------------------
void Explosion::setDirection(sf::Vector2f position)
{
	this->updatePosition(position);
}