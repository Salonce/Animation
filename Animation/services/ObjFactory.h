#ifndef OBJ_FACTORY_H
#define OBJ_FACTORY_H

#include <Surface.h>
#include <Obj.h>
#include <SDL_rect.h>
#include <Player.h>
#include <TextureRepository.h>
#include <ObjRepository.h>
#include "PlayerService.h"
#include <PlayerRepository.h>

struct ObjFactory {

	TextureRepository* textureRepository;
	ObjRepository* objRepository;
	PlayerRepository* playerRepository;

	ObjFactory(TextureRepository* textureRepository, ObjRepository* objRepository, PlayerRepository* playerRepository) {
		this->textureRepository = textureRepository;
		this->objRepository = objRepository;
		this->playerRepository = playerRepository;
	}


	void rock(int x, int y) {
		Obj* rock = new Obj(x, y, ON_FLOOR, textureRepository->getBag("rock"), SDL_Rect(18, 59, 32, 5));
		objRepository->add(rock);
	}

	void tree(int x, int y) {
		Obj* tree = new Obj(x, y, ON_FLOOR, textureRepository->getBag("tree"), SDL_Rect(18, 59, 25, 5));
		objRepository->add(tree);
	}

	void makePlayer(int x, int y) {
		Player* player = new Player(x, y, textureRepository->getBag("player"));
		playerRepository->set(player);
		printf("PLAAA");

	}
};




#endif