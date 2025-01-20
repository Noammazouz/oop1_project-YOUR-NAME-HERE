#include "Board.h"
#include "ResourcesManager.h"
#include <fstream>
#include "Guard.h"
#include "Player.h"
#include "Rock.h"
#include "Wall.h"
#include "Door.h"

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

	m_rows = static_cast<int>(m_level.size()) - 1;
	m_cols = static_cast<int>(m_level[m_rows].size()) - 1;

	//return currStage;
}
//-------------------------
void Board::LoadBoard(sf::RenderWindow& window, std::vector<std::unique_ptr<UpdateableObject>>& m_movingObj
						, std::vector<std::unique_ptr<StaticObject>>& m_staticObj)
{
	sf::Sprite pic;
	ResourcesManager& resources = ResourcesManager::getInstance();
	int index = 0;
	for (int row = 0; row < m_rows; row++)
	{
		for (int col = 0; col < m_cols; col++)
		{
			
			switch (m_level[row][col])
			{
			case 'D': // Door
				m_staticObj.push_back(std::make_unique<Door>(sf::Vector2f(col * TILE_SIZE, row * TILE_SIZE)));
				/*pic.setTexture(resources.getTexture("door"));
				pic.setPosition(sf::Vector2f(col * TILE_SIZE, row * TILE_SIZE));*/
				break;
			case '/': // Player
				pic.setTexture(resources.getTexture("player"));
				m_movingObj.push_back(std::make_unique<Player>(sf::Vector2f(col * TILE_SIZE, row * TILE_SIZE)));
				break;
			case '#': // Wall
				pic.setTexture(resources.getTexture("wall"));
				m_staticObj.push_back(std::make_unique<Wall>(sf::Vector2f(col * TILE_SIZE, row * TILE_SIZE), resources.getTexture("wall")));
				std::cout << "in wall case: " << index << std::endl;
				++index;
				break;
			case '@': // Rock
				pic.setTexture(resources.getTexture("rock"));
				m_staticObj.push_back(std::make_unique<Rock>(sf::Vector2f(col * TILE_SIZE, row * TILE_SIZE), resources.getTexture("rock")));
				std::cout << "in rock case" << std::endl;
				break;
			case '!': // Guard
				pic.setTexture(resources.getTexture("guard"));
				m_movingObj.push_back(std::make_unique<Guard>(sf::Vector2f(col * TILE_SIZE, row * TILE_SIZE)));
				break;
			}
			std::cout << "locition: " << row << " " << col << std::endl;
			window.draw(pic);
		}
	}
	std::cout << "num of rows: " << m_rows << " num of cols: " << m_cols << std::endl;
}