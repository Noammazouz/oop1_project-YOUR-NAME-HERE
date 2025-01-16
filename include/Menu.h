#pragma once 


class Menu
{
	while (window.isOpen())
	{
		window.clear();
		
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
};