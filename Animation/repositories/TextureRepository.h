#ifndef TEXTURE_REPOSITORY_H
#define TEXTURE_REPOSITORY_H

#include <SDL.h>
#include <SDL_image.h>
#include <vector>
#include <string>
#include <format>
#include <unordered_map>

#include "sdl_util.h"



class TextureRepository {
   
    std::unordered_map<std::string, SDL_Texture*> textures;
    std::unordered_map<std::string, std::vector<SDL_Texture*>> textureBag;
    SDL_Renderer* renderer;

    SDL_Texture* loadTexture(SDL_Renderer* renderer, std::string file_name);
    SDL_Surface* loadSurface(const std::string& file_name);

public:
    TextureRepository(SDL_Renderer* renderer) {
        this->renderer = renderer;

        this->textures["tree"] = loadTexture(renderer, "tree.png");
        this->textures["tree2"] = loadTexture(renderer, "tree2.png");
        this->textures["grass"] = loadTexture(renderer, "grass.png");
        this->textures["rock"] = loadTexture(renderer, "rock.png");
        this->textures["player"] = loadTexture(renderer, "player.png");

        std::vector<SDL_Texture*> tree_textures;
        tree_textures.push_back(this->textures["tree"]);
        tree_textures.push_back(this->textures["tree2"]);
        textureBag["tree"] = tree_textures;

        std::vector<SDL_Texture*> grass_textures;
        grass_textures.push_back(this->textures["grass"]);
        textureBag["grass"] = grass_textures;

        std::vector<SDL_Texture*> rock_textures;
        rock_textures.push_back(this->textures["rock"]);
        textureBag["rock"] = rock_textures;

        std::vector<SDL_Texture*> player_textures;
        player_textures.push_back(this->textures["player"]);
        textureBag["player"] = player_textures;
    }

    SDL_Texture* get(const std::string& name) {
        return textures[name];
    }

    std::vector<SDL_Texture*>& getBag(const std::string& name) {
        return textureBag[name];
    }

    /// UNFINISHED
    ~TextureRepository() {
        for (auto& texture : textures) {
            SDL_DestroyTexture(texture.second);
        }
    }

};



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

#endif 


//BLENDING
// 
//std::vector<SDL_Texture*> grass_textures;
//SDL_Texture* txr = textureRepository.get("grass");
//SDL_SetTextureBlendMode(txr, SDL_BLENDMODE_BLEND);
//SDL_SetTextureAlphaMod(txr, 125);