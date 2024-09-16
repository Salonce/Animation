
#ifndef PLAYER_SERVICE_H
#define PLAYER_SERVICE_H

#include <vector>
#include <Player.h>
#include <PlayerRepository.h>

class PlayerService {
	PlayerRepository* playerRepository;

public:

	void handle(const Uint8* currentKeyStates) {
		Player* player = this->playerRepository->get();
		if (currentKeyStates[SDL_SCANCODE_UP]) player->handleEvent(Direction::UP);
		if (currentKeyStates[SDL_SCANCODE_DOWN]) player->handleEvent(Direction::DOWN);
		if (currentKeyStates[SDL_SCANCODE_LEFT]) player->handleEvent(Direction::LEFT);
		if (currentKeyStates[SDL_SCANCODE_RIGHT]) player->handleEvent(Direction::RIGHT);
		if (!(currentKeyStates[SDL_SCANCODE_UP]) && !(currentKeyStates[SDL_SCANCODE_DOWN])) player->handleEvent(Direction::SLOW_DOWN);
		if (!(currentKeyStates[SDL_SCANCODE_LEFT]) && !(currentKeyStates[SDL_SCANCODE_RIGHT])) player->handleEvent(Direction::SLOW_DOWN_HORIZONTALLY);
	}

	PlayerService(PlayerRepository* playerRepository) {
		this->playerRepository = playerRepository;
	};

	Player* getPlayer() {
		return playerRepository->get();
	}

	void playerMoves() {

	}
	//playerService.getPlayer()->move(getObstacles(objsVect, playerService.getPlayer()));
};



#endif