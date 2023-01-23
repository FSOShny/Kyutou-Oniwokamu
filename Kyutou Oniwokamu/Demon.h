#pragma once
#include "Character.h"
#include "Peach.h"

class Demon : public Character
{
public:
	void Setter(int hp, int ap) override;
	void Attack();
	void HeavyAtk();
	void Defend();
private:
};
