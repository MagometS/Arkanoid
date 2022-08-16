#include "Bonus.h"

void Bonus::Render(SDL_Renderer* ren)
{
	SDL_Rect rect = { x,y,w,h };
	SDL_SetRenderDrawColor(ren, color.r, color.g, color.b, color.a);
	SDL_RenderFillRect(ren, &rect);
}