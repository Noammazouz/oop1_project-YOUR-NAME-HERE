#include "Bombs.h"
#include <iostream>


Bombs::Bombs(sf::Vector2f position, const sf::Texture& texture)
    : UpdateableObject(position, texture, 32.f, 32.f), m_timer(sf::seconds(4))
{
    this->setID(BOMBS);
}

void Bombs::update(sf::Time deltaTime)
{
    m_timer-=deltaTime;
    if (m_timer.asSeconds() <= 0.f)
    {
        this->setLife(true);
    }
}

void Bombs::collide(GameObject& otherobject)
{
    otherobject.bombCollide(*this);
}
