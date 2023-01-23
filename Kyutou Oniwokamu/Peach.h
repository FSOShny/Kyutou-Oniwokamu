#pragma once
#include "Character.h"
#include "Demon.h"

class Peach : public Character
{
public:
	void Setter(int hp, int ap) override;
	void Attack();
	void PoisonAtk();
	void Defend();
	void Recover();
private:
};
