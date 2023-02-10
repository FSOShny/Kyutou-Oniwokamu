#include "Demon.h"

Demon::Demon()
	: poisonedTurn(0)
{
}

void Demon::Setter(int hp, int ap)
{
	// �S�̃p�����[�^��ݒ肷��
	this->hp = hp;
	maxHp = hp;
	this->ap = ap;
}

int Demon::Attack(double rate)
{
	// �i���݂̍U���́~�A�N�V�����{���j�̒l��Ԃ�
	return (ap * rate);
}

int Demon::Damaged(int damage)
{
	// ���݂̗̑͂����炷
	hp -= damage;

	// ���݂̗̑͂��[���ł���Ƃ���
	// �S��퓬�s�\�ɂ���
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
		// ���݂̗̑͂��ő�l��65%�ȉ��ł���Ƃ���
		// �S�����{��Ԃɂ���
		// �i���{��Ԏ��͍U���͂�{�ɂ���j
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
	// �S��3�^�[���������ŏ�Ԃɂ���
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
		// �ŏ�Ԃ̎c��^�[���������炷
		poisonedTurn--;

		// �ŏ�Ԃ̎c��^�[�������[���ł���Ƃ���
		// �S�̓ŏ�Ԃ�����
		if (poisonedTurn == 0)
		{
			state &= ~isPoisoned;
			return true;
		}
	}
	return false;
}
