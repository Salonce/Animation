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

#include "TextureRepository.h"
#include "CompareRenderables.h"
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
#include "MovingSpriteRepository.h"
#include <MovablesService.h>

int main(int argc, char* args[])
{

    Renderer renderer;
    TextureRepository textureRepository = TextureRepository(&renderer);
    PlayerRepository playerRepository;
    SpriteRepository spriteRepository;
    MovingSpriteRepository movingSpriteRepository;
    ObjRepository objRepository;
    SpriteFactory spriteFactory(&textureRepository, &spriteRepository, &movingSpriteRepository);
    ObjFactory objFactory(&textureRepository, &objRepository, &playerRepository);


    ObstaclesService obstaclesService(&objRepository, &playerRepository);
    PlayerService playerService(&playerRepository, &obstaclesService);
    MovablesService movablesService(&movingSpriteRepository);
    RenderablesService renderablesService(&playerRepository, &spriteRepository, &objRepository, &movingSpriteRepository ,&renderer);
    


    srand((unsigned)time(nullptr)); int random = rand();  //// RANDOM NUMBER GENERATOR

    for (int i = 0; i <= renderer.getScreenWidth(); i += 64) {
        for (int y = 0; y <= renderer.getScreenHeight(); y += 64) {
            spriteFactory.grass(i, y);
        }
    }

    for (int i = 0; i < 25; i++) {
        int x = -64 + rand() % (renderer.getScreenWidth());
        int y = -64 + rand() % (renderer.getScreenHeight());
        objFactory.rock(x, y);
    }

    for (int i = 0; i < 25; i++) {
        int x = -64 + rand() % (renderer.getScreenWidth());
        int y = -64 + rand() % (renderer.getScreenHeight());
        objFactory.tree(x, y);
    }

    for (int i = 0; i < 10; i++) {
        int x = -64 + rand() % (renderer.getScreenWidth());
        int y = -64 + rand() % (renderer.getScreenHeight());
        objFactory.willow(x, y);
    }

    for (int i = 0; i < 10; i++) {
        int x = -64 + rand() % (renderer.getScreenWidth());
        int y = -64 + rand() % (renderer.getScreenHeight());
        objFactory.puddle(x, y);
    }

    objFactory.makePlayer(314, 181);


    bool run = true;
    SDL_Event event;

    while (run) {
        
        while (SDL_PollEvent(&event)) { //KEY STROKES ACTIONS
            if (event.type == SDL_QUIT)
                run = false;
        } 

        const Uint8* currentKeyStates = SDL_GetKeyboardState(nullptr); //KEY STATES ACTIONS
        playerService.handle(currentKeyStates); 

        //GENERATE RANDOM 
        for (int i = 0; i <= 10; i++) {
            int x = renderer.getScreenWidth() + 500;
            int y = -64 + rand() % (renderer.getScreenHeight() + 128);
            spriteFactory.clouds(x, y);
        }



        //RENDERING START
        renderer.clearBackBuffer(); 
        playerService.playerMoves();
        movablesService.autoMoveAll();
        renderablesService.renderAll();
        

        renderer.switchBuffers(); 
        //RENDERING END
    }

    renderer.close(); //textures not freed/destroyed
    return 0;
}
