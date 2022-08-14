#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <SDL.h>

class Obstacle : public SDL_Rect
{
public:
	virtual void OnCollision() = 0;
	bool isDestroyed()const { return _isDestroyed; }
	virtual void Render(SDL_Renderer* ren) = 0;

protected:
	bool _isDestroyed = false;

};
#endif

