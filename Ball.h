#ifndef BALL_H
#define BALL_H

#include <SDL.h>
#include "Shape.h"
#include "Point.h"
#include "ScreenConst.h"
#include "Player.h"
#include "SDL_Circle.h"

class Ball : public Shape
{
public:
	Ball(int x, int y);
	void Move();
	void OnCollision(Shape& Obstacle);
	void StartPosition();
	void Render(SDL_Renderer* ren);

private:
	Point position ;
	Point velocity = { 0,0 };
	int radius = 5;
	int maxVel = 10;
	SDL_Circle circle{ position.x,position.y,radius };


	bool isTouchedFloor = false;
};
#endif
