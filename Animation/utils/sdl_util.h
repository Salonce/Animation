#ifndef SDL_UTIL_H
#define SDL_UTIL_H

#include <string>
#include <vector>

class Sprite;
class Obstacle;
class Player;
class Obj;

void close(SDL_Window* window);
std::vector<Obstacle*>* getObstacles(std::vector<Obj*> objectsVector, Player* character);
std::vector<Renderable*> getRenderable(std::vector<Sprite*> spritesVector, std::vector<Obj*> objectsVector, Player* character);
SDL_Window* initialize_window(int screen_width, int screen_height);
SDL_Surface* loadSurface(const std::string& file_name);
SDL_Texture* loadTexture(SDL_Renderer* renderer, std::string file_name);
SDL_Renderer* initializeRenderer(SDL_Window* sdl_window);
bool initializeSDL_Image();
void renderTexture(SDL_Renderer* renderer, Renderable* texture);
#endif