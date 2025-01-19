#include "Tile.h"

Tile::Tile(sf::Sprite base_pic)
    : m_pic(base_pic), m_location(sf::Vector2f(0, 0)), m_size(0, 0)
{

}

void Tile::setLocation(int col_size, int row_size, const float TILE_SIZE_X, const float TILE_SIZE_Y)
{
    m_location.x = float(BOARD_STARTING_X + (TILE_SIZE_X * col_size));
    m_location.y = float(BOARD_STARTING_Y + (TILE_SIZE_Y * row_size));
    m_size.x = TILE_SIZE_X;
    m_size.y = TILE_SIZE_Y;
}

sf::RectangleShape Tile::makeRectangle() const
{
    sf::RectangleShape shape;

    shape.setSize(m_size);
    shape.setOutlineThickness(3);
    shape.setPosition(m_location);
    shape.setOutlineColor(sf::Color::Black);
    shape.setTexture(m_texture);

    return shape;
}

sf::Vector2f Tile::getLocation() const
{
    return m_location;
}

sf::Vector2f Tile::getSize() const
{
    return m_size;
}

void Tile::setSprite(const sf::Sprite& curr_pic)
{
    m_pic = curr_pic;
}


const sf::Sprite& Tile::getSprite() const
{
    return m_pic;
}