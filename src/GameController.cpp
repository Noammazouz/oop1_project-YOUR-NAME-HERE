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
	m_board.LoadBoard(window, m_movingObj, m_staticObj);
	
	while (window.isOpen())
	{
		// Clear the window
		window.clear();

		// Draw the sprite
		
		//drawWindow(window);
		// Display everything
		window.display();
		

		for (auto event = sf::Event{}; window.pollEvent(event);)
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
	}
}

void  GameController::drawWindow(sf::RenderWindow& window)
{
	
	ResourcesManager& resources = ResourcesManager::getInstance();
	sf::Sprite backround;
	backround.setTexture(resources.getTexture("backround"));
	window.draw(backround);
}