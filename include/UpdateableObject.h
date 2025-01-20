#pragma once

#include "GameObject.h"


class UpdateableObject : public GameObject
{
public:
	virtual void update() = 0;

	virtual ~UpdateableObject() = default;
private:
};
