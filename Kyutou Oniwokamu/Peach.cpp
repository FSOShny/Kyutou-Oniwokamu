#include "Peach.h"

Peach::Peach()
	: frightenedTurn(0)
{
}

void Peach::Setter(int hp, int ap)
{
	// ���̃p�����[�^��ݒ肷��
	this->hp = hp;
	maxHp = hp;
	this->ap = ap;
}

int Peach::Damaged(int damage)
{
	// ���݂̗̑͂����炷
	// �i�h���Ԏ��͎󂯂�_���[�W�ʂ������ɂȂ�j
	if (!(state & isDefend))
	{
		hp -= damage;
	}
	else
	{
		hp -= (damage * 0.5);
	}

	// ���݂̗̑͂��[���ł���Ƃ���
	// ����퓬�s�\�ɂ���
	// �i�񕜂ɂ��̗͂̍ő�l�𒴂��邱�Ƃ͂Ȃ��j
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

int Peach::Attack()
{
	// ���݂̍U���́~1�̒l��Ԃ�
	return ap;
}

int Peach::PoisonAtk()
{
	// ���݂̍U���́~0.5�̒l��Ԃ�
	return (ap * 0.5);
}

void Peach::Defend()
{
	// �������̃^�[�������h���Ԃɂ���
	state |= isDefend;
}

int Peach::Recover()
{
	// ���݂̍U���́~(-1)�̒l��Ԃ�
	return -ap;
}

bool Peach::CheckDefend()
{
	// ���̖h���Ԃ�����
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
	// ����2�^�[���̊Ԃ������|��Ԃɂ���
	state |= isFrightened;
	frightenedTurn = 3;

	// �U���͂𔼕��ɂ���
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
		// ���|��Ԃ̎c��^�[���������炷
		frightenedTurn--;

		// ���|��Ԃ̎c��^�[�������[���ł���Ƃ���
		// ���̋��|��Ԃ�����
		// �i�U���͂����ɖ߂��j
		if (frightenedTurn == 0)
		{
			state &= ~isFrightened;
			ap *= 2;
			return true;
		}
	}
	return false;
}
