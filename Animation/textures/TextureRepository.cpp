#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <format>
#include <vector>

#include <TextureRepository.h>
#include <Renderer.h>

TextureRepository::TextureRepository(Renderer* renderer) {
    this->renderer = renderer;

    this->textures["tree"] = loadTexture(renderer, "tree.png");
    this->textures["tree2"] = loadTexture(renderer, "tree2.png");
    this->textures["grass"] = loadTexture(renderer, "grass.png");
    this->textures["rock"] = loadTexture(renderer, "rock.png");
    this->textures["player"] = loadTexture(renderer, "player.png");
    this->textures["willow1"] = loadTexture(renderer, "willow1.png");
    this->textures["willow2"] = loadTexture(renderer, "willow2.png");
    this->textures["puddle1"] = loadTexture(renderer, "puddle1.png");
    this->textures["puddle2"] = loadTexture(renderer, "puddle2.png");
    this->textures["clouds"] = loadTexture(renderer, "clouds.png");

    addBag("tree", { "tree", "tree2" });
    addBag("grass", { "grass" });
    addBag("rock", { "rock" });
    addBag("player", { "player" });
    addBag("willow", { "willow1", "willow2"});
    addBag("puddle", { "puddle1", "puddle2" });
    addBag("clouds", { "clouds" });


}
void TextureRepository::addBag(const std::string& textureName, const std::vector<std::string>& textureKeys) {
    std::vector<SDL_Texture*> texturesList;
    for (const auto& key : textureKeys) {
        texturesList.push_back(this->textures[key]);
    }
    textureBag[textureName] = texturesList;
}


SDL_Texture* TextureRepository::loadTexture(Renderer* renderer, std::string file_name)
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