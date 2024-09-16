#ifndef RENDERABLES_SERVICE_H
#define RENDERABLES_SERVICE_H

#include <vector>

class Sprite;
class Obj;
class Player;
class Renderable;

std::vector<Renderable*> getRenderables(std::vector<Sprite*> spritesVector, std::vector<Obj*> objectsVector, Player* character);

#endif