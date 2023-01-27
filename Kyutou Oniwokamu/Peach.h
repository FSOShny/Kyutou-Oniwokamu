#pragma once
#include "Character.h"

class Peach : public Character
{
public:
	Peach();
	void Setter(int hp, int ap) override;
	int Damaged(int damage) override;
	bool CheckDead() override;

	int Attack();
	int PoisonAtk();
	void Defend();
	bool CheckDefend();
	int Recover();
	void Frightened();
	bool CheckFrightened();
	bool RemoveFrightened();
private:
	int frightenedTurn;
	unsigned int isDefend = (1 << 1);
	unsigned int isFrightened = (1 << 2);
};
