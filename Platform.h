#ifndef PLATFORM_H
#define PLATFORM_H

#include <SDL.h>
#include <vector>
#include "ScreenConst.h"
#include "Obstacle.h"
#include "Color.h"
#include "Bonus.h"
#include "Player.h"


class Platform : public Obstacle
{
public:

	
	Platform();
	Platform(int x, int y);


	void Move(std::vector<Bonus*> bonuses);


	void OnEvent(SDL_Event& e);


	void Render(SDL_Renderer* ren) override;


	void OnCollision(Player& player) override { return; }


	bool CheckCollision(typename Bonus* bonus);


private:


	double velocity = 0;
	int maxVel = 10;
	Color color = { 32, 178, 170, 0};
};
#endif
