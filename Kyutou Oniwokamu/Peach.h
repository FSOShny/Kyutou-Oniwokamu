#pragma once
#include "Character.h"

class Peach : public Character
{
public:
	// ���N���X�̃R���X�g���N�^
	Peach();

	// �����_���[�W���󂯂��Ƃ��̃��\�b�h
	int Damaged(int damage) override;
	// �����h����s���Ƃ��̃��\�b�h
	void Defend();
	// �����h���Ԃ��ǂ������m�F���郁�\�b�h
	bool CheckDefend();
	// �������|��ԂɂȂ�Ƃ��̃��\�b�h
	void Frightened();
	// �������|��Ԃ��ǂ������m�F���郁�\�b�h
	bool CheckFrightened();
	// �S�̓ŏ�Ԃ����������ǂ������m�F���郁�\�b�h
	bool RemoveFrightened();
private:
	// ���̖h���Ԃ�\���t���O�萔
	unsigned int isDefend = (1 << 1);
	// ���̋��|��Ԃ�\���t���O�萔
	unsigned int isFrightened = (1 << 2);
	// ���|��Ԃ̎c��^�[����
	int frightenedTurn;
};
