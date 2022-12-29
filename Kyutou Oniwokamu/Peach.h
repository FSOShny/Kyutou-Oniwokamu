#pragma once
#include "Character.h"

class Peach : public Character
{
public:
	Peach();
	void Attack();
	void PoisonAtk();
	void Defend();
	void Recover();
private:
	bool def;
};
