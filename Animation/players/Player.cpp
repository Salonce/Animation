#include <SDL.h>
#include "Player.h"
#include <Obstacle.h>
#include <vector>
#include <TextureRepository.h>
#include <cstdio>
#include <memory>


void Player::move(std::unique_ptr<std::vector<Obstacle*>> obstaclesVector) {


	bool blocked = false;
	if (velocity_y < 0) {
		for (int i = -1; i >= velocity_y; i--) {
			this->y--;
			for (int j = 0; blocked == false && j < obstaclesVector->size(); j++) {
				if (this == obstaclesVector->at(j))
					continue;
				else if (SDL_HasIntersection(&obstaclesVector->at(j)->getRectangle(), &getRectangle())) {
					blocked = true;
					break;
				}
			}
			if (blocked == true) {
				this->y++;
				break;
			}
		}
	}

	if (velocity_y > 0) {
		blocked = false;
		for (int i = 1; i <= velocity_y; i++) {
			this->y++;
			for (int j = 0; blocked == false && j < obstaclesVector->size(); j++) {
				if (this == obstaclesVector->at(j))
					continue;
				else if (SDL_HasIntersection(&obstaclesVector->at(j)->getRectangle(), &getRectangle())) {
					blocked = true;
					break;
				}
			}
			if (blocked == true) {
				this->y--;
				break;
			}
		}
	}
	if (velocity_x < 0) {
		blocked = false;
		for (int i = -1; i >= velocity_x; i--) {
			this->x--;
			for (int j = 0; blocked == false && j < obstaclesVector->size(); j++) {
				if (this == obstaclesVector->at(j))
					continue;
				else if (SDL_HasIntersection(&obstaclesVector->at(j)->getRectangle(), &getRectangle())) {
					blocked = true;
					break;
				}
			}
			if (blocked == true) {
				this->x++;
				break;
			}
		}
	}

	else if (velocity_x > 0) {
		blocked = false;
		for (int i = 1; i <= velocity_x; i++) {
			this->x++;
			for (int j = 0; blocked == false && j < obstaclesVector->size(); j++) {
				if (this == obstaclesVector->at(j))
					continue;
				else if (SDL_HasIntersection(&obstaclesVector->at(j)->getRectangle(), &getRectangle())) {
					blocked = true;
					break;
				}
			}
			if (blocked == true) {
				this->x--;
				break;
			}
		}
	}	
}

void Player::handleEvent(Direction direction) {
	bool blocked = false;
	switch (direction) {
	case Direction::UP:
		if (velocity_y > -4)
			velocity_y--;
		break;

	case Direction::DOWN:
		if (velocity_y < 4)
			velocity_y++;
		break;

	case Direction::LEFT:
		if (velocity_x > -4)
			velocity_x--;
		break;

	case Direction::RIGHT:
		if (velocity_x < 4)
			velocity_x++;
		break;

	case Direction::SLOW_DOWN:
		if (velocity_y < 0)
			velocity_y++;
		else if (velocity_y > 0)
			velocity_y--;
		break;

	case Direction::SLOW_DOWN_HORIZONTALLY:
		if (velocity_x < 0)
			velocity_x++;
		else if (velocity_x > 0)
			velocity_x--;
		break;

	default:
		break;
	}
}
