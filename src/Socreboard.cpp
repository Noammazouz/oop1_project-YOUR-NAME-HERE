#include "scoreboard.h"
#include <iostream>

Scoreboard::Scoreboard()
	:m_numberOfLives(sf::Text()), m_Score(sf::Text()), m_Level(sf::Text()), m_Time(sf::Text())
{

}

void Scoreboard::updateLives(int numberOfLives)
{
	m_numberOfLives.setString("Life: " + std::to_string(numberOfLives));
	m_numberOfLives.setCharacterSize(30);
	m_numberOfLives.setFont(ResourcesManager::getInstance().getFont());
	m_numberOfLives.setOutlineColor(sf::Color::White);
	m_numberOfLives.setOutlineThickness(1);
	m_numberOfLives.setPosition(sf::Vector2f(0, 420));
}

sf::Text Scoreboard::getLives() const
{
	return m_numberOfLives;
}

void Scoreboard::updateScore(int Score)
{
	m_Score.setString("Points: " + std::to_string(Score));
	m_Score.setCharacterSize(30);
	m_Score.setFont(ResourcesManager::getInstance().getFont());
	m_Score.setOutlineColor(sf::Color::White);
	m_Score.setOutlineThickness(1);
	m_Score.setPosition(sf::Vector2f(0, 227));
}

sf::Text Scoreboard::getScore() const
{
	return m_Score;
}

void Scoreboard::updateLevel(int numberOfLevel)
{
	m_Level.setString("Level: " + std::to_string(numberOfLevel));
	m_Level.setCharacterSize(30);
	m_Level.setFont(ResourcesManager::getInstance().getFont());
	m_Level.setOutlineColor(sf::Color::White);
	m_Level.setOutlineThickness(1);
	m_Level.setPosition(sf::Vector2f(0, 125));
}

sf::Text Scoreboard::getLevel() const
{
	return m_Level;
}

void Scoreboard::updateTime(sf::Time Timer, float addedTime)
{
	//sf::Time deltaTime = sf::seconds((float)2 * 60 - Timer.getElapsedTime().asSeconds() + addedTime);
	int minutes = Timer.asSeconds() / 60,
		seconds = int(Timer.asSeconds()) % 60;

	std::string temp = std::to_string(minutes) + ":" + std::to_string(seconds);

	m_Time.setString("Time: " + temp);
	m_Time.setCharacterSize(30);
	m_Time.setFont(ResourcesManager::getInstance().getFont());
	m_Time.setOutlineColor(sf::Color::White);
	m_Time.setOutlineThickness(1);
	m_Time.setPosition(sf::Vector2f(0, 320));
}

sf::Text Scoreboard::getTime() const
{
	return m_Time;
}