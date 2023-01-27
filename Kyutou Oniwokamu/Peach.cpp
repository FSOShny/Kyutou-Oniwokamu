#include "Peach.h"

Peach::Peach()
	: frightenedTurn(0)
{
}

void Peach::Setter(int hp, int ap)
{
	this->hp = hp;
	maxHp = hp;
	this->ap = ap;
}

int Peach::Damaged(int damage)
{
	hp -= damage;
	if (hp <= 0)
	{
		state |= isDead;
	}
	else if (hp > maxHp)
	{
		hp = maxHp;
	}
	return damage;
}

bool Peach::CheckDead()
{
	return (state & isDead);
}

int Peach::Attack()
{
	return ap;
}

int Peach::PoisonAtk()
{
	return (ap * 0.5);
}

void Peach::Defend()
{
	state |= isDefend;
}

bool Peach::CheckDefend()
{
	if (state & isDefend)
	{
		state &= ~isDefend;
		return true;
	}
	else
	{
		return false;
	}
}

int Peach::Recover()
{
	return -ap;
}

void Peach::Frightened()
{
	state |= isFrightened;
	ap *= 0.5;
	frightenedTurn = 2;
}

bool Peach::CheckFrightened()
{
	return (state & isFrightened);
}

bool Peach::RemoveFrightened()
{
	if (state & isFrightened)
	{
		frightenedTurn--;
		if (frightenedTurn == 0)
		{
			state &= ~isFrightened;
			ap *= 2;
			return true;
		}
	}
	return false;
}
