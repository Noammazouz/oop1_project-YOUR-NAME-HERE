#include "Player.h"
#include <iostream>


Player::Player()
{
}

Player::Player(sf::Vector2f position, const sf::Texture& texture, float CELL_WIDTH, float CELL_HEIGHT)
	: UpdateableObject(position, texture, CELL_WIDTH, CELL_HEIGHT)
{
}
void Player::setDirectionFromKeyboard(sf::Keyboard::Key key)
{
	switch (key)
	{
	case sf::Keyboard::Key::Space:
		 m_direction = sf::Vector2f(0, 0); 
		 break;
    case sf::Keyboard::Key::Left:
		 m_direction = sf::Vector2f(-1, 0); 
		 break;
    case sf::Keyboard::Key::Down:
		 m_direction = sf::Vector2f(0, 1); 
		 break;
	case sf::Keyboard::Key::Right:
		m_direction = sf::Vector2f(1, 0);
		break;
	case sf::Keyboard::Key::Up:
		m_direction = sf::Vector2f(0, -1);
		break;
	}
}

void Player::update(sf::Time deltaTime)
{
	m_prevlocation = this->getPosition();
	this->updatePosition(m_direction * SPEED * deltaTime.asSeconds());
}

void Player::setDirection(sf::Vector2f position)
{}

void Player::staticCollide(GameObject& otherObject)
{
	otherObject.playerCollide(*this);
}