#ifndef RENDERER_H
#define RENDERER_H

#include <SDL.h>
#include <stdio.h>
#include <SDL_image.h>

class Renderer {

	SDL_Window* window = nullptr; 
	SDL_Renderer* renderer = nullptr;
    int screen_width = 1220;
    int screen_height = 800;

public:

    Renderer() {
        initialize_window(1220, 800);
        initializeRenderer();
        initializeSDL_Image();
        SDL_SetRenderDrawColor(this->renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    }

    SDL_Renderer*& getRenderer() {
        return this->renderer;
    }

    SDL_Window*& getWindow() {
        return this->window;
    }

    int getScreenWidth() {
        return this->screen_width;
    }

    int getScreenHeight() {
        return this->screen_height;
    }

    void clearBackBuffer() {
        SDL_RenderClear(renderer);
    }
    void switchBuffers() {
        SDL_RenderPresent(renderer);
    }


    void initialize_window(int screen_width, int screen_height) {
        if (SDL_Init(SDL_INIT_VIDEO) < 0)
            printf("SDL could not initialize the window! SDL_Error: %s\n", SDL_GetError());
        else {
            this->window = SDL_CreateWindow("Monkey Island", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screen_width, screen_height, SDL_WINDOW_SHOWN);
            if (this->window == nullptr)
                printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        }
    }

    void initializeRenderer() {
        this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        if (renderer == nullptr)
            printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
    }

    void initializeSDL_Image() {
        int imgFlags = IMG_INIT_PNG;
        if (!(IMG_Init(imgFlags) & imgFlags))
            printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
    };

    void close() // textures not destroyed
    {
        if (this->window != nullptr) {
            SDL_DestroyWindow(this->window);
        }
        SDL_Quit();
    }
};


#endif // !"RENDERER_H"

