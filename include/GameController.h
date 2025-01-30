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
#include "Scoreboard.h"
#include "Explosion.h"

class GameController
{
public:
	GameController();
	void newGame();
private:

	void runLevel();
	void drawWindow(sf::RenderWindow& window);
	void move(sf::Clock& clock, sf::Time& timer);
	void handleCollision();
	void setbomb();
	void handleErasing();
	void explosion(sf::RenderWindow& window);
	void calculateScore();
	void setExpoDirection(int index);
	void resetGuardPos();
	void checkExpo();
	void checkVaildDraw();
	//to make the freezing guard
	//to make the removing guard
	// to make the add time for game

	Board m_board;
	Player m_player;
	Menu m_menu;
	Scoreboard m_scoreboard;
	int m_level;
	std::vector<std::unique_ptr<UpdateableObject>> m_movingObj;
	std::vector<std::unique_ptr<StaticObject>> m_staticObj;
};
