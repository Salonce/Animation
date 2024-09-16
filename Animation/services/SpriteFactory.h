
#ifndef SPRITE_FACTORY_H
#define SPRITE_FACTORY_H
#include <Surface.h>
#include <Sprite.h>
#include <TextureRepository.h>
#include <SpriteRepository.h>

struct SpriteFactory {

	TextureRepository* textureRepository;
	SpriteRepository* spriteRepository;

	SpriteFactory(TextureRepository* textureRepository, SpriteRepository* spriteRepository) {
		this->textureRepository = textureRepository;
		this->spriteRepository = spriteRepository;
	}

	void grass(int x, int y) {
		Sprite* sprite = new Sprite(x, y, FLOOR, textureRepository->getBag("grass"));
		spriteRepository->add(sprite);
		// push this sprite into repo, then load from repo in Animation.cpp
	}


private:
	
};





#endif