
#ifndef PLAYER_SERVICE_H
#define PLAYER_SERVICE_H

#include <vector>
#include <Player.h>


class PlayerService {

	Player* player;

	PlayerService(Player* player) {
		this->player = player;
	};

	void handle(const Uint8* currentKeyStates) {
		if (currentKeyStates[SDL_SCANCODE_UP]) player->handleEvent(Direction::UP);
		if (currentKeyStates[SDL_SCANCODE_DOWN]) player->handleEvent(Direction::DOWN);
		if (currentKeyStates[SDL_SCANCODE_LEFT]) player->handleEvent(Direction::LEFT);
		if (currentKeyStates[SDL_SCANCODE_RIGHT]) player->handleEvent(Direction::RIGHT);
		if (!(currentKeyStates[SDL_SCANCODE_UP]) && !(currentKeyStates[SDL_SCANCODE_DOWN])) player->handleEvent(Direction::SLOW_DOWN);
		if (!(currentKeyStates[SDL_SCANCODE_LEFT]) && !(currentKeyStates[SDL_SCANCODE_RIGHT])) player->handleEvent(Direction::SLOW_DOWN_HORIZONTALLY);
	}

};




#endif