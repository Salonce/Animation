#ifndef SPRITE_H
#define SPRITE_H

#include <SDL.h>
#include <SDL_image.h>
#include <vector>

//interfaces/enums
#include "Renderable.h"
#include "Surface.h"

#include "SpriteRepository.h"
#include <string>

class Sprite : public Renderable {

protected:
	std::vector<SDL_Texture*> textures;
	Surface surface;
	
	int x;
	int y;

	int img_width = 64;
	int img_height = 64;

	int texture_stage = 0;

public:

	Sprite();

	Sprite(int x, int y, Surface surface, std::vector<SDL_Texture*> textures) {
		this->surface = surface;
		this->textures = textures;
		setX(x);
		setY(y);
	}

	int getX() const override { return x; }
	int getY() const override { return y; }
	void setX(int newX) override { x = newX; }
	void setY(int newY) override { y = newY; }
	int getSurface() override { return surface; };
	int getWidth() const override { return img_width; }
	int getHeight() const override { return img_height; }

	SDL_Texture* getTexture();

	void animate() override;
};
#endif

