
#ifndef SPRITE_FACTORY_H
#define SPRITE_FACTORY_H
#include <Surface.h>
#include <Sprite.h>

struct SpriteFactory {

	void grass(int x, int y) {
		new Sprite(x, y, FLOOR, "grass");
	}

};





#endif