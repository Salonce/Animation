#include "Sprite.h"
#include <cstdio>
#include <vector>

Sprite::Sprite() {}
std::vector<Sprite*>* Sprite::spritesVector = nullptr;

bool Sprite::initializeSprites(std::vector<Sprite*>* spritesVector) {
	Sprite::spritesVector = spritesVector;
	if (Sprite::spritesVector == nullptr) {
		printf("Sprite's not loaded\n");
		return false;
	}
	return true;
}

void Sprite::animate() {
	size_t size = textures.size();
	if (((texture_stage + 1) / 60) < size)
		texture_stage++;
	else
		texture_stage = 0;
}

SDL_Texture* Sprite::getTexture() {
	if (this->textures.empty()) {
		printf("Sprite texture is empty\n");
	};
	return this->textures.at(texture_stage / 60);
}


