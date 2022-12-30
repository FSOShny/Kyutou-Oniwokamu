#pragma once
#include "Character.h"
#include "Demon.h"

class Peach : public Character
{
public:
	void Setter(int hp, int ap);
	void Attack(Demon& demon);
	void PoisonAtk(Demon& demon);
	void Defend();
	void Recover();
	bool StateCheck();
private:
	const unsigned int isDeath = (1 << 0);
	const unsigned int isDefend = (1 << 1);
};
