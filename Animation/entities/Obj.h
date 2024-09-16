#ifndef OBJ_H 
#define OBJ_H 

#include <SDL.h>
#include <vector>

#include "Sprite.h"
#include "Obstacle.h"
#include "Surface.h"

class Obj : public Sprite, public Obstacle {

	static std::vector<Obj*>* objsVector;
	SDL_Rect rectangle;

public:

	Obj(int x, int y, Surface surface, const std::string& bag_name, SDL_Rect rectangle)

	{
		this->surface = surface;
		this->textures = textureRepository->getBag(bag_name);
		setX(x);
		setY(y);

		rectangle.x += getX();
		rectangle.y += getY();
		this->rectangle = rectangle;
		if (objsVector != nullptr) { objsVector->push_back(this); }
		else printf("objsVector is not initialized\n");

		printf("x: %d\n", rectangle.x);
		printf("y: %d\n", rectangle.y);
		printf("rect width: %d\n", rectangle.w);
		printf("rect height: %d\n", rectangle.h);
	}

	SDL_Rect& getRectangle() {
		return rectangle;
	}

	static bool initializeObjs(std::vector<Obj*>* objsVector);
};
#endif
