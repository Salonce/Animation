
#ifndef PLAYER_SERVICE_H
#define PLAYER_SERVICE_H

#include <vector>
#include <Player.h>
#include <PlayerRepository.h>
#include "ObstaclesService.h"

class PlayerService {

	PlayerRepository* playerRepository;
	ObstaclesService* obstaclesService;

public:

	void handle(const Uint8* currentKeyStates) {
		Player* player = getPlayer();
		if (currentKeyStates[SDL_SCANCODE_UP]) player->handleEvent(Direction::UP);
		if (currentKeyStates[SDL_SCANCODE_DOWN]) player->handleEvent(Direction::DOWN);
		if (currentKeyStates[SDL_SCANCODE_LEFT]) player->handleEvent(Direction::LEFT);
		if (currentKeyStates[SDL_SCANCODE_RIGHT]) player->handleEvent(Direction::RIGHT);
		if (!(currentKeyStates[SDL_SCANCODE_UP]) && !(currentKeyStates[SDL_SCANCODE_DOWN])) player->handleEvent(Direction::SLOW_DOWN);
		if (!(currentKeyStates[SDL_SCANCODE_LEFT]) && !(currentKeyStates[SDL_SCANCODE_RIGHT])) player->handleEvent(Direction::SLOW_DOWN_HORIZONTALLY);
	}

	PlayerService(PlayerRepository* playerRepository, ObstaclesService* obstaclesService) {
		this->playerRepository = playerRepository;
		this->obstaclesService = obstaclesService;
	};

	Player* getPlayer() {
		return playerRepository->get();
	}

	void playerMoves() {
		getPlayer()->move(obstaclesService->getObstacles());
	}
	//playerService.getPlayer()->move(getObstacles(objsVect, playerService.getPlayer()));
};



#endif