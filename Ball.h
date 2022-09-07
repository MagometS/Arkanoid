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
	void Move(std::vector<Obstacle*>& obstacles, Player& player, Ball* secondBall);


	bool CheckCollision(Obstacle* obstacle);
	bool CheckCollision(Ball* ball);


	void StartPosition();


	void Render(SDL_Renderer* ren);


	Point GetPosition() { return position; }


	int GetRadius() { return radius; }


	Point GetVelocity() { return velocity; }


	void SetColor(int r, int g, int b, int a);


	void SpeedUp(int vel);


	void ChangeDirection_X() { velocity.x = -velocity.x; }
	void ChangeDirection_Y() { velocity.y = -velocity.y; }


private:


	Point position;
	Point velocity = { 0,0 };
	int radius = 5;
	int maxVel = 8;
	bool isTouchedFloor = false;


protected:


	Color color = { 127, 255, 212, 0 };

};
#endif
