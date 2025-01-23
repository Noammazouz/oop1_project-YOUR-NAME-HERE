#include "UpdateableObject.h"



UpdateableObject::UpdateableObject()
	: GameObject()
{}
UpdateableObject::UpdateableObject(sf::Vector2f position, const sf::Texture& texture, float CELL_WIDTH, float CELL_HEIGHT)
	: GameObject(texture, position, CELL_WIDTH, CELL_HEIGHT), m_starting_position(position.x + CELL_WIDTH / 2, position.y + CELL_HEIGHT / 2)
{}
UpdateableObject::UpdateableObject(const sf::Texture& texture, sf::Vector2f position)
	: GameObject(texture, position)
{}

sf::Vector2f UpdateableObject::getStartingPosition(sf::Vector2f position) const
{
	return m_starting_position;
}

void UpdateableObject::move(sf::Vector2f direction)
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