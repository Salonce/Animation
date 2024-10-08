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
		Obj* rock = new Obj(x, y, ON_FLOOR, textureRepository->newGroup({ "rock.png" }), SDL_Rect(18, 59, 32, 5));
		objRepository->add(rock);
	}

	void tree(int x, int y) {
		Obj* tree = new Obj(x, y, ON_FLOOR, textureRepository->newGroup({ "tree.png", "tree2.png"}), SDL_Rect(18, 59, 25, 5));
		objRepository->add(tree);
	}

	void puddle(int x, int y) {
		Obj* puddle = new Obj(x, y, ON_FLOOR, textureRepository->newGroup({ "puddle1.png", "puddle2.png"}), SDL_Rect(18, 59, 25, 5));
		objRepository->add(puddle);
	}
	void willow(int x, int y) {
		Obj* willow = new Obj(x, y, ON_FLOOR, textureRepository->newGroup({ "willow1.png", "willow2.png"}), SDL_Rect(18, 59, 25, 5));
		objRepository->add(willow);
	}


	void makePlayer(int x, int y) {
		Player* player = new Player(x, y, textureRepository->newGroup({ "player.png" }));
		playerRepository->set(player);
		printf("PLAAA");

	}
};




#endif