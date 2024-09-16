#include <vector>
#include <Obj.h>
#include <Obstacle.h>
#include <Player.h>

std::vector<Obstacle*>* getObstacles(std::vector<Obj*> objectsVector, Player* character) {

    std::vector<Obstacle*>* obstaclesVector = new std::vector<Obstacle*>;

    obstaclesVector->push_back(character);

    for (Obj* obj : objectsVector) {
        obstaclesVector->push_back(obj);
    }

    return obstaclesVector;
}

