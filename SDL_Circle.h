#ifndef SDL_CIRCLE_H
#define SDL_CIRCLE_H

#include <SDL.h>

int SDL_RenderFillCircle(SDL_Renderer* renderer, int x, int y, int radius);
int SDL_RenderDrawCircle(SDL_Renderer* renderer, int x, int y, int radius);

typedef struct SDL_Circle
{
	int x, y, rad;
}SDL_Circle;

#endif
