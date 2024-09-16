
#ifndef OBSTACLES_SERVICE_H
#define OBSTACLES_SERVICE_H

#include <vector>;
class Obj;
class Player;
class Obstacle;

std::vector<Obstacle*>* getObstacles(std::vector<Obj*> objectsVector, Player* character);

#endif