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
	auto window = sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), "level");

	loadSprites();
	
	int index = 0;
	while (window.isOpen())
	{
		if (index == 8)
		{
			index = 0;
		}
		// Clear the window
		window.clear();

		// Draw the sprite
		window.draw(m_sprite[7]);
		const float size = 50;
		m_sprite[3].setPosition(100, 100);
		m_sprite[3].setScale(size / m_sprite[3].getLocalBounds().width, size / m_sprite[3].getLocalBounds().height);
		window.draw(m_sprite[3]);
		// Display everything
		window.display();
		

		for (auto event = sf::Event{}; window.pollEvent(event);)
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
	}
}

void  GameController::loadSprites()
{
	
	ResourcesManager& resources = ResourcesManager::getInstance();

	m_sprite.clear();

	m_sprite.reserve(OBJECT_NAME.size());

	for (int pics = 0; pics < 8; ++pics)
	{
		sf::Sprite pic;
		pic.setTexture(resources.getTexture(OBJECT_NAME.at(pics)));
		m_sprite.push_back(pic);
	}
}