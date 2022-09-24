#include "BonusSecondBall.h"

BonusSecondBall::BonusSecondBall(int x, int y, BallForBonus* ball)
{
	this->x = x;
	this->y = y;
	this->ball = ball;
}


BonusSecondBall::~BonusSecondBall()
{
	this->ball = NULL;
}


void BonusSecondBall::MakeAction()
{
	ball->Activate();
}