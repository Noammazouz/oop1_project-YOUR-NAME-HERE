#include "Bombs.h"
#include <iostream>


Bombs::Bombs(sf::Vector2f position, const sf::Texture& texture)
    : UpdateableObject(position, texture, 32.f, 32.f), m_timer(sf::seconds(4))
{
    //this->setID(BOMBS);
}

void Bombs::update(sf::Time deltaTime)
{
    m_timer-=deltaTime;
    if (m_timer.asSeconds() <= 0.f)
    {
		m_isExploded = true;
        this->setLife(true);
    }
}

void Bombs::collide(GameObject& otherobject)
{
    std::cout << "im here at collide at bombs.cpp" << std::endl;
    otherobject.bombCollide(*this);
}

void Bombs::setDirection(sf::Vector2f /*position*/)
{
}

void Bombs::guardCollide(Guard& /*otherObject*/)
{

}

sf::Time Bombs::getTimer() const
{
	return m_timer;
}

bool Bombs::getExpo() const
{
    return m_isExploded;
}