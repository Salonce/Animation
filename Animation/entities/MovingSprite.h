#ifndef MOVING_SPRITE_H
#define MOVING_SPRITE_H

#include <Sprite.h>
#include <functional>

class MovingSprite : public Sprite {

	using Mover = std::function<void(int&, int&)>;
	Mover mover;


public:
	MovingSprite(int x, int y, Surface surface, std::vector<SDL_Texture*> textures, Mover mover) :
		Sprite(x, y, surface, textures), mover(mover){
		
	};
	

	void autoMove() {
		mover(x, y);
	}
	void autoRemove();

};





#endif