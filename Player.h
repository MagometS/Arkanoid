#ifndef PLAYER_H
#define PLAYER_H


class Player
{
public:


	Player() { health = 10; }
	Player(int health);


	void MinusHealth();


	void PlusScore(int points);


	int GetScore()
	{
		return score;
	}


	int GetHealth()
	{
		return health;
	}


private:


	int score = 0;
	int health;
};

#endif PLAYER_H