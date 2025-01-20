#include "GameObject.h"
#include <iostream>

GameObject::GameObject()
	: m_position(0,0)
{
}
GameObject::GameObject(const sf::Texture texture, sf::Vector2f pos)
	: m_position(pos)
{
	//std::cout << m_position.x / 32 << " " << m_position.y / 32 << std::endl;
	setTexture(texture);
}
void GameObject::draw(sf::RenderWindow& window)
{
	window.draw(m_pic);
}

void GameObject::setTexture(const sf::Texture texture)
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