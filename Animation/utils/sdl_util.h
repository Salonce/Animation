#ifndef SDL_UTIL_H
#define SDL_UTIL_H

#include <string>
#include <vector>

class Sprite;
class Obstacle;
class Player;
class Obj;
class Renderable;

void close(SDL_Window* window);

SDL_Window* initialize_window(int screen_width, int screen_height);
SDL_Renderer* initializeRenderer(SDL_Window* sdl_window);
bool initializeSDL_Image();
void renderTexture(SDL_Renderer* renderer, Renderable* texture);
#endif