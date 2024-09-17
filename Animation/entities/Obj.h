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

	Obj(int x, int y, Surface surface, std::vector<SDL_Texture*> textures, SDL_Rect rectangle) : Sprite(x, y, surface, textures)
	{
		rectangle.x += getX();
		rectangle.y += getY();
		this->rectangle = rectangle;
	}

	SDL_Rect& getRectangle() {
		return rectangle;
	}
};
#endif
