#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <SDL.h>

class Obstacle : public SDL_Rect
{
public:
	virtual void OnCollision() = 0;
};
#endif

