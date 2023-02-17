#include "Character.h"

Character::Character()
	: hp(0)
	, maxHp(0)
	, ap(0)
	, state(0)
{
}

void Character::Setter(int hp, int ap)
{
	// キャラクターのパラメータを設定する
	this->hp = hp;
	maxHp = hp;
	this->ap = ap;
}

int Character::Attack(double rate)
{
	// （現在の攻撃力×アクション倍率）の値を返す
	return (ap * rate);
}

bool Character::CheckDead()
{
	// キャラクターが戦闘不能かどうかのフラグを返す
	return (state & isDead);
}
