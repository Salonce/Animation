#ifndef TEXTURE_H
#define TEXTURE_H

#include <SDL_render.h>

class Renderable {

public: 
	virtual void setX(int x) = 0;
	virtual void setY(int y) = 0;

	virtual int getX() const = 0;
	virtual int getY() const = 0;

	virtual int getWidth() const = 0;
	virtual int getHeight() const = 0;

	virtual int getSurface() = 0;
	virtual void animate() = 0;

	virtual SDL_Texture* getTexture() = 0;
};

#endif // !TEXTURE_H