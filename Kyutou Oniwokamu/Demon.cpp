#include "Demon.h"

Demon::Demon()
	: poisonedTurn(0)
{
}

void Demon::Setter(int hp, int ap)
{
	this->hp = hp;
	maxHp = hp;
	this->ap = ap;
}

int Demon::Damaged(int damage)
{
	hp -= damage;
	if (hp <= 0)
	{
		state |= isDead;
	}
	return damage;
}

bool Demon::CheckDead()
{
	return (state & isDead);
}

int Demon::Attack()
{
	return ap;
}

int Demon::HeavyAtk()
{
	return ap * 2;
}

bool Demon::CheckEnraged()
{
	if (!(state & isEnraged))
	{
		if (hp <= maxHp * 0.65)
		{
			state |= isEnraged;
			ap *= 2;
			return true;
		}
	}
	else
	{
		return false;
	}
}

void Demon::Poisoned()
{
	state |= isPoisoned;
	poisonedTurn = 3;
}

bool Demon::CheckPoisoned()
{
	return (state & isPoisoned);
}

bool Demon::RemovePoisoned()
{
	if (state & isPoisoned)
	{
		poisonedTurn--;
		Damaged(1);
		if (poisonedTurn == 0)
		{
			state &= ~isPoisoned;
			return true;
		}
	}
	return false;
}
