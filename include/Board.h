#pragma once 
#include "Tile.h"
#include <iostream>
#include <vector>
#include <string>


class Board
{
public:
	Board();
	void LoadBoard(const std::vector <sf::Texture>& textures, int index[]);
	void loadLevel();


private:
	std::vector<std::vector<Tile>> m_board;
	std::vector<std::string> m_level;
	bool m_isBoardExist = false;
	int m_rows;
	int m_cols;
};