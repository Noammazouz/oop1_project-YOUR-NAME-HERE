#include "GameObject.h"
#include <iostream>

GameObject::GameObject()
	: m_cell_size{0,0}
{
}
GameObject::GameObject(const sf::Texture& texture, sf::Vector2f pos, float CELL_WIDTH, float CELL_HEIGHT)
	: m_cell_size{CELL_WIDTH / 2, CELL_HEIGHT / 2}
{
	sf::Vector2f postion;
	postion = sf::Vector2f(pos.x + CELL_WIDTH / 2, pos.y + CELL_HEIGHT / 2);
	setTexture(texture);
	setSprite(postion);
}
GameObject::GameObject(const sf::Texture& texture, sf::Vector2f pos)
{
	setTexture(texture);
	setSprite(pos);
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
	return m_pic.getPosition();
}

void GameObject::setSprite(sf::Vector2f pos)
{
	m_pic.setScale((m_cell_size[0] * 2) / m_pic.getTexture()->getSize().x, (m_cell_size[1] * 2) / m_pic.getTexture()->getSize().y);
	m_pic.setOrigin(static_cast<float>(m_pic.getTexture()->getSize().x) / 2.0f, static_cast<float>(m_pic.getTexture()->getSize().y) / 2.0f);
	m_pic.setPosition(pos);
}