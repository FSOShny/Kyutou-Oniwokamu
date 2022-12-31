#include "Demon.h"

void Demon::Setter(int hp, int ap)
{
	this->hp = hp;
	maxHp = hp;
	this->ap = ap;
}

bool Demon::IsDefend()
{
	return (state & isDefend);
}

bool Demon::IsAngered()
{
	return (state & isAngered);
}

int Demon::Attack(Peach& peach)
{
	ret = ap;
	if (state & isAngered)
	{
		ret *= 2;
	}
	if (peach.IsDefend())
	{
		ret /= 3;
	}
	peach.Damaged(ret);
	return ret;
}

int Demon::HeavyAtk(Peach& peach)
{
	ret = ap * 2;
	if (state & isAngered)
	{
		ret *= 2;
	}
	if (peach.IsDefend())
	{
		ret /= 3;
	}
	peach.Damaged(ret);
	return ret;
}

void Demon::Defend()
{
	state |= isDefend;
}

bool Demon::CheckDead()
{
	return (state & isDead);
}

bool Demon::CheckAngered()
{
	if (hp <= (maxHp * 0.7) && !(state & isAngered))
	{
		state |= isAngered;
		return true;
	}

	return false;
}

bool Demon::RemoveDefend()
{
	if (state & isDefend)
	{
		state &= ~isDefend;
		return true;
	}

	return false;
}

bool Demon::RemovePoisoned()
{
	if (state & isPoisoned)
	{
		Damaged(20);
		turnPois++;
		if (turnPois == 3)
		{
			state &= ~isPoisoned;
			turnPois = 0;
			return true;
		}
	}

	return false;
}

void Demon::Damaged(int point)
{
	hp -= point;

	if (hp <= 0)
	{
		state |= isDead;
	}
}

void Demon::Poisoned()
{
	state |= isPoisoned;
}
