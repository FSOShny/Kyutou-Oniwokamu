#pragma once

class Character
{
public:
	Character();
	virtual void Setter(int hp, int ap) = 0;
protected:
	int hp;
	int ap;
};
