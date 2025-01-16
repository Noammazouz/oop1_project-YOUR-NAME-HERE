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


class GameController
{
public:
	GameController();
	void newGame();
private:

	void runLevel();
	void loadSprites();
	std::vector<sf::Sprite> m_sprite;
	//
};
