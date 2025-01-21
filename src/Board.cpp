#include "Board.h"
#include "ResourcesManager.h"
#include <fstream>
#include "Guard.h"
#include "Player.h"
#include "Rock.h"
#include "Wall.h"
#include "Door.h"

//// Define the variables here
//float CELL_WIDTH = 0;
//float CELL_HEIGHT = 0;

Board::Board()
{}

//-----------------------
void Board::loadLevel()
{
	m_level.clear();
	auto line = std::string();
	std::string currFileName = std::string("Level") + std::to_string(1) + ".txt";
	std::ifstream file(currFileName);

	if (!file)
	{
		std::cout << "You are the best! You beat me!" << std::endl;
		//return END_GAME;
	}

	while (std::getline(file, line))
	{
		m_level.push_back(line);
	}

	m_rows = static_cast<int>(m_level.size());
	m_cols = static_cast<int>(m_level[m_rows - 1].size());

	//return currStage;
}
//-------------------------
void Board::LoadBoard(std::vector<std::unique_ptr<UpdateableObject>>& m_movingObj
						, std::vector<std::unique_ptr<StaticObject>>& m_staticObj)
{
	float frameWidth = WIDTH * 0.8f; 
	float frameHeight = HEIGHT * 0.8f * 1.2;
	const float CELL_WIDTH = frameWidth / m_cols;
	const float CELL_HEIGHT = frameHeight / m_rows;

	sf::Sprite pic;
	ResourcesManager& resources = ResourcesManager::getInstance();

	for (int row = 0; row < m_rows; row++)
	{
		for (int col = 0; col < m_cols; col++)
		{
			switch (m_level[row][col])
			{
			case 'D': // Door
				m_staticObj.push_back(std::make_unique<Door>(sf::Vector2f(BOARD_STARTING_X + col * CELL_WIDTH, row * CELL_HEIGHT), resources.getTexture("door"), CELL_WIDTH, CELL_HEIGHT));
				break;
			case '/': // Player
				m_movingObj.push_back(std::make_unique<Player>(sf::Vector2f(BOARD_STARTING_X + col * CELL_WIDTH, row * CELL_HEIGHT), resources.getTexture("player"), CELL_WIDTH, CELL_HEIGHT));
				break;
			case '#': // Wall
				m_staticObj.push_back(std::make_unique<Wall>(sf::Vector2f(BOARD_STARTING_X + col * CELL_WIDTH, row * CELL_HEIGHT), resources.getTexture("wall"), CELL_WIDTH, CELL_HEIGHT));
				break;
			case '@': // Rock
				m_staticObj.push_back(std::make_unique<Rock>(sf::Vector2f(BOARD_STARTING_X + col * CELL_WIDTH, row * CELL_HEIGHT), resources.getTexture("rock"), CELL_WIDTH, CELL_HEIGHT));
				break;
			case '!': // Guard
				m_movingObj.push_back(std::make_unique<Guard>(sf::Vector2f(BOARD_STARTING_X + col * CELL_WIDTH, row * CELL_HEIGHT), resources.getTexture("guard"), CELL_WIDTH, CELL_HEIGHT));
				break;
			}
		}
	}
}