#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <stdio.h>
#include <vector>
#include <cstdio>


//interface
#include "sdl_util.h"
#include "Renderable.h"


SDL_Window* initialize_window(int screen_width, int screen_height){

    SDL_Window* sdl_window = nullptr;

    if (SDL_Init(SDL_INIT_VIDEO) < 0){
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    }

    else{
        sdl_window = SDL_CreateWindow("Monkey Island", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screen_width, screen_height, SDL_WINDOW_SHOWN);
        if (sdl_window == nullptr)
            printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
    }
    return sdl_window;
}

SDL_Renderer* initializeRenderer(SDL_Window* sdl_window) {
    SDL_Renderer* renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr)
        printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
    return renderer;
}

bool initializeSDL_Image() {
    int imgFlags = IMG_INIT_PNG;
    if (!(IMG_Init(imgFlags) & imgFlags)) {
        printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
        return false;
    }
    return true;
};

void renderTexture(SDL_Renderer* renderer, Renderable* texture) {
    SDL_Rect viewport;
    viewport.x = texture->getX();
    viewport.y = texture->getY();
    viewport.w = texture->getWidth();
    viewport.h = texture->getHeight();

    //printf("x: %i, \n", viewport->x);
    //printf("y: %i, \n", viewport->y);
    //printf("w: %i, \n", viewport->w);
    //printf("h: %i, \n", viewport->h);

    SDL_RenderCopy(renderer, texture->getTexture(), nullptr, &viewport);
}

void close(SDL_Window* window) // textures not destroyed
{
    if (window != nullptr) {
        SDL_DestroyWindow(window);
    }
    SDL_Quit();
}