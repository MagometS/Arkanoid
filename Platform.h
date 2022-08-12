#ifndef PLATFORM_H
#define PLATFORM_H

#include <SDL.h>
#include "Shape.h"
#include "ScreenConst.h"
#include "Obstacle.h"

class Platform : public Shape, public Obstacle
{
public:
	Platform(int x, int y);
	void Move();
	void OnEvent(SDL_Event& e);
	void Render(SDL_Renderer* ren);
	void OnCollision() { return; }
private:
	double velocity = 0;
	int maxVel = 10;
	SDL_Rect rect;
};
#endif
