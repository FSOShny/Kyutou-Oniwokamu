#include "Demon.h"

Demon::Demon()
	: poisonedTurn(0)
{
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

bool Demon::CheckEnraged()
{
	/* 鬼が激怒状態かどうかを確認する */

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
	// 鬼が毒状態かどうかのフラグを返す
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
