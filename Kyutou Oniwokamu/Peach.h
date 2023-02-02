#pragma once
#include "Character.h"

class Peach : public Character
{
public:
	// ���N���X�̃R���X�g���N�^
	Peach();

	void Setter(int hp, int ap) override;
	int Damaged(int damage) override;
	bool CheckDead() override;

	// �����U�����s���Ƃ��̏���
	int Attack();
	// �����ōU�����s���Ƃ��̏���
	int PoisonAtk();
	// �����h����s���Ƃ��̏���
	void Defend();
	// �����񕜂��s���Ƃ��̏���
	int Recover();
	// �����h���Ԃ��ǂ������m�F���鏈��
	bool CheckDefend();
	// �������|��ԂɂȂ�Ƃ��̏���
	void Frightened();
	// �������|��Ԃ��ǂ������m�F���鏈��
	bool CheckFrightened();
	// �S�̓ŏ�Ԃ����������ǂ������m�F���鏈��
	bool RemoveFrightened();
private:
	// ���|��Ԃ̎c��^�[����
	int frightenedTurn;
	// ���̖h���Ԃ�\���t���O�萔
	unsigned int isDefend = (1 << 1);
	// ���̋��|��Ԃ�\���t���O�萔
	unsigned int isFrightened = (1 << 2);
};
