#include "GameObject.h"
#include <iostream>

GameObject::GameObject()
	: m_position(0,0)
{
}
GameObject::GameObject(const sf::Texture& texture, sf::Vector2f pos, float CELL_WIDTH, float CELL_HEIGHT)
	: m_position(pos.x + CELL_WIDTH / 2, pos.y + CELL_HEIGHT / 2)
{
	setTexture(texture);
	m_pic.setScale(CELL_WIDTH / m_pic.getTexture()->getSize().x, CELL_HEIGHT / m_pic.getTexture()->getSize().y);
	m_pic.setOrigin(static_cast<float>(m_pic.getTexture()->getSize().x) / 2.0f, static_cast<float>(m_pic.getTexture()->getSize().y) / 2.0f);
	m_pic.setPosition(m_position);
	m_limits[0] = static_cast<float>(CELL_WIDTH / 2);
	m_limits[1] = static_cast<float>(CELL_HEIGHT / 2);
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

void GameObject::move(sf::Vector2f direction)
{
	float left_corner = direction.x + m_position.x - m_limits[0];
	float bottom_corner = direction.y + m_position.y + m_limits[1];
	float up_corner = direction.y + m_position.y - m_limits[1];
	float right_corner = direction.x + m_position.x + m_limits[0];

	if (left_corner > BOARD_STARTING_X && up_corner > 0 && bottom_corner < HEIGHT && right_corner < WIDTH)
	{
		m_position += direction;
		m_pic.move(direction);
	}
}