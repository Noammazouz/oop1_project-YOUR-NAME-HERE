#pragma once

#include <vector> 
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
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
	void drawWindow();
	void move(sf::Clock& clock, sf::Time& timer);
	void handleCollision();
	void setbomb();
	void handleErasing();
	void explosion();
	void calculateScore();
	void setExpoDirection(int index);
	void resetLevel();
	void checkExpo();
	void checkVaildDraw();
	void handleLoadingLevel(sf::Time& timer, sf::Clock& clock);
	void handleMusicTransition(bool toGameplay);
	void handleMuting();
	void handleSocreboard(const sf::Time& timer);
	//to make the freezing guard
	//to make the removing guard
	// to make the add time for game
	sf::RenderWindow m_window;

	Board m_board;
	Player m_player;
	Menu m_menu;
	Scoreboard m_scoreboard;

	int m_level;
	bool m_inGameplay = false;
	std::vector<std::unique_ptr<UpdateableObject>> m_movingObj;
	std::vector<std::unique_ptr<StaticObject>> m_staticObj;
};
