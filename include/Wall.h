#pragma once
#include "StaticObject.h"

class Wall : public StaticObject
{
public:
	Wall(sf::Vector2f position, const sf::Texture& texture, float CELL_WIDTH, float CELL_HEIGHT);
	virtual void staticCollide(GameObject& otherObject) override {};
	/*virtual void updateableCollide(GameObject& otherObject) override{};
	virtual ReturnType doorCollide(Door& otherObject) override {};
	virtual ReturnType wallCollide(Wall& otherobject) override{};
	virtual ReturnType guardCollide(Guard& otherObject) override;
	virtual ReturnType bombCollide(Bombs& otherobject) override {};*/
	virtual ReturnType playerCollide(Player& otherObject) override;
	~Wall() = default;
};