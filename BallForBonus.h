#ifndef BALLFORBONUS
#define BALLFORBONUS

#include "Ball.h"

class BallForBonus : public Ball
{
public:


	bool isActivated() { return _isActivated; }


private:


	bool _isActivated = false;
};

#endif // !BALLFORBONUS
