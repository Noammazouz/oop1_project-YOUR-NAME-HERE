#pragma once

#include <vector> 
#include <string>
#include <SFML/Graphics.hpp>
#include "Board.h"
#include "Player.h"
#include "Bombs.h"
#include "Guard.h"
#include "ResourcesManager.h"
#include "Const.h"
#include "UpdateableObject.h"
#include "StaticObject.h"
#include "GameObject.h"
#include "Menu.h"


class GameController
{
public:
	GameController();
	void newGame();
private:

	void runLevel();
	void drawWindow(sf::RenderWindow& window);
	void move(sf::Clock& clock);
	void handleCollision();

	Board m_board;
	Player m_player;
	Menu m_menu;
	std::vector<std::unique_ptr<UpdateableObject>> m_movingObj;
	std::vector<std::unique_ptr<StaticObject>> m_staticObj;
};
