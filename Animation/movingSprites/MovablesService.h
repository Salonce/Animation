
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

		for (MovingSprite*& movingSprite : movingSpriteRepository->getAll())
			autoMovablesVector->push_back(movingSprite);

		return autoMovablesVector;
	}

	//void autoMoveAll() {
	//	std::unique_ptr<std::vector<MovingSprite*>> autoMovablesVector = getAutoMovables();


	//	for (MovingSprite* movingSprite : *autoMovablesVector) {
	//		movingSprite->autoMove();
	//	}
	//}

	void autoMoveAll() {
		// Iterate over the vector in the repository directly
		auto& storage = movingSpriteRepository->getAll();  // Get the reference to the vector

		auto it = storage.begin();
		while (it != storage.end()) {
			MovingSprite* movingSprite = *it;

			movingSprite->autoMove();  // Perform the movement

			// Check if this sprite should be removed
			if (movingSprite->autoRemove()) {
				// Remove the pointer from the vector
				it = storage.erase(it);  // Erase returns an iterator to the next element

				// Clean up the deleted object
				delete movingSprite;
			}
			else {
				// Only increment the iterator if no removal was performed
				++it;
			}
		}
	}
};


#endif