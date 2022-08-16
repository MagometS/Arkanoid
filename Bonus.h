#ifndef BONUS_H
#define BONUS_H

#include <SDL.h>
#include "Platform.h"
#include "Color.h"

class Bonus : SDL_Rect
{
public:


	void Move() { y += velocity; }


	bool isActivated() { return _isActivated; }


	virtual void MakeAction() = 0;


	void Render(SDL_Renderer* ren);


	void Activate() { _isActivated = true; }


	void Destroy() { _isActivated = false; }

private:


	bool _isActivated = false;
	int velocity = 5;
	Color color = { 255, 255, 0 ,0 };
};

#endif
