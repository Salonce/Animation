#ifndef TEXTURE_REPOSITORY_H
#define TEXTURE_REPOSITORY_H

#include <SDL.h>
#include <SDL_image.h>
#include <vector>
#include <string>
#include <format>
#include <unordered_map>

#include <Renderer.h>



class TextureRepository {
   
    std::unordered_map<std::string, SDL_Texture*> textures;
    std::unordered_map<std::string, std::vector<SDL_Texture*>> textureBag;
    Renderer* renderer;

    SDL_Texture* loadTexture(std::string file_name);
    SDL_Surface* loadSurface(const std::string& file_name);

public:
    TextureRepository(Renderer* renderer);

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

    void addBag(const std::string& textureName, const std::vector<std::string>& textureKeys);
};



#endif 


//BLENDING
// 
//std::vector<SDL_Texture*> grass_textures;
//SDL_Texture* txr = textureRepository.get("grass");
//SDL_SetTextureBlendMode(txr, SDL_BLENDMODE_BLEND);
//SDL_SetTextureAlphaMod(txr, 125);