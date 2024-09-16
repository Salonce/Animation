#ifndef SPRITE_H
#define SPRITE_H

#include <SDL.h>
#include <vector>

#include "Texture.h"
#include "Player.h"
#include "Surface.h"
#include "Obstacle.h"

class Sprite : public Renderable {

protected:
	std::vector<SDL_Texture*> textures;
	Surface surface;
	static std::vector<Sprite*>* spritesVector;
	
	int x;
	int y;

	int img_width = 64;
	int img_height = 64;

	int texture_stage = 0;

public:

	Sprite() {}

	Sprite(int x, int y, Surface surface, std::vector<SDL_Texture*> &textures) {
		this->surface = surface;
		this->textures = textures;
		this->x = x;
		this->y = y;
		Sprite::spritesVector->push_back(this);
	}


	int getX() const override { return this->x; }
	int getY() const override { return this->y; }
	void setX(int x) override { this->x = x; }
	void setY(int y) override { this->y = y; }
	int getSurface() override { return surface; };
	int getWidth() const override { return img_width; }
	int getHeight() const override { return img_height; }
	SDL_Texture* getTexture() override {
		if (this->textures.empty()) {
			printf("Sprite texture is empty\n");
		};
		//printf("texture stage: %i\n", texture_stage);
		return this->textures.at(texture_stage/60);
	}

	void animate() override {
		size_t size = textures.size();
		if (   ((texture_stage + 1) / 60) < size   )
			texture_stage++;
		else
			texture_stage = 0;
	}

	static bool initializeSprites(std::vector<Sprite*>* spritesVector);
};


#endif

