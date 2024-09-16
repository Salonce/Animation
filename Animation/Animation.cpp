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

int main(int argc, char* args[])
{
    const int screen_width = 1220;
    const int screen_height = 800;
    SDL_Window* window = initialize_window(screen_width, screen_height);
    SDL_Renderer* renderer = initializeRenderer(window);
    initializeSDL_Image(); // works without it... not sure if needed
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

    TextureRepository textureRepository = TextureRepository(renderer);
    PlayerRepository playerRepository;
    SpriteRepository spriteRepository;
    ObjRepository objRepository;
    printf("PLAYER SET");
    PlayerService playerService(&playerRepository);
    RenderablesService renderablesService(&playerService, &spriteRepository, &objRepository);

    
    SpriteFactory spriteFactory(&textureRepository, &spriteRepository);
    ObjFactory objFactory(&textureRepository, &objRepository, &playerRepository);


    srand((unsigned)time(nullptr)); int random = rand();  //// RANDOM NUMBER GENERATOR

    for (int i = 0; i <= screen_width; i += 64) {
        for (int y = 0; y <= screen_height; y += 64) {
            spriteFactory.grass(i, y);
        }
    }

    for (int i = 0; i <= 45; i++) {
        int x = -64 + rand() % (screen_width + 128);
        int y = -64 + rand() % (screen_height + 128);
        objFactory.rock(x, y);
    }

    for (int i = 0; i <= 45; i++) {
        int x = -64 + rand() % (screen_width + 128);
        int y = -64 + rand() % (screen_height + 128);
        objFactory.tree(x, y);
    }

    objFactory.makePlayer(314, 181);


    if (window) {
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
            SDL_RenderClear(renderer);

            std::vector<Obj*> objsVect = objRepository.getAll();
            std::vector<Sprite*> sprites = spriteRepository.getAll();

            playerService.getPlayer()->move(getObstacles(objsVect, playerService.getPlayer()));

            std::vector<Renderable*> renderables = getRenderables(sprites, objsVect, playerService.getPlayer());


            std::sort(renderables.begin(), renderables.end(), CompareRenderables());

            for (Renderable* renderable : renderables) {
                renderable->animate();
                renderTexture(renderer, renderable);
            }

            SDL_RenderPresent(renderer);
        }
    }
    close(window); //textures not freed/destroyed
    return 0;
}
