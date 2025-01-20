#pragma once 
#include "Tile.h"
#include <iostream>
#include <vector>
#include <string>
#include "Const.h"
#include "UpdateableObject.h"
#include "StaticObject.h"

class Board
{
public:
	Board();
	void LoadBoard(std::vector<std::unique_ptr<UpdateableObject>>& m_movingObj
		, std::vector<std::unique_ptr<StaticObject>>& m_staticObj);
	void loadLevel();

private:
	std::vector<std::string> m_level;
	int m_rows;
	int m_cols;
};