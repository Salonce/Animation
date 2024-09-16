#ifndef OBJ_FACTORY_H
#define OBJ_FACTORY_H

#include <Surface.h>
#include <Obj.h>
#include <SDL_rect.h>
#include <Player.h>
#include <TextureRepository.h>
#include <ObjRepository.h>
#include "PlayerService.h"

struct ObjFactory {

	TextureRepository* textureRepository;
	ObjRepository* objRepository;
	PlayerService* playerServiceRepo;

	ObjFactory(TextureRepository* textureRepository, ObjRepository* objRepository, PlayerService* playerServiceRepo) {
		this->textureRepository = textureRepository;
		this->objRepository = objRepository;
		this->playerServiceRepo = playerServiceRepo;
	}


	void rock(int x, int y) {
		Obj* rock = new Obj(x, y, ON_FLOOR, textureRepository->getBag("rock"), SDL_Rect(18, 59, 32, 5));
		objRepository->add(rock);
	}

	void tree(int x, int y) {
		Obj* tree = new Obj(x, y, ON_FLOOR, textureRepository->getBag("tree"), SDL_Rect(18, 59, 25, 5));
		objRepository->add(tree);
	}

	void player(int x, int y) {
		playerServiceRepo->setPlayer(new Player(x, y, textureRepository->getBag("player")));
		Player* character = new Player(x, y, textureRepository->getBag("player"));
	}
};




#endif