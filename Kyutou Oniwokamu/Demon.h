#pragma once
#include "Character.h"
#include "Peach.h"

class Demon : public Character
{
public:
	void Setter(int hp, int ap);
	bool IsDefend();
	bool IsAngered();

	int Attack(Peach& peach);
	int HeavyAtk(Peach& peach);
	void Defend();
	bool CheckDead();
	bool CheckAngered();
	bool RemoveDefend();
	bool RemovePoisoned();

	void Damaged(int point);
	void Poisoned();
private:
	int turnPois;
	const unsigned int isDead = (1 << 0);
	const unsigned int isDefend = (1 << 1);
	const unsigned int isPoisoned = (1 << 2);
	const unsigned int isAngered = (1 << 3);
};
