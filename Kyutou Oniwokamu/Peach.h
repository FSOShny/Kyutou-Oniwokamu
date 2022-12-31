#pragma once
#include "Character.h"
#include "Demon.h"

class Peach : public Character
{
public:
	void Setter(int hp, int ap);
	bool IsDefend();

	int Attack(Demon& demon);
	int PoisonAtk(Demon& demon);
	void Defend();
	int Recover();
	bool CheckDead();
	bool RemoveDefend();

	void Damaged(int point);
private:
	const unsigned int isDead = (1 << 0);
	const unsigned int isDefend = (1 << 1);
};
