#include "GameObject.h"
#include <iostream>

GameObject::GameObject()
	: m_position(0,0)
{
}
GameObject::GameObject(const sf::Texture& texture, sf::Vector2f pos, float CELL_WIDTH, float CELL_HEIGHT)
	: m_position(pos)
{
	setTexture(texture);
	m_pic.setScale(CELL_WIDTH / m_pic.getTexture()->getSize().x, CELL_HEIGHT / m_pic.getTexture()->getSize().y);
	m_pic.setPosition(m_position);
}
void GameObject::draw(sf::RenderWindow& window)
{
	window.draw(m_pic);
}

void GameObject::setTexture(const sf::Texture& texture)
{
	m_pic.setTexture(texture);
}

sf::Vector2f GameObject::getPosition() const
{
	return m_position;
}

void GameObject::setPosition(const sf::Vector2f position)
{
	m_position = position;
}