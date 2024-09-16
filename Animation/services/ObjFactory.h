#ifndef OBJ_FACTORY_H
#define OBJ_FACTORY_H

#include <Surface.h>
#include <Obj.h>
#include <SDL_rect.h>

struct ObjFactory {

	void rock(int x, int y) {
		new Obj(x, y, ON_FLOOR, "rock", SDL_Rect(18, 59, 32, 5));;
	}

	void tree(int x, int y) {
		new Obj(x, y, ON_FLOOR, "tree", SDL_Rect(18, 59, 25, 5));;
	}
};




#endif