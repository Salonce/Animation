#include "Sprite.h"


std::vector<Sprite*>* Sprite::spritesVector = NULL;

bool Sprite::initializeSprites(std::vector<Sprite*>* spritesVector) {
	Sprite::spritesVector = spritesVector;
	if (Sprite::spritesVector == NULL) {
		printf("Sprite's not loaded\n");
		return false;
	}
	return true;
}

