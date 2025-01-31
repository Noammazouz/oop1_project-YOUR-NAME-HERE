#include "GameController.h"


GameController::GameController()
	: m_level(1), m_window(sf::VideoMode(WIDTH, HEIGHT), "level")
{
	//initializeMusic();
}
//-------------------------------------
void GameController::newGame()
{
	handleMusicTransition(false);
	m_menu.draw();
	runLevel();
}
//---------
void GameController::runLevel()
{
	//auto window = sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), "level");
	//m_movingObj.clear();
	//m_staticObj.clear();
	//if (m_board.loadLevel(m_level) == END_GAME)
	//{
	//	//make the end game
	//}
	//Guard::resetNumOfGuards();
	//m_board.LoadBoard(m_movingObj, m_staticObj, m_player);
	handleMusicTransition(true);
	m_scoreboard.updateScore(0);
	sf::Time timer;
	sf::Clock clock;
	handleLoadingLevel(timer, clock);

	while (m_window.isOpen())
	{
		m_window.clear();

		drawWindow();
		m_window.display();

		for (auto event = sf::Event{}; m_window.pollEvent(event);)
		{
			switch (event.type)
			{
				case sf::Event::Closed:
					m_window.close();
					break;
				case sf::Event::KeyPressed:
				{
					if (event.key.code == sf::Keyboard::Escape)
					{
						newGame();
					}
					if (event.key.code == sf::Keyboard::B)
					{
						setbomb();
					}
					if (event.key.code == sf::Keyboard::M)
					{
						handleMuting();
					}
					else
					{
						m_player.setDirectionFromKeyboard(event.key.code);
					}
					break;
				}
				case sf::Event::KeyReleased:
				{
					m_player.setDirectionFromKeyboard(sf::Keyboard::Key::Space);
					break;
				}
			}
		}
		
		move(clock, timer);
		handleCollision();
		explosion();
		handleErasing();
		handleSocreboard(timer);
		if (m_player.getWin())
		{
			m_level++;
			calculateScore();
			handleLoadingLevel(timer, clock);
		}
		if (m_player.getLife() == END_GAME || timer.asSeconds() <= 0.f)
		{
			// to do a Lost board
			m_window.close();
			break;
		}
	}
}
//-------------------------------------
void  GameController::drawWindow()
{
	ResourcesManager& resources = ResourcesManager::getInstance();
	sf::Sprite backround;

	backround.setTexture(resources.getTexture("backround"));
	m_window.draw(backround);

	for (const auto& staticObj : m_staticObj)
	{
		staticObj->draw(m_window);
	}

	// Draw moving objects
	for (const auto& movingObj : m_movingObj)
	{
		movingObj->draw(m_window);
	}

	m_player.draw(m_window);
	m_window.draw(m_scoreboard.getLevel());
	m_window.draw(m_scoreboard.getScore());
	m_window.draw(m_scoreboard.getTime());
	m_window.draw(m_scoreboard.getLives());
}
//-------------------------------------
void GameController::move(sf::Clock& clock, sf::Time& timer)
{
	const auto deltaTime = clock.restart();

	int index = 0;
	m_player.update(deltaTime);
	for (const auto& movingObj : m_movingObj)
	{
		if (index < Guard::getNumOfGuardsAlive())
		{
			movingObj->setDirection(m_player.getPosition());
		}
		movingObj->update(deltaTime);
		index++;
	}
	timer -= deltaTime;
}
//-------------------------------------
void GameController::handleCollision()
{
	for (const auto& staticObj : m_staticObj)
	{
		if (m_player.checkCollision(*staticObj))
		{
			m_player.collide(*staticObj);
		}
	}

	for (const auto& movingObj : m_movingObj)
	{
		for (const auto& staticObj : m_staticObj)
		{
			if (movingObj->checkCollision(*staticObj))
			{
				movingObj->collide(*staticObj);
			}
		}
	}

	for (int guard = 0; guard < Guard::getNumOfGuardsAlive(); ++guard)
	{
		if (m_player.checkCollision(*m_movingObj[guard]))
		{
			m_player.collide(*m_movingObj[guard]);
			resetLevel();
			break;
		}
	}

	for (int moveObj = 0; moveObj < (Guard::getNumOfGuardsAlive()-1); ++moveObj)
	{
		for (int nextMoveObj = moveObj + 1; nextMoveObj < Guard::getNumOfGuardsAlive(); ++nextMoveObj)
		{
			if (m_movingObj[moveObj]->checkCollision(*m_movingObj[nextMoveObj]))
			{
				m_movingObj[moveObj]->collide(*m_movingObj[nextMoveObj]);
			}
		}
	}
}
//-------------------------------------
void GameController::setbomb()
{
	m_movingObj.push_back(std::make_unique<Bombs>(sf::Vector2f(m_player.getPosition()), ResourcesManager::getInstance().getTexture("bomb")));
}
//-------------------------------------
void GameController::handleErasing()
{
	std::erase_if(m_movingObj, [](const auto& item)
		{return item->isDead(); });

	std::erase_if(m_staticObj, [](const auto& item)
		{return item->isDead(); });
}
//-------------------------------------
void GameController::explosion()
{
	auto bomb = Guard::getNumOfGuardsAlive();

	for (; bomb < m_movingObj.size(); bomb++)
	{
		if (m_movingObj[bomb]->getExpo())
		{
			setExpoDirection(bomb);
			checkVaildDraw();
			drawWindow();
			checkExpo();	
		}
	}
}
//-------------------------------------
void GameController::calculateScore()
{
	int points = 0;
	points += ENDING_LEVEL;
	points += (Guard::getNumOfStartingGuards() * POINT_FOR_GUARD);
	points += (std::abs(Guard::getNumOfGuardsAlive() - Guard::getNumOfStartingGuards()) * KILL_GUARD);
	m_scoreboard.updateScore(points);
}
//-------------------------------------
void GameController::resetLevel()
{
	for (int index = 0; index < Guard::getNumOfGuardsAlive(); ++index)
	{
		m_movingObj[index]->setPosition(m_movingObj[index]->getStartingPosition());
	}
	for (int index = Guard::getNumOfGuardsAlive(); index < m_movingObj.size(); ++index)
	{
		m_movingObj[index]->setLife(true);
	}
}
//-------------------------------------
void GameController::setExpoDirection(int index)
{
	for (int direction = 0; direction < NUM_OF_DIRECTION; direction++)
	{
		switch(direction)
		{
		case UP:
			m_movingObj.push_back(std::make_unique<Explosion>(sf::Vector2f(m_movingObj[index]->getPosition()), ResourcesManager::getInstance().getTexture("explosion")));
			m_movingObj[m_movingObj.size() - 1]->setDirection(sf::Vector2f(0, -BOMB_WIDTH));
			break;
		case DOWN:
			m_movingObj.push_back(std::make_unique<Explosion>(sf::Vector2f(m_movingObj[index]->getPosition()), ResourcesManager::getInstance().getTexture("explosion")));
			m_movingObj[m_movingObj.size() - 1]->setDirection(sf::Vector2f(0, BOMB_WIDTH));
			break;
		case LEFT:
			m_movingObj.push_back(std::make_unique<Explosion>(sf::Vector2f(m_movingObj[index]->getPosition()), ResourcesManager::getInstance().getTexture("explosion")));
			m_movingObj[m_movingObj.size() - 1]->setDirection(sf::Vector2f(-BOMB_WIDTH, 0));
			break;
		case RIGHT:
			m_movingObj.push_back(std::make_unique<Explosion>(sf::Vector2f(m_movingObj[index]->getPosition()), ResourcesManager::getInstance().getTexture("explosion")));
			m_movingObj[m_movingObj.size() - 1]->setDirection(sf::Vector2f(BOMB_WIDTH, 0));
			break;
		}
	}
	m_movingObj.push_back(std::make_unique<Explosion>(sf::Vector2f(m_movingObj[index]->getPosition()), ResourcesManager::getInstance().getTexture("explosion")));
}
//-------------------------------------
void GameController::checkExpo()
{
	auto explosion = m_movingObj.size() - NUM_OF_EXPLOSION;
	for (; explosion < m_movingObj.size(); explosion++)
	{
		for (int guard = 0; guard < Guard::getNumOfGuardsAlive(); guard++)
		{
			if (m_movingObj[explosion]->checkCollision(*m_movingObj[guard]))
			{
				m_movingObj[explosion]->collide(*m_movingObj[guard]);

			}
		}
		for (const auto& staticObj : m_staticObj)
		{
			if (m_movingObj[explosion]->checkCollision(*staticObj))
			{
				m_movingObj[explosion]->collide(*staticObj);
			}
		}
		if (m_movingObj[explosion]->checkCollision(m_player))
		{
			m_movingObj[explosion]->collide(m_player);
			resetLevel();
			break;
		}
	}
}
//-------------------------------------
void GameController::checkVaildDraw()
{
	auto explosion = m_movingObj.size() - NUM_OF_EXPLOSION;
	for (; explosion < m_movingObj.size(); explosion++)
	{
		for (const auto& staticObj : m_staticObj)
		{
			if (m_movingObj[explosion]->checkCollision(*staticObj))
			{
				m_movingObj[explosion]->collide(*staticObj);
			}
		}
	}
	handleErasing();
}
//---------------------------------
void GameController::handleLoadingLevel(sf::Time& timer, sf::Clock& clock)
{
	m_movingObj.clear();
	m_staticObj.clear();
	if (m_board.loadLevel(m_level) == END_GAME)
	{
		//make the end game
	}
	Guard::resetNumOfGuards();
	m_board.LoadBoard(m_movingObj, m_staticObj, m_player);

	timer = sf::seconds(120);
	clock.restart();
}
//-----------------------------
void GameController::handleMusicTransition(bool toGameplay)
{
	if (toGameplay && !m_inGameplay)
	{
		ResourcesManager::getInstance().getMusic("menu").stop();
		if (ResourcesManager::getInstance().getMusic("game").getStatus() != sf::Music::Playing)
		{
			ResourcesManager::getInstance().getMusic("game").play();
		}
		m_inGameplay = true;
	}
	else if (!toGameplay && m_inGameplay)
	{
		ResourcesManager::getInstance().getMusic("game").stop();
		ResourcesManager::getInstance().getMusic("menu").play();
		m_inGameplay = false;
	}
	else
	{
		ResourcesManager::getInstance().getMusic("menu").play();
	}
}
//-------------------------------------
void GameController::handleMuting()
{
	if (ResourcesManager::getInstance().getMusic("game").getStatus() == sf::Music::Playing)
	{
		ResourcesManager::getInstance().getMusic("game").pause();
	}
	else
	{
		ResourcesManager::getInstance().getMusic("game").play();
	}
}
//---------------------------------
void GameController::handleSocreboard(const sf::Time& timer)
{
	m_scoreboard.updateTime(timer, 0);
	m_scoreboard.updateLevel(m_level);
	m_scoreboard.updateLives(m_player.getLife());
}