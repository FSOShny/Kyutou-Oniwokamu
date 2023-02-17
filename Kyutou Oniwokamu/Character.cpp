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
	// �L�����N�^�[�̃p�����[�^��ݒ肷��
	this->hp = hp;
	maxHp = hp;
	this->ap = ap;
}

int Character::Attack(double rate)
{
	// �i���݂̍U���́~�A�N�V�����{���j�̒l��Ԃ�
	return (ap * rate);
}

bool Character::CheckDead()
{
	// �L�����N�^�[���퓬�s�\���ǂ����̃t���O��Ԃ�
	return (state & isDead);
}
