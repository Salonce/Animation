#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <format>
#include <vector>

#include <TextureRepository.h>
#include <Renderer.h>
#include <SDL_render.h>

TextureRepository::TextureRepository(Renderer* renderer) {
    this->renderer = renderer;
}

std::vector<SDL_Texture*> TextureRepository::newGroup(const std::vector<std::string>& fileNames) {
    std::vector<SDL_Texture*> texturesList;
    for (const auto& fileName : fileNames) {
        if (textures.count(fileName) == 0)
            this->textures[fileName] = loadAlphaTexture(fileName);
        texturesList.push_back(this->textures[fileName]);
    }
    return texturesList;
}

SDL_Texture* TextureRepository::loadTexture(std::string file_name)
{
    std::string fullPath = "images/" + file_name;
    SDL_Texture* newTexture = nullptr;
    SDL_Surface* loadedSurface = IMG_Load(fullPath.c_str());
    if (loadedSurface == nullptr)
        printf("Unable to load image %s! SDL_image Error: %s\n", file_name.c_str(), IMG_GetError());
    else
    {
        SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0xFF, 0, 0xFF));
        newTexture = SDL_CreateTextureFromSurface(renderer->getRenderer(), loadedSurface);
        if (newTexture == nullptr)
            printf("Unable to create texture from %s! SDL Error: %s\n", file_name.c_str(), SDL_GetError());
        SDL_FreeSurface(loadedSurface);
    }
    return newTexture;
}

SDL_Texture* TextureRepository::loadAlphaTexture(std::string file_name) {
    std::string fullPath = "images/" + file_name;
    SDL_Texture* sdl_texture = IMG_LoadTexture(renderer->getRenderer(), fullPath.c_str());
    if (sdl_texture == NULL) {
        printf("Can't load %s: %s\n", file_name.c_str(), IMG_GetError());
    }
    return sdl_texture;
}

//SDL_Surface* TextureRepository::loadSurface(const std::string& file_name) {
//    std::string fullPath = "images/" + file_name;
//    SDL_Surface* gHelloWorld = SDL_LoadBMP(fullPath.c_str());
//    if (gHelloWorld == nullptr)
//        printf("Unable to load image %s! SDL Error: %s\n", "images/demo.bmp", SDL_GetError());
//    return gHelloWorld;
//}