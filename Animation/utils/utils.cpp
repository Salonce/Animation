#include <SDL.h>
#include <SDL_image.h>
#include <string>


#include <stdio.h>
#include "sdl_util.h"
#include "Texture.h"

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

void close(SDL_Window* window) // textures not destroyed
{
    if (window != nullptr) {
        SDL_DestroyWindow(window);
    }
    SDL_Quit();
}

SDL_Renderer* initializeRenderer(SDL_Window* sdl_window) {
    SDL_Renderer* renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == NULL)
        printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
    return renderer;
}

SDL_Surface* loadSurface(const std::string& file_name) {
    std::string fullPath = "images/" + file_name;
    SDL_Surface* gHelloWorld = SDL_LoadBMP(fullPath.c_str());
    if (gHelloWorld == nullptr)
        printf("Unable to load image %s! SDL Error: %s\n", "images/demo.bmp", SDL_GetError());
    return gHelloWorld;
}


SDL_Texture* loadTexture(SDL_Renderer* renderer, std::string file_name)
{
    std::string fullPath = "images/" + file_name;
    SDL_Texture* newTexture = nullptr;
    SDL_Surface* loadedSurface = IMG_Load(fullPath.c_str());
    if (loadedSurface == nullptr)
        printf("Unable to load image %s! SDL_image Error: %s\n", file_name.c_str(), IMG_GetError());
    else
    {
        SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0xFF, 0, 0xFF));
        newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
        if (newTexture == NULL)
            printf("Unable to create texture from %s! SDL Error: %s\n", file_name.c_str(), SDL_GetError());
        SDL_FreeSurface(loadedSurface);
    }
    return newTexture;
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

    SDL_RenderCopy(renderer, texture->getTexture(), NULL, &viewport);
}





std::vector<Obstacle*>* getObstacles(std::vector<Obj*> objectsVector, Player* character) {

    std::vector<Obstacle*>* obstaclesVector = new std::vector<Obstacle*>;

    obstaclesVector->push_back(character);

    for (Obj* obj : objectsVector) {
        obstaclesVector->push_back(obj);
    }

    return obstaclesVector;
}

std::vector<Renderable*> getRenderable(std::vector<Sprite*> spritesVector, std::vector<Obj*> objectsVector, Player* character) {

    std::vector<Renderable*> renderablesVector;

    renderablesVector.push_back(character);

    for (Obj* obj : objectsVector) {
        renderablesVector.push_back(obj);
    }

    for (Renderable* renderable : spritesVector) {
        renderablesVector.push_back(renderable);
    }

    return renderablesVector;
}

