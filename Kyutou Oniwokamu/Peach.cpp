#include "Peach.h"

Peach::Peach()
	: frightenedTurn(0)
{
}

void Peach::Setter(int hp, int ap)
{
	// 桃のパラメータを設定する
	this->hp = hp;
	maxHp = hp;
	this->ap = ap;
}

int Peach::Attack(double rate)
{
	// （現在の攻撃力×アクション倍率）の値を返す
	return (ap * rate);
}

int Peach::Damaged(int damage)
{
	// 現在の体力を減らす
	// （防御状態時は受けるダメージ量が半分になる）
	if (!(state & isDefend))
	{
		hp -= damage;
	}
	else
	{
		hp -= (damage * 0.5);
	}

	// 現在の体力がゼロであるときに
	// 桃を戦闘不能にする
	// （なお、回復により体力の最大値を超えることはない）
	if (hp <= 0)
	{
		state |= isDead;
	}
	else if (hp > maxHp)
	{
		hp = maxHp;
	}

	if (!(state & isDefend))
	{
		return damage;
	}
	else
	{
		return (damage * 0.5);
	}
}

bool Peach::CheckDead()
{
	return (state & isDead);
}

void Peach::Defend()
{
	// 桃をそのターンだけ防御状態にする
	state |= isDefend;
}

bool Peach::CheckDefend()
{
	// 桃の防御状態を消す
	if (state & isDefend)
	{
		state &= ~isDefend;
		return true;
	}
	else
	{
		return false;
	}
}

void Peach::Frightened()
{
	// 桃を2ターン分だけ恐怖状態にする
	state |= isFrightened;
	frightenedTurn = 2;

	// 攻撃力を半分にする
	ap *= 0.5;
}

bool Peach::CheckFrightened()
{
	return (state & isFrightened);
}

bool Peach::RemoveFrightened()
{
	if (state & isFrightened)
	{
		// 恐怖状態の残りターン数がゼロであるときに
		// 桃の恐怖状態を消す
		// （攻撃力を元に戻す）
		if (frightenedTurn == 0)
		{
			state &= ~isFrightened;
			ap *= 2;
			return true;
		}

		// 恐怖状態の残りターン数を減らす
		frightenedTurn--;
	}
	return false;
}
