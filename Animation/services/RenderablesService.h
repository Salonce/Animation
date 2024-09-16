#ifndef RENDERABLES_SERVICE_H
#define RENDERABLES_SERVICE_H

#include <vector>
#include <ObjRepository.h>
#include <SpriteRepository.h>
#include <Renderable.h>
#include <Sprite.h>
#include <Obj.h>
#include <Player.h>
#include <PlayerRepository.h>
#include <CompareRenderables.h>


class RenderablesService {


    PlayerRepository* playerRepository;
	SpriteRepository* spriteRepository;
	ObjRepository* objRepository;

    std::vector<Renderable*> getRenderables() {

        std::vector<Renderable*> renderablesVector;

        renderablesVector.push_back(playerRepository->get());

        for (Obj* obj : objRepository->getAll())
            renderablesVector.push_back(obj);

        for (Renderable* renderable : spriteRepository->getAll())
            renderablesVector.push_back(renderable);

        return renderablesVector;
    }

public:
    RenderablesService(PlayerRepository* playerRepository, SpriteRepository* spriteRepository, ObjRepository* objRepository) {
        this->playerRepository = playerRepository;
        this->spriteRepository = spriteRepository;
        this->objRepository = objRepository;
    }

    //void renderAll() {
    //    std::vector<Renderable*> renderables = getRenderables();

    //    std::sort(renderables.begin(), renderables.end(), CompareRenderables());

    //    for (Renderable* renderable : renderables) {
    //        renderable->animate();
    //        renderTexture(renderer, renderable);
    //    }
    //}

};

std::vector<Renderable*> getRenderables(std::vector<Sprite*> spritesVector, std::vector<Obj*> objectsVector, Player* character);

#endif