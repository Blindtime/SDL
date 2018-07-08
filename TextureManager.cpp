#include "TextureManager.hpp"

SDL_Texture* TextureManager::LoadTexture(const char* textureSheet){
    SDL_Surface* tmpSurface  = IMG_Load(textureSheet);

    printf("Surface: %s\n", SDL_GetError());

    SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::renderer, tmpSurface);
    
    printf("Texture: %s\n", SDL_GetError());
    
    SDL_FreeSurface(tmpSurface);

    return tex;
}

int TextureManager::Draw(SDL_Texture* tex, SDL_Rect srcRect, SDL_Rect destRect){
    return SDL_RenderCopy(Game::renderer, tex, &srcRect, &destRect);
}

