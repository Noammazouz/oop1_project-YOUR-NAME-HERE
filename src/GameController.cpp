#include "GameController.h"


GameController::GameController()
{}



void GameController::newGame()
{
	m_menu.draw();
	runLevel();
}
//---------
void GameController::runLevel()
{
	m_board.loadLevel();
	auto window = sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), "level");
	m_board.LoadBoard(m_movingObj, m_staticObj, m_player);
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
						setbomb(window);
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
		
		move(clock);
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
void GameController::move(sf::Clock& clock)
{
	const auto deltaTime = clock.restart();

	m_player.update(deltaTime);
	for (auto& movingObj : m_movingObj)
	{
		movingObj->setDirection(m_player.getPosition());
		movingObj->update(deltaTime);
	}
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

	for (size_t i = 0; i < m_movingObj.size(); ++i)
	{
		for (size_t j = i + 1; j < m_movingObj.size(); ++j)
		{
			if (m_movingObj[i]->checkCollision(*m_movingObj[j]))
			{
				m_movingObj[i]->collide(*m_movingObj[j]);
			}
		}
	}
}

void GameController::setbomb(sf::RenderWindow& window)
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
	for (size_t i = 0; i < m_movingObj.size(); ++i)
	{
		for (size_t j = i + 1; j < m_movingObj.size(); ++j)
		{
			if (m_movingObj[i]->checkCollision(*m_movingObj[j]) && m_movingObj[i]->getId() != GUARD)
			{
				m_movingObj[i]->collide(*m_movingObj[j]);
			}
		}
	}
}