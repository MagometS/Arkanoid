#ifndef PLATFORM_H
#define PLATFORM_H

#include "Shape.h"
#include <SDL.h>
#include "ScreenConst.h"

class Platform : public Shape, public SDL_Rect
{
public:
	Platform(int x, int y);
	void Move();
	void OnEvent(SDL_Event& e);
	void Render(SDL_Renderer* ren);


private:
	double velocity = 0;
	int maxVel = 10;
	SDL_Rect rect;
};
#endif
