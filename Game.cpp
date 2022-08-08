#include "Game.h"

 bool Game::Init()
 {
    bool ok = true;

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cout << "Can't init SDL: " << SDL_GetError() << std::endl;
    }

    win = SDL_CreateWindow("Примитивы", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (win == NULL) {
        std::cout << "Can't create window: " << SDL_GetError() << std::endl;
        ok = false;
    }

    ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
    if (ren == NULL) {
        std::cout << "Can't create renderer: " << SDL_GetError() << std::endl;
        ok = false;
    }
    return ok;
}

void Game::OnEvent()
{

}


void Game::OnLoop()
{

}

void Game::OnRender()
{

}


void Game::Quit()
{
    SDL_DestroyWindow(win);
    win = NULL;

    SDL_DestroyRenderer(ren);
    ren = NULL;

    SDL_Quit();
}