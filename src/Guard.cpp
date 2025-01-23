#include "Guard.h"
#include <iostream>

Guard::Guard(sf::Vector2f position, const sf::Texture& texture, float CELL_WIDTH, float CELL_HEIGHT)
	: UpdateableObject(position, texture, CELL_WIDTH, CELL_HEIGHT)
{
}


void Guard::update(sf::Time deltaTime)
{
    this->updatePosition(m_direction * (SPEED / 2) * deltaTime.asSeconds());
}

void Guard::setDirection(sf::Vector2f position)
{
    float xDistance = this->getPosition().x - position.x;
    float yDistance = this->getPosition().y - position.y;

    if (std::abs(yDistance) > std::abs(xDistance))
    {
        if (yDistance > 0)
        {
			m_direction = sf::Vector2f(0, -1);//up
        }
        else
        {
			m_direction = sf::Vector2f(0, 1);//down
        }
    }
    else
    {
        if (xDistance > 0)
        {
			m_direction = sf::Vector2f(-1, 0); //left
        }
        else
        {
			m_direction = sf::Vector2f(1, 0); //right
        }
    }
}
