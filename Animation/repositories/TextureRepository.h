#ifndef TEXTURE_REPOSITORY_H
#define TEXTURE_REPOSITORY_H

#include <SDL.h>
#include <vector>
#include <string>
#include <format>
#include <unordered_map>

#include "sdl_util.h"



class TextureRepository {
   
    std::unordered_map<std::string, SDL_Texture*> textures;
    std::unordered_map<std::string, std::vector<SDL_Texture*>> textureBag;
    SDL_Renderer* renderer;

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

    //LATER TO DESTROY
    ~TextureRepository() {
        // Free the textures when the repository is destroyed
        for (auto& texture : textures) {
            SDL_DestroyTexture(texture.second);
        }
    }
};

#endif 

//BLENDING
// 
//std::vector<SDL_Texture*> grass_textures;
//SDL_Texture* txr = textureRepository.get("grass");
//SDL_SetTextureBlendMode(txr, SDL_BLENDMODE_BLEND);
//SDL_SetTextureAlphaMod(txr, 125);