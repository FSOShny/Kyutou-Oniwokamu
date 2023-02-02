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

int Demon::Attack()
{
	// ���݂̍U���́~1�̒l��Ԃ�
	return ap;
}

int Demon::HeavyAtk()
{
	// ���݂̍U���́~2�̒l��Ԃ�
	return ap * 2;
}

bool Demon::CheckEnraged()
{
	if (state & isEnraged)
	{
		return true;
	}
	else
	{
		// ���݂̗̑͂��ő�l��6.5�ȉ��ł���Ƃ���
		// �S�����{��Ԃɂ���
		// �i���{��Ԏ��͍U���͂�{�ɂ���j
		if (hp <= maxHp * 0.65)
		{
			state |= isEnraged;
			ap *= 2;
			return true;
		}
	}
	return false;
}

void Demon::Poisoned()
{
	// �S��3�^�[���̊Ԃ����ŏ�Ԃɂ���
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

		// �S��20�_���[�W���󂯂�i��p�e�L�X�g�͏o�͂��Ȃ��j
		Damaged(20);

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
