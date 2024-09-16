#ifndef OBJ_H 
#define OBJ_H 

#include <SDL.h>
#include <vector>

#include "Sprite.h"
#include "Obstacle.h"
#include "Surface.h"

class Obj : public Sprite, public Obstacle {
	SDL_Rect rectangle;

public:

	Obj(int x, int y, Surface surface, std::vector<SDL_Texture*> textures, SDL_Rect rectangle)

	{
		this->surface = surface;
		this->textures = textures;
		setX(x);
		setY(y);

		rectangle.x += getX();
		rectangle.y += getY();
		this->rectangle = rectangle;

		//printf("x: %d, y: %d, w: %d, h: %d\n", rectangle.x, rectangle.y, rectangle.w, rectangle.h);
	}

	SDL_Rect& getRectangle() {
		return rectangle;
	}
};
#endif
