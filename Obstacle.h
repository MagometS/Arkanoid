#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <SDL.h>
#include "Shape.h"
#include "Player.h"


class Ball;


class Obstacle : public SDL_Rect, public Shape
{
public:
	virtual void OnCollision(Player& player, Ball* ball) = 0;
	bool isDestroyed()const { return _isDestroyed; }

protected:
	bool _isDestroyed = false;

};
#endif

