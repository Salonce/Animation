#ifndef PLAYER_H 
#define PLAYER_H 

#include <vector>

//enums/interfaces
#include "Obstacle.h"
#include "Renderable.h"
#include "Direction.h"
#include "Surface.h"
#include <TextureRepository.h>

class Player : public Renderable, public Obstacle {

private:
	static TextureRepository* textureRepository;
	std::vector<SDL_Texture*> textures;

	int x = 0;
	int y = 0;

	int img_width = 64;
	int img_height = 64;

	int velocity_y = 0;
	int velocity_x = 0;

	SDL_Rect rect;

public:

	Player(int x, int y, const std::string& bag_name) {
		setX(x);
		setY(y);
		this->textures = textureRepository->getBag(bag_name);
	}
	
	int getX() const override {return x;}
	int getY() const override {return y;}
	void setX(int x) override {this->x = x;}
	void setY(int y) override {this->y = y;}
	int getSurface() override { return ON_FLOOR; }
	int getWidth() const override {return img_width;}
	int getHeight() const  override {return img_height;}

	void animate() override {};

	void move(std::vector<Obstacle*>* obstaclesVector) ;

	//MEMORY BOY
	SDL_Rect& getRectangle() {
		rect.x = x + 18;
		rect.y = y + 61;
		rect.w = 28;
		rect.h = 3;
		return rect;
	}

	SDL_Texture* getTexture() override { 
		if (this->textures.empty()) {
			printf("character Sprite texture is empty\n");
		};
		return this->textures[0]; 
	}

	void handleEvent(Direction direction);
	static bool initialize(TextureRepository* textureRepository);
};

#endif 