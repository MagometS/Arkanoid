#include "Player.h"


Player::Player(int health)
{
	this->health = health;
}


void Player::PlusScore(int points)
{
	score += points;
}


void Player::MinusHealth()
{
	health -= 1;
}