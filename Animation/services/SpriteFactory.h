
#ifndef SPRITE_FACTORY_H
#define SPRITE_FACTORY_H
#include <Surface.h>
#include <Sprite.h>
#include <TextureRepository.h>

struct SpriteFactory {

	TextureRepository* textureRepository;

	SpriteFactory(TextureRepository* textureRepository) {
		this->textureRepository = textureRepository;
	}

	void grass(int x, int y) {
		new Sprite(x, y, FLOOR, textureRepository->getBag("grass"));
	}


private:
	
};





#endif