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

#include "Direction.h"
#include "Player.h"
#include "Sprite.h"
#include "TextureRepository.h"
#include "CompareRenderables.h"
#include "Surface.h"
#include "Obj.h"
#include "sdl_util.h"
#include "Renderable.h"

int main(int argc, char* args[])
{
    const int screen_width = 1220;
    const int screen_height = 800;
    SDL_Window* window = initialize_window(screen_width, screen_height);
    SDL_Renderer* renderer = initializeRenderer(window);
    initializeSDL_Image(); // works without it... not sure if needed
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

    std::vector<Sprite*> spritesVector;
    std::vector<Obj*> objsVector;

    Sprite::initializeSprites(&spritesVector);
    Obj::initializeObjs(&objsVector);

    TextureRepository textureRepository = TextureRepository(renderer);

    SDL_Rect rock_rect = SDL_Rect(18, 59, 32, 5);
    SDL_Rect tree_rect = SDL_Rect(18, 59, 25, 5);

    srand((unsigned)time(nullptr)); int random = rand();  //// RANDOM NUMBER GENERATOR

    for (int i = 0; i <= screen_width; i += 64) {
        for (int j = 0; j <= screen_height; j += 64) {
            new Sprite(i, j, FLOOR, *textureRepository.getBag("grass"));
        }
    }

    for (int i = 0; i <= 25; i++) {
        int x = -64 + rand() % (screen_width + 128);
        int y = -64 + rand() % (screen_height + 128);
        new Obj(x, y, ON_FLOOR, *textureRepository.getBag("rock"), rock_rect);
    }

    for (int i = 0; i <= 25; i++) {
        int x = -64 + rand() % (screen_width + 128);
        int y = -64 + rand() % (screen_height + 128);
        //new Obj(x, y, ON_FLOOR, tree_textures, tree_rect);
        new Obj(x, y, ON_FLOOR, *textureRepository.getBag("tree"), tree_rect);
    }

    Player* character = new Player(215, 53, *textureRepository.getBag("player"));

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
            if (currentKeyStates[SDL_SCANCODE_UP]) character->handleEvent(Direction::UP);
            if (currentKeyStates[SDL_SCANCODE_DOWN]) character->handleEvent(Direction::DOWN);
            if (currentKeyStates[SDL_SCANCODE_LEFT]) character->handleEvent(Direction::LEFT);
            if (currentKeyStates[SDL_SCANCODE_RIGHT]) character->handleEvent(Direction::RIGHT);
            if (!(currentKeyStates[SDL_SCANCODE_UP]) && !(currentKeyStates[SDL_SCANCODE_DOWN])) character->handleEvent(Direction::SLOW_DOWN);
            if (!(currentKeyStates[SDL_SCANCODE_LEFT]) && !(currentKeyStates[SDL_SCANCODE_RIGHT])) character->handleEvent(Direction::SLOW_DOWN_HORIZONTALLY);

            SDL_RenderClear(renderer);
            character->move(getObstacles(objsVector, character));
            std::vector<Renderable*> renderables = getRenderable(spritesVector, objsVector, character);
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
