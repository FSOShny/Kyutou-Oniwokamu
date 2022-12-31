#include "Peach.h"

void Peach::Setter(int hp, int ap)
{
	this->hp = hp;
	maxHp = hp;
	this->ap = ap;
}

bool Peach::IsDefend()
{
	return (state & isDefend);
}

int Peach::Attack(Demon& demon)
{
	ret = ap;

	if (demon.IsDefend())
	{
		ret /= 3;
	}

	demon.Damaged(ret);
	return ret;
}

int Peach::PoisonAtk(Demon& demon)
{
	ret = ap / 2;

	if (demon.IsDefend())
	{
		ret /= 3;
	}

	demon.Damaged(ret);
	demon.Poisoned();
	return ret;
}

void Peach::Defend()
{
	state |= isDefend;
}

int Peach::Recover()
{
	ret = 30;
	hp += ret;

	if (maxHp < hp)
	{
		ret -= (hp - maxHp);
		hp = maxHp;
		return ret;
	}

	return ret;
}

bool Peach::CheckDead()
{
	return (state & isDead);
}

bool Peach::RemoveDefend()
{
	if (state & isDefend)
	{
		state &= ~isDefend;
		return true;
	}

	return false;
}

void Peach::Damaged(int point)
{
	hp -= point;

	if (hp <= 0)
	{
		state |= isDead;
	}
}
