#include <TextureRepository.h>

#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <format>


SDL_Texture* TextureRepository::loadTexture(SDL_Renderer* renderer, std::string file_name)
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
        if (newTexture == nullptr)
            printf("Unable to create texture from %s! SDL Error: %s\n", file_name.c_str(), SDL_GetError());
        SDL_FreeSurface(loadedSurface);
    }
    return newTexture;
}

SDL_Surface* TextureRepository::loadSurface(const std::string& file_name) {
    std::string fullPath = "images/" + file_name;
    SDL_Surface* gHelloWorld = SDL_LoadBMP(fullPath.c_str());
    if (gHelloWorld == nullptr)
        printf("Unable to load image %s! SDL Error: %s\n", "images/demo.bmp", SDL_GetError());
    return gHelloWorld;
}