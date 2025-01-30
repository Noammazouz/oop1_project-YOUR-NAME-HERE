#include "Guard.h"
#include <iostream>
#include "Player.h"

Guard::Guard(sf::Vector2f position, const sf::Texture& texture, float CELL_WIDTH, float CELL_HEIGHT)
	: UpdateableObject(position, texture, CELL_WIDTH, CELL_HEIGHT)
{
    //this->setID(GUARD);
	m_num_of_guards++;
	m_num_of_guards_alive++;
}


void Guard::update(sf::Time deltaTime)
{
    this->setPrevLocation(this->getPosition());
    this->updatePosition(m_direction * SPEED * deltaTime.asSeconds());
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

void Guard::collide(GameObject& otherObject)
{
    otherObject.guardCollide(*this);
}

void Guard::guardCollide(Guard& otherObject)
{
	this->setPosition(this->getPrevLocation());
}

void Guard::bombCollide(Bombs& otherobject)
{
    this->setLife(true);
}
Guard::~Guard()
{
	m_num_of_guards_alive--;

}
void Guard::resetNumOfGuards()
{
	m_num_of_guards = 0;
	m_num_of_guards_alive = 0;
}
int Guard::getNumOfStartingGuards()
{
	return m_num_of_guards;

}
int Guard::getNumOfGuardsAlive()
{
	return m_num_of_guards_alive;
}

void Guard::playerCollide(Player& otherObject)
{
	otherObject.setPosition(otherObject.getStartingPosition());
}
int Guard::m_num_of_guards_alive = 0;
int Guard::m_num_of_guards = 0;
