#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <format>
#include <vector>

#include <TextureRepository.h>
#include <Renderer.h>

TextureRepository::TextureRepository(Renderer* renderer) {
    this->renderer = renderer;

    addBag("tree", { "tree.png", "tree2.png" });
    addBag("grass", { "grass.png" });
    addBag("rock", { "rock.png" });
    addBag("player", { "player.png" });
    addBag("willow", { "willow1.png", "willow2.png"});
    addBag("puddle", { "puddle1.png", "puddle2.png" });
    addBag("clouds", { "clouds.png" });


}
void TextureRepository::addBag(const std::string& textureName, const std::vector<std::string>& textureKeys) {
    std::vector<SDL_Texture*> texturesList;
    for (const auto& key : textureKeys) {
        if (textures.count(key) == 0)
            this->textures[key] = loadTexture(key);
        texturesList.push_back(this->textures[key]);
    }
    textureBag[textureName] = texturesList;
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

SDL_Surface* TextureRepository::loadSurface(const std::string& file_name) {
    std::string fullPath = "images/" + file_name;
    SDL_Surface* gHelloWorld = SDL_LoadBMP(fullPath.c_str());
    if (gHelloWorld == nullptr)
        printf("Unable to load image %s! SDL Error: %s\n", "images/demo.bmp", SDL_GetError());
    return gHelloWorld;
}