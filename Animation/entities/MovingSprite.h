#ifndef MOVING_SPRITE_H
#define MOVING_SPRITE_H

#include <SDL_render.h>
#include <Sprite.h>
#include <functional>
#include "Surface.h"
#include <vector>


class MovingSprite : public Sprite {

	using AutoMover = std::function<void(int&, int&)>;
	AutoMover autoMover;


public:
	MovingSprite(int x, int y, Surface surface, std::vector<SDL_Texture*> textures, AutoMover autoMover) :
		Sprite(x, y, surface, textures), autoMover(autoMover){
		
	};
	

	void autoMove() {
		autoMover(x, y);
	}

	bool autoRemove() {
		if (x < -100 || x > 1600 || y < -100 || y > 1600)
			return true;
		return false;
	}

};





#endif