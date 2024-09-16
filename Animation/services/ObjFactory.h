#ifndef OBJ_FACTORY_H
#define OBJ_FACTORY_H

#include <Surface.h>
#include <Obj.h>
#include <SDL_rect.h>
#include <Player.h>
#include <TextureRepository.h>

struct ObjFactory {

	TextureRepository* textureRepository;

	ObjFactory(TextureRepository* textureRepository) {
		this->textureRepository = textureRepository;
	}


	void rock(int x, int y) {
		new Obj(x, y, ON_FLOOR, textureRepository->getBag("rock"), SDL_Rect(18, 59, 32, 5));;
	}

	void tree(int x, int y) {
		new Obj(x, y, ON_FLOOR, textureRepository->getBag("tree"), SDL_Rect(18, 59, 25, 5));;
	}

	void player(int x, int y) {
		Player* character = new Player(x, y, textureRepository->getBag("player"));
	}
};




#endif