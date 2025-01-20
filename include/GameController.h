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


class GameController
{
public:
	GameController();
	void newGame();
private:

	void runLevel();
	void drawWindow(sf::RenderWindow& window);
	Board m_board;
	std::vector<std::unique_ptr<UpdateableObject>> m_movingObj;
	std::vector<std::unique_ptr<StaticObject>> m_staticObj;
};
