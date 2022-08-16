#ifndef PLATFORM_H
#define PLATFORM_H

#include <SDL.h>
#include "ScreenConst.h"
#include "Obstacle.h"
#include "Color.h"
#include "Player.h"

class Platform : public Obstacle
{
public:

	
	Platform();
	Platform(int x, int y);


	void Move();


	void OnEvent(SDL_Event& e);


	void Render(SDL_Renderer* ren) override;


	void OnCollision(Player& player) override { return; }


private:


	double velocity = 0;
	int maxVel = 10;
	Color color = { 32, 178, 170, 0};
};
#endif
