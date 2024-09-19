
#ifndef SPRITE_FACTORY_H
#define SPRITE_FACTORY_H
#include <Surface.h>
#include <Sprite.h>
#include <TextureRepository.h>
#include <SpriteRepository.h>
#include <MovingSpriteRepository.h>
#include <MovingSprite.h>

struct SpriteFactory {

	TextureRepository* textureRepository;
	SpriteRepository* spriteRepository;
	MovingSpriteRepository* movingSpriteRepository;

	SpriteFactory(TextureRepository* textureRepository, SpriteRepository* spriteRepository, MovingSpriteRepository* movingSpriteRepository) {
		this->movingSpriteRepository = movingSpriteRepository;
		this->textureRepository = textureRepository;
		this->spriteRepository = spriteRepository;
	}

	void grass(int x, int y) {
		Sprite* sprite = new Sprite(x, y, FLOOR, textureRepository->newGroup({"grass.png"}));
		spriteRepository->add(sprite);
		// push this sprite into repo, then load from repo in Animation.cpp
	}

	void clouds(int x, int y) {
		MovingSprite* movingSprite = new MovingSprite(x, y, SKY, textureRepository->newGroup({ "kritacloud.png" }), [](int& x, int& y) {x--; });
		movingSpriteRepository->add(movingSprite);
		// push this sprite into repo, then load from repo in Animation.cpp
	}


private:
	
};





#endif