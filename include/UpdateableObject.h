#pragma once

#include "GameObject.h"


class UpdateableObject : public GameObject
{
	virtual void update() = 0;

	virtual ~UpdateableObject() = default;
};
