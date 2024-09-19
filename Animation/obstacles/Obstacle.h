#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <SDL_rect.h>

class Obstacle {

	public:
		virtual SDL_Rect& getRectangle() = 0;
};

#endif