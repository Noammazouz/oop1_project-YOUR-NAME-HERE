#include "GameController.h"


GameController::GameController()
	: m_level(1)
{}



void GameController::newGame()
{
	m_menu.draw();
	runLevel();
}
//---------
void GameController::runLevel()
{
	if (m_board.loadLevel(m_level) == END_GAME)
	{
		//make the end game
	}
	Guard::resetNumOfGuards();

	auto window = sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), "level");
	m_board.LoadBoard(m_movingObj, m_staticObj, m_player);

	sf::Time timer = sf::seconds(120);
	sf::Clock clock;
	
	while (window.isOpen())
	{
		window.clear();

		drawWindow(window);

		window.display();
		

		for (auto event = sf::Event{}; window.pollEvent(event);)
		{
			switch (event.type)
			{
				case sf::Event::Closed:
					window.close();
					break;
				case sf::Event::KeyPressed:
				{
					if (event.key.code == sf::Keyboard::Escape)
					{
						window.close();
					}
					if (event.key.code == sf::Keyboard::B)
					{
						setbomb();
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
		//to reset game and to dec player life
		//to do leader board
	}
}

void  GameController::drawWindow(sf::RenderWindow& window)
{
	ResourcesManager& resources = ResourcesManager::getInstance();
	sf::Sprite backround;

	backround.setTexture(resources.getTexture("backround"));
	window.draw(backround);

	for (const auto& staticObj : m_staticObj)
	{
		staticObj->draw(window);
	}

	// Draw moving objects
	for (const auto& movingObj : m_movingObj)
	{
		movingObj->draw(window);
	}

	m_player.draw(window);
}
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
	/*for (size_t guard = 0; guard < Guard::getNumOfGuardsAlive(); ++guard)
	{
		if (m_player.checkCollision(*m_movingObj[guard]))
		{
			m_player.collide(*m_movingObj[guard]);
			resetGuardPos();
			break;
		}
	}*/

	for (size_t moveObj = 0; moveObj < (Guard::getNumOfGuardsAlive()-1); ++moveObj)
	{
		for (size_t nextMoveObj = moveObj + 1; nextMoveObj < Guard::getNumOfGuardsAlive(); ++nextMoveObj)
		{
			if (m_movingObj[moveObj]->checkCollision(*m_movingObj[nextMoveObj]))
			{
				m_movingObj[moveObj]->collide(*m_movingObj[nextMoveObj]);
			}
		}
	}
}

void GameController::setbomb()
{
	m_movingObj.push_back(std::make_unique<Bombs>(sf::Vector2f(m_player.getPosition()), ResourcesManager::getInstance().getTexture("bomb")));
}

void GameController::handleErasing()
{
	std::erase_if(m_movingObj, [](const auto& item)
		{
			return item->isDead(); });

	std::erase_if(m_staticObj, [](const auto& item)
		{
			return item->isDead(); });
}

void GameController::explosion()
{
	auto bomb = Guard::getNumOfGuardsAlive();

	for (; bomb < m_movingObj.size(); bomb++)
	{
		if (m_movingObj[bomb]->getExpo())
		{
			for (int direction = 0; direction < NUM_OF_DIRECTION; direction++)
			{
				m_movingObj[bomb]->setDirection(sf::Vector2f(m_movingObj[bomb]->getPosition().x+32.f, m_movingObj[bomb]->getPosition().y + 32.f));
			}
			m_movingObj[bomb]->setDirection(m_movingObj[bomb]->getPosition());
			std::cout << "in expo if" << std::endl;
			for (int guard = 0; guard < Guard::getNumOfGuardsAlive(); guard++)
			{
				if (m_movingObj[bomb]->checkCollision(*m_movingObj[guard]))
				{
					m_movingObj[bomb]->collide(*m_movingObj[guard]);

				}
			}
			if (m_movingObj[bomb]->checkCollision(m_player))
			{
				m_movingObj[bomb]->collide(m_player);
				resetGuardPos();
				break;
			}
			
		}
	}
}
void GameController::calculateScore()
{
	int points = 0;
	points += ENDING_LEVEL;
	points += (Guard::getNumOfStartingGuards() * POINT_FOR_GUARD);
	points += (std::abs(Guard::getNumOfGuardsAlive() - Guard::getNumOfStartingGuards()) * KILL_GUARD);
	//m_player.addScore(points);
}

void GameController::resetGuardPos()
{
	for (size_t index = 0; index < Guard::getNumOfGuardsAlive(); ++index)
	{
		m_movingObj[index]->setPosition(m_movingObj[index]->getStartingPosition());
	}
}