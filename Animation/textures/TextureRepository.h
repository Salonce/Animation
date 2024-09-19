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
    Renderer* renderer;

    SDL_Texture* saveTexture(std::string file_name);
    SDL_Surface* loadSurface(const std::string& file_name);

public:
    TextureRepository(Renderer* renderer);

    SDL_Texture* get(const std::string& name) {
        return textures[name];
    }

    /// UNFINISHED
    ~TextureRepository() {
        for (auto& texture : textures) {
            SDL_DestroyTexture(texture.second);
        }
    }

    std::vector<SDL_Texture*> newGroup(const std::vector<std::string>& fileNames);
};



#endif 


//BLENDING
// 
//std::vector<SDL_Texture*> grass_textures;
//SDL_Texture* txr = textureRepository.get("grass");
//SDL_SetTextureBlendMode(txr, SDL_BLENDMODE_BLEND);
//SDL_SetTextureAlphaMod(txr, 125);