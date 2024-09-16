#ifndef RENDERABLES_SERVICE_H
#define RENDERABLES_SERVICE_H

#include <vector>
#include <ObjRepository.h>
#include <SpriteRepository.h>
#include <Renderable.h>
#include <Sprite.h>
#include <Obj.h>
#include <Player.h>
#include <PlayerService.h>


class RenderablesService {


    PlayerService* playerServiceRepo;
	SpriteRepository* spriteRepository;
	ObjRepository* objRepository;



public:
    RenderablesService(PlayerService* playerServiceRepo, SpriteRepository* spriteRepository, ObjRepository* objRepository) {
        this->playerServiceRepo = playerServiceRepo;
        this->spriteRepository = spriteRepository;
        this->objRepository = objRepository;
    }
    std::vector<Renderable*> getRenderables() {

        std::vector<Renderable*> renderablesVector;

        renderablesVector.push_back(playerServiceRepo->getPlayer());

        for (Obj* obj : objRepository->getAll())
            renderablesVector.push_back(obj);

        for (Renderable* renderable : spriteRepository->getAll())
            renderablesVector.push_back(renderable);

        return renderablesVector;
    }
};

std::vector<Renderable*> getRenderables(std::vector<Sprite*> spritesVector, std::vector<Obj*> objectsVector, Player* character);

#endif