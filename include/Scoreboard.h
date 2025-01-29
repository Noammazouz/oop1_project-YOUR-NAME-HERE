#pragma once

#include <SFML/Graphics.hpp>


class Scoreboard
{
public:
	Scoreboard();
	void updateLives(int numberOfLives, sf::Font* newFont);
	sf::Text getLives() const;
	void updateScore(int Score, sf::Font* newFont);
	sf::Text getScore() const;
	void updateLevel(int numberOfLevel, sf::Font* newFont);
	sf::Text getLevel() const;
	void updateTime(sf::Clock Timer, sf::Font* newFont, float addedTime);
	sf::Text getTime() const;

private:
	sf::Text m_numberOfLives, m_numberOfCheeses, m_Score, m_numberOfKeys, m_Level, m_Time;
};