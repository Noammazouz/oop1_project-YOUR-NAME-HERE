#include "Menu.h"
#include <iostream>


void Menu::draw(sf::RenderWindow& window)
{
	//ResourcesManager& resources = ResourcesManager::getInstance();
	sf::Font font;
	if (!font.loadFromFile("C:/Windows/Fonts/arial.ttf"))
	{
		std::cout << "Error loading font\n";
	}

	sf::Text text;
	text.setFont(font);
	text.setString("Press Enter to start the game");
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::White);
	text.setPosition(200, 200);

	
	while (window.isOpen())
	{
		window.clear();
		window.draw(text);
		window.display();
		if (auto event = sf::Event{}; window.waitEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::MouseButtonReleased:
				//handleMouseEvents(window, event.mouseButton, current_tex);
				break;
			}
		}
	}
}
