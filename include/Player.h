#pragma once
#include "UpdateableObject.h"

class GameObject;

class Player : public UpdateableObject
{
public:
	Player();
	Player(sf::Vector2f position, const sf::Texture& texture, float CELL_WIDTH, float CELL_HEIGHT);

	void update(sf::Time deltaTime) override;
	void setDirectionFromKeyboard(sf::Keyboard::Key key);
	void setDirection(sf::Vector2f position) override;

	virtual void collide(GameObject& otherObject) override;
	virtual void guardCollide(Guard& otherObject) override;
	virtual void explosionCollide(Explosion& otherobject) override;

	void setWin(bool win);
	bool getWin() const;
	void decLife();
	void incLife();
	static int getLife();
	const Present& getPresent() const;
	void setPresent(Present present);
	~Player() = default;

private:
	sf::Vector2f m_direction;
	static int m_lives;
	bool m_win = false;
	Present m_present;
};