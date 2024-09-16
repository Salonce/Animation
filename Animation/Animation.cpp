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

int main(int argc, char* args[])
{
    const int screen_width = 1220;
    const int screen_height = 800;
    SDL_Window* window = initialize_window(screen_width, screen_height);
    SDL_Renderer* renderer = initializeRenderer(window);
    initializeSDL_Image(); // works without it... not sure if needed
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

    SpriteRepository spriteRepository;
    ObjRepository objRepository;
    PlayerService playerService;
    RenderablesService renderablesService(&playerService, &spriteRepository, &objRepository);

    TextureRepository textureRepository = TextureRepository(renderer);
    SpriteFactory spriteFactory(&textureRepository, &spriteRepository);
    ObjFactory objFactory(&textureRepository, &objRepository, &playerService);


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

    Player* player = new Player(215, 53, textureRepository.getBag("player"));



    if (window) {
        bool run = true;
        SDL_Event event;

        while (run) {
            std::priority_queue<Renderable*, std::vector<Renderable*>, CompareRenderables> pq;
            while (SDL_PollEvent(&event)) {

                if (event.type == SDL_QUIT)
                    run = false;
            }
            const Uint8* currentKeyStates = SDL_GetKeyboardState(nullptr);
            if (currentKeyStates[SDL_SCANCODE_UP]) player->handleEvent(Direction::UP);
            if (currentKeyStates[SDL_SCANCODE_DOWN]) player->handleEvent(Direction::DOWN);
            if (currentKeyStates[SDL_SCANCODE_LEFT]) player->handleEvent(Direction::LEFT);
            if (currentKeyStates[SDL_SCANCODE_RIGHT]) player->handleEvent(Direction::RIGHT);
            if (!(currentKeyStates[SDL_SCANCODE_UP]) && !(currentKeyStates[SDL_SCANCODE_DOWN])) player->handleEvent(Direction::SLOW_DOWN);
            if (!(currentKeyStates[SDL_SCANCODE_LEFT]) && !(currentKeyStates[SDL_SCANCODE_RIGHT])) player->handleEvent(Direction::SLOW_DOWN_HORIZONTALLY);

            SDL_RenderClear(renderer);

            std::vector<Obj*> objsVect = objRepository.getAll();
            std::vector<Sprite*> sprites = spriteRepository.getAll();

            player->move(getObstacles(objsVect, player));

            std::vector<Renderable*> renderables = getRenderables(sprites, objsVect, player);


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
