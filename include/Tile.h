#pragma once

#include "consts.h"
#include <SFML/Graphics.hpp>
#include <iostream>

class Tile
{
public:
	Tile();
	void setLocation(int col_size, int row_size, const float TILE_SIZE_X, const float TILE_SIZE_Y);
	sf::RectangleShape makeRectangle() const;
	sf::Vector2f getLocation() const;
	sf::Vector2f getSize() const;
	void setSprite(const sf::Sprite& curr_pic);
	const sf::Sprite& getSprite() const;


private:
	sf::Sprite m_pic;
	sf::Vector2f m_location, m_size;
};