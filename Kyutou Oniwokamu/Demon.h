#pragma once
#include "Character.h"
#include "Peach.h"

class Demon : public Character
{
public:
	void Setter(int hp, int ap);
	void Attack(Peach& peach);
	void HeavyAtk(Peach& peach);
	void Provoke();
	bool StateCheck();
private:
	const unsigned int isDeath = (1 << 0);
	const unsigned int isFurious = (1 << 1);
	const unsigned int isPoisoned = (1 << 2);
};
