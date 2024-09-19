#ifndef PLAYER_REPOSITORY_H
#define PLAYER_REPOSITORY_H

#include <vector>
#include <Player.h>

class PlayerRepository {

	Player* player;

public:
	PlayerRepository() {}

	void set(Player* player) {
		
		if (player == nullptr) {
			printf("PLAYER NOT CORRECTLY SET");
		}
		if (player != nullptr)
			printf("PLAYER SET");
			//printf("players stats: %d, %d, %d", player->getHeight(), player->getWidth(), player->getX());
			this->player = player;
	}

	Player*& get() {
		return player;
	}
};

#endif