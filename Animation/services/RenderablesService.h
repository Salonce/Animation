#ifndef RENDERABLES_SERVICE_H
#define RENDERABLES_SERVICE_H

#include <vector>
#include <Sprite.h>
#include <Obj.h>
#include <Player.h>
#include <Renderable.h>

std::vector<Renderable*> getRenderable(std::vector<Sprite*> spritesVector, std::vector<Obj*> objectsVector, Player* character);

#endif