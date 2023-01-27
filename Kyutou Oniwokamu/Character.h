#pragma once

class Character
{
public:
	Character();
	virtual void Setter(int hp, int ap) = 0;
	virtual int Damaged(int damage) = 0;
	virtual bool CheckDead() = 0;
protected:
	int hp;
	int maxHp;
	int ap;
	unsigned int state;
	const unsigned int isDead = (1 << 0);
};
