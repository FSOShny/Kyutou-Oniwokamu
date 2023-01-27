#pragma once
#include "Character.h"

class Demon : public Character
{
public:
	Demon();
	void Setter(int hp, int ap) override;
	int Damaged(int damage) override;
	bool CheckDead() override;

	int Attack();
	int HeavyAtk();
	bool CheckEnraged();
	void Poisoned();
	bool CheckPoisoned();
	bool RemovePoisoned();
private:
	int poisonedTurn;
	const unsigned int isEnraged = (1 << 1);
	const unsigned int isPoisoned = (1 << 2);
};
