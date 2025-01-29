#include "GameObject.h"
#include <iostream>

GameObject::GameObject()
	: m_cell_size{0,0}
{
}
GameObject::GameObject(const sf::Texture& texture, sf::Vector2f pos, float CELL_WIDTH, float CELL_HEIGHT)
	: m_cell_size{CELL_WIDTH / 2, CELL_HEIGHT / 2}, m_pic(texture)
{
	sf::Vector2f postion;
	postion = sf::Vector2f(pos.x + CELL_WIDTH / 2, pos.y + CELL_HEIGHT / 2);
	setSprite(postion);
}
void GameObject::draw(sf::RenderWindow& window)
{
	window.draw(m_pic);
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

void GameObject::updatePosition(sf::Vector2f direction)
{
	float left_corner = direction.x + m_pic.getPosition().x - m_cell_size[0];
	float bottom_corner = direction.y + m_pic.getPosition().y + m_cell_size[1];
	float up_corner = direction.y + m_pic.getPosition().y - m_cell_size[1];
	float right_corner = direction.x + m_pic.getPosition().x + m_cell_size[0];

	

	if (left_corner > BOARD_STARTING_X && up_corner > 0 && bottom_corner < HEIGHT && right_corner < WIDTH)
	{
		m_pic.move(direction);
	}
}

sf::FloatRect GameObject::getBounds() const
{
	return m_pic.getGlobalBounds();
}

void GameObject::setPosition(const sf::Vector2f& position)
{
	m_pic.setPosition(position);
}

void GameObject::setLife(const bool life)
{
	m_is_dead = life;
}

bool GameObject::isDead() const
{
	return m_is_dead;
}

void  GameObject::mirrorImage(sf::Vector2f direction)
{
	if (direction.x < 0 && m_facingRight)
	{
		m_pic.scale(-1, 1);
		m_facingRight = false;
	}
	else if(direction.x > 0 && !m_facingRight)
	{
		m_pic.scale(-1, 1);
		m_facingRight = true;
	}
}

void GameObject::playerCollide(Player& /*otherObject*/)
{
}

void  GameObject::bombCollide(Bombs& /*otherobject*/)
{
}