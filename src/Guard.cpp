#include "Guard.h"


Guard::Guard(sf::Vector2f position, const sf::Texture& texture, float CELL_WIDTH, float CELL_HEIGHT)
	: UpdateableObject(position, texture, CELL_WIDTH, CELL_HEIGHT)
{
}


void Guard::update(sf::Keyboard::Key key, sf::Vector2f position)
{
	/*float yDistance = this->getPosition().x - position.x;
	float xDistance = this->getPosition().y - position.y;

    if (std::abs(yDistance) > std::abs(xDistance))
    {
        if (yDistance > 0)
        {
            m_direction = sf::Vector2f(0, -1);
        }
        else
        {
            m_direction = sf::Vector2f(0, 1);
        }
    }
    else
    {
        if (xDistance > 0)
        {
            m_direction = sf::Vector2f(-1, 0);
        }
        else
        {
            m_direction = sf::Vector2f(1, 0);;
        }
    }*/
}

void Guard::setDirection(sf::Vector2f position)
{
    float yDistance = this->getPosition().x - position.x;
    float xDistance = this->getPosition().y - position.y;

    if (std::abs(yDistance) > std::abs(xDistance))
    {
        if (yDistance > 0)
        {
            m_direction = sf::Vector2f(0, -1);
        }
        else
        {
            m_direction = sf::Vector2f(0, 1);
        }
    }
    else
    {
        if (xDistance > 0)
        {
            m_direction = sf::Vector2f(-1, 0);
        }
        else
        {
            m_direction = sf::Vector2f(1, 0);;
        }
    }
}
