#include "GameController.h"


GameController::GameController()
{}



void GameController::newGame()
{	
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
		// Clear the window
		window.clear();

		// Draw the sprite
		
		drawWindow(window);
		// Display everything
		window.display();
		

		for (auto event = sf::Event{}; window.pollEvent(event);)
		{
			m_player.setDirectionFromKeyboard(sf::Keyboard::Key::Space);
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
					else
					{
						m_player.setDirectionFromKeyboard(event.key.code);
					}
					break;
				}
			}
		}

		move(clock);
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
		//movingObj->setDirection(m_player.getPosition());
		movingObj->update(deltaTime);
	}
}