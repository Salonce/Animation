
#ifndef MOVABLES_SERVICE_H
#define MOVABLES_SERVICE_H

#include <vector>
#include <PlayerRepository.h>
#include <memory>
#include <MovingSpriteRepository.h>
#include <MovingSprite.h>

class MovablesService {

	MovingSpriteRepository* movingSpriteRepository;

public:

	MovablesService(MovingSpriteRepository* movingSpriteRepository) : 
		movingSpriteRepository(movingSpriteRepository) {
	}

	std::unique_ptr<std::vector<MovingSprite*>> getAutoMovables() {
		auto autoMovablesVector = std::make_unique<std::vector<MovingSprite*>>();

		/// place for other automovables just in case, rebuild for an AutoMovable interface if needed

		for (MovingSprite* movingSprite : movingSpriteRepository->getAll())
			autoMovablesVector->push_back(movingSprite);

		return autoMovablesVector;
	}

	void autoMoveAll() {
		std::unique_ptr<std::vector<MovingSprite*>> autoMovablesVector = getAutoMovables();

		for (MovingSprite* movingSprite : *autoMovablesVector) {
			movingSprite->autoMove();
		}
	}

};


#endif