#include <SDL.h>
#include <SDL_image.h>
#include <vector>
#include <unordered_map>
#include <string>
#include <queue>
#include<iostream>
#include<cstdlib>
#include <algorithm>
#include <ctime>

#include "sdl_util.h"
#include "Direction.h"
#include "Player.h"
#include "Sprite.h"
#include "TextureRepository.h"
#include "CompareRenderables.h"
#include "Obj.h"
#include "Renderable.h"
#include <RenderablesService.h>
#include <ObstaclesService.h>
#include <SpriteFactory.h>
#include <ObjFactory.h>
#include "SpriteRepository.h"
#include "ObjRepository.h"
#include "PlayerService.h"
#include "PlayerRepository.h"
#include "Renderer.h"

int main(int argc, char* args[])
{

    Renderer renderer;
    TextureRepository textureRepository = TextureRepository(&renderer);
    PlayerRepository playerRepository;
    SpriteRepository spriteRepository;
    ObjRepository objRepository;
    PlayerService playerService(&playerRepository);
    RenderablesService renderablesService(&playerRepository, &spriteRepository, &objRepository, &renderer);

    
    SpriteFactory spriteFactory(&textureRepository, &spriteRepository);
    ObjFactory objFactory(&textureRepository, &objRepository, &playerRepository);


    srand((unsigned)time(nullptr)); int random = rand();  //// RANDOM NUMBER GENERATOR

    for (int i = 0; i <= renderer.getScreenWidth(); i += 64) {
        for (int y = 0; y <= renderer.getScreenHeight(); y += 64) {
            spriteFactory.grass(i, y);
        }
    }

    for (int i = 0; i <= 45; i++) {
        int x = -64 + rand() % (renderer.getScreenWidth() + 128);
        int y = -64 + rand() % (renderer.getScreenHeight() + 128);
        objFactory.rock(x, y);
    }

    for (int i = 0; i <= 45; i++) {
        int x = -64 + rand() % (renderer.getScreenWidth() + 128);
        int y = -64 + rand() % (renderer.getScreenHeight() + 128);
        objFactory.tree(x, y);
    }

    objFactory.makePlayer(314, 181);


    if (renderer.getWindow()) {
        bool run = true;
        SDL_Event event;

        while (run) {

            //KEY STROKES ACTIONS
            while (SDL_PollEvent(&event)) {
                if (event.type == SDL_QUIT)
                    run = false;
            }

            //KEY STATES ACTIONS
            const Uint8* currentKeyStates = SDL_GetKeyboardState(nullptr);
            playerService.handle(currentKeyStates);

            //RENDERING
            SDL_RenderClear(renderer.getRenderer());

            std::vector<Obj*> objsVect = objRepository.getAll();

            playerService.getPlayer()->move(getObstacles(objsVect, playerService.getPlayer()));

            renderablesService.renderAll();
            SDL_RenderPresent(renderer.getRenderer());
        }
    }
    close(renderer.getWindow()); //textures not freed/destroyed
    return 0;
}
