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
	/*ResourcesManager& r = ResourcesManager::instance();
	r.loadTexture();*/
	/*while(1)
	{
	window.display();
	}*/
	loadSprites(window);
	
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
		
		m_sprite[6].setPosition(100, 100);
		window.draw(m_sprite[6]);
		const float size = 50;
		m_sprite[3].setPosition(100, 100);
		m_sprite[3].setScale(size / m_sprite[3].getLocalBounds().width, size / m_sprite[3].getLocalBounds().height);
		window.draw(m_sprite[3]);
		// Display everything
		window.display();
		

		for (auto event = sf::Event{}; window.pollEvent(event); )
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
	}
}

void  GameController::loadSprites(sf::RenderWindow& window)
{
	sf::Sprite pic;
	ResourcesManager& r = ResourcesManager::instance();
	r.loadTexture();
	std::vector<std::string> name = { "door", "guard" , "player" ,"rock" , "wall" , "empty" , "menu" ,"backround" };
	for (int pics = 0; pics < 8; ++pics)
	{
		const sf::Texture* playerTexture = r.getTexture(name.at(pics));
		if (playerTexture)
		{
			pic.setTexture(*playerTexture); // Dereference the pointer to get the texture
		}
		else
		{
			return; // Exit if the texture is not found
		}
		m_sprite.push_back(pic);
	}
	window.draw(m_sprite[6]);
	window.display();
	while(1)
	{ }
}