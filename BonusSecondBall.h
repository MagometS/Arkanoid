#ifndef BONUSSECONDBALL_H
#define BONUSSECONDBALL_H

#include "Bonus.h"
#include "BallForBonus.h"

class BonusSecondBall : public Bonus
{
public:


	BonusSecondBall(int x, int y, BallForBonus* ball);
	~BonusSecondBall();


	void MakeAction();


private:


	BallForBonus* ball;
};
#endif // !BONUSSECONDBALL_H

