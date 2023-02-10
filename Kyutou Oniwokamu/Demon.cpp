#include "Demon.h"

Demon::Demon()
	: poisonedTurn(0)
{
}

void Demon::Setter(int hp, int ap)
{
	// 鬼のパラメータを設定する
	this->hp = hp;
	maxHp = hp;
	this->ap = ap;
}

int Demon::Attack(double rate)
{
	// （現在の攻撃力×アクション倍率）の値を返す
	return (ap * rate);
}

int Demon::Damaged(int damage)
{
	// 現在の体力を減らす
	hp -= damage;

	// 現在の体力がゼロであるときに
	// 鬼を戦闘不能にする
	if (hp <= 0)
	{
		state |= isDead;
	}

	return damage;
}

bool Demon::CheckDead()
{
	return (state & isDead);
}

bool Demon::CheckEnraged()
{
	if (state & isEnraged)
	{
		return true;
	}
	else
	{
		// 現在の体力が最大値の65%以下であるときに
		// 鬼を激怒状態にする
		// （激怒状態時は攻撃力を倍にする）
		if (hp <= maxHp * 0.65)
		{
			state |= isEnraged;
			ap *= 1.5;
			return true;
		}
	}
	return false;
}

void Demon::Poisoned()
{
	// 鬼を3ターン分だけ毒状態にする
	state |= isPoisoned;
	poisonedTurn = 3;
}

bool Demon::CheckPoisoned()
{
	return (state & isPoisoned);
}

bool Demon::RemovePoisoned()
{
	if (state & isPoisoned)
	{
		// 毒状態の残りターン数を減らす
		poisonedTurn--;

		// 毒状態の残りターン数がゼロであるときに
		// 鬼の毒状態を消す
		if (poisonedTurn == 0)
		{
			state &= ~isPoisoned;
			return true;
		}
	}
	return false;
}
