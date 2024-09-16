
#ifndef OBSTACLES_SERVICE_H
#define OBSTACLES_SERVICE_H

#include <vector>
#include <ObjRepository.h>
#include <PlayerRepository.h>
class Obj;
class Player;
class Obstacle;

class ObstaclesService {

	ObjRepository* objRepository;
	PlayerRepository* playerRepository;

public:

	ObstaclesService(ObjRepository* objRepository, PlayerRepository* playerRepository) {
		this->objRepository = objRepository;
		this->playerRepository = playerRepository;
	}

	std::vector<Obstacle*>* getObstacles() {
		std::vector<Obstacle*>* obstaclesVector = new std::vector<Obstacle*>;

		obstaclesVector->push_back(playerRepository->get());

		for (Obj* obj : objRepository->getAll())
			obstaclesVector->push_back(obj);

		return obstaclesVector;
	}

};

std::vector<Obstacle*>* getObstacles(std::vector<Obj*> objectsVector, Player* character);

#endif