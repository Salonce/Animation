#ifndef SPRITE_REPOSITORY_H
#define  SPRITE_REPOSITORY_H

#include <vector>

class Sprite;

class SpriteRepository {

	std::vector<Sprite*> storage;

public:
	SpriteRepository() {}


	void add(Sprite* sprite) {
		if (sprite != NULL)
			storage.push_back(sprite);
	}

	std::vector<Sprite*>* getAll() {
		return &storage;
	}
};

#endif