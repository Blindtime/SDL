#pragma once
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

class Game{

public:

    Game();
    ~Game();
    void init();
    void handleEvents();
    void update();
    void render();
    void clean();
    bool running() const;

    static SDL_Renderer* renderer;    

private:
    bool isRunning;
    SDL_Window* window;
    
};