#ifndef BALLFORBONUS
#define BALLFORBONUS

#include "Ball.h"

class BallForBonus : public Ball
{
public:


	bool isActivated() { return _isActivated; }


	void Activate() { _isActivated = true; }


private:


	bool _isActivated = false;
};

#endif // !BALLFORBONUS
