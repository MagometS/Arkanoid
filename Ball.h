#ifndef BALL_H
#define BALL_H

#include <SDL.h>
#include <vector>
#include "Point.h"
#include "ScreenConst.h"
#include "Player.h"
#include "SDL_Circle.h"
#include "Obstacle.h"
#include "Color.h"

class Ball 
{

public:


	Ball();
	Ball(int x, int y);


	void Move(std::vector<Obstacle*>& obstacles,Player& player);


	bool CheckCollision(Obstacle* obstacle);
	bool CheckCollision(Ball& ball);


	void StartPosition();


	void Render(SDL_Renderer* ren);


	Point GetPosition() { return position; }


	int GetRadius() { return radius; }


	void SetColor(int r, int g, int b, int a);


private:


	Point position;
	Point velocity = { 0,0 };
	int radius = 5;
	int maxVel = 8;
	Color color = { 127, 255, 212, 0 };


	bool isTouchedFloor = false;
};
#endif
