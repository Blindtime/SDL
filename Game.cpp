#include "Game.hpp"
#include "TextureManager.hpp"
#include <stdio.h>

SDL_Renderer* Game::renderer = nullptr;
SDL_Texture* tex = nullptr;

Game::Game(){}

Game::~Game(){}

void Game::init(){
    isRunning = true;
    
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0){
        isRunning = false;
    }

     if(IMG_Init(IMG_INIT_PNG) != 0){
        isRunning = false;
        printf("sIMG_Init: %s\n", SDL_GetError());
    }

    if(SDL_CreateWindowAndRenderer(600, 480, SDL_WINDOW_SHOWN, &window, &renderer) != 0){
        isRunning = false;
    }
}

bool Game::running() const{
    return isRunning;
}

void Game::handleEvents(){
    SDL_Event event;
    SDL_PollEvent(&event);


    if(event.type == SDL_QUIT){
        isRunning = false;
    }
}

void Game::update(){
}

void Game::render(){
    SDL_RenderClear(renderer);

    SDL_Rect src;
    src.h = src.w = 32;
    src.x = src.y = 32;

    SDL_Rect dst;
    dst.h = dst.w = 32;
    dst.x = dst.y = 32;
    
    tex = TextureManager::LoadTexture("assets/texture.png");
    TextureManager::Draw(tex, src, dst);

    SDL_RenderPresent(renderer);
}

void Game::clean(){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}