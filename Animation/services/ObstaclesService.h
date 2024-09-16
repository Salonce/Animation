
#ifndef OBSTACLES_SERVICE_H
#define OBSTACLES_SERVICE_H

#include <vector>
#include <Obj.h>
#include <Player.h>
#include <Obstacle.h>

std::vector<Obstacle*>* getObstacles(std::vector<Obj*> objectsVector, Player* character);

#endif