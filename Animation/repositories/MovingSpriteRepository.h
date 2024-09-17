#ifndef MOVING_SPRITE_REPOSITORY_H
#define MOVING_SPRITE_REPOSITORY_H

#include <vector>
#include "Obj.h"
#include <MovingSprite.h>

class MovingSpriteRepository {

	std::vector<MovingSprite*> storage;

public:
	MovingSpriteRepository() {}

	void add(MovingSprite* movingSprite) {
		if (movingSprite != nullptr)
			storage.push_back(movingSprite);
	}

	std::vector<MovingSprite*>& getAll() {
		return storage;
	}
};

#endif