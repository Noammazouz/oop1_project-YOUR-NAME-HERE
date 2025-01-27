#include "Menu.h"
#include "Const.h"
#include "ResourcesManager.h"
#include <iostream>


void Menu::draw()
{
	auto window = sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), "MENU");
	
	while (window.isOpen())
	{
		window.clear();
		if (!m_help_window)
		{
			drawWindow(window);
		}

		if (auto event = sf::Event{}; window.waitEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::MouseButtonReleased:
				handleMouseEvents(window, event.mouseButton);
				break;
			}
		}
	}
}

void Menu::drawWindow(sf::RenderWindow& window)
{
	m_buttons.clear();

	ResourcesManager& resources = ResourcesManager::getInstance();
	sf::Sprite backround;

	backround.setTexture(resources.getTexture("menu"));
	window.draw(backround);

	sf::Sprite pic;
	std::string buttons[NUM_OF_BUTTON - 1] = { "start game", "help", "exit"};

	for (int boutton = 0; boutton < NUM_OF_BUTTON - 1; ++boutton)
	{
		pic.setTexture(resources.getTexture(buttons[boutton]));
		pic.setOrigin(static_cast<float>(pic.getTexture()->getSize().x) / 2.0f, static_cast<float>(pic.getTexture()->getSize().y) / 2.0f);
		pic.setPosition(WIDTH / 2, HEIGHT /5 + 300 * boutton);
		pic.setScale(0.3, 0.3);
		m_buttons.push_back(pic);
		window.draw(pic);
	}
	window.display();
}

void Menu::handleMouseEvents(sf::RenderWindow& window, const sf::Event::MouseButtonEvent& event)
{
	for (int boutton = 0; boutton < NUM_OF_BUTTON; ++boutton)
	{
		if (m_buttons[boutton].getGlobalBounds().contains(event.x, event.y))
		{
			switch (boutton)
			{
				case START_GAME:
				{
					window.close();
					return;
				}
				case HELP:
				{
					drawHelp(window);
				
					break;
				}
				case EXIT:
				{
					exit(EXIT_SUCCESS);
					break;
				}
				case BACK:
				{
					m_help_window = false;
					drawWindow(window);
					break;
				}
			}
		}
	}
}

void Menu::drawHelp(sf::RenderWindow& window)
{
	sf::Sprite return_bouton, help_explation;

	return_bouton.setTexture(ResourcesManager::getInstance().getTexture("return"));
	return_bouton.setScale(0.3, 0.3);
	m_buttons.push_back(return_bouton);

	help_explation.setTexture(ResourcesManager::getInstance().getTexture("explation"));
	window.draw(help_explation);
	window.draw(return_bouton);
	window.display();
	m_help_window = true;
}
