#pragma once
#include "Character.h"

class Peach : public Character
{
public:
	// ���N���X�̃R���X�g���N�^
	Peach();

	// �i�L�����N�^�[�N���X���\�b�h�̃I�[�o�[���C�h�j
	void Setter(int hp, int ap) override;
	int Attack(double rate) override;
	int Damaged(int damage) override;
	bool CheckDead() override;

	// �����h����s���Ƃ��̏���
	void Defend();
	// �����h���Ԃ��ǂ������m�F���鏈��
	bool CheckDefend();
	// �������|��ԂɂȂ�Ƃ��̏���
	void Frightened();
	// �������|��Ԃ��ǂ������m�F���鏈��
	bool CheckFrightened();
	// �S�̓ŏ�Ԃ����������ǂ������m�F���鏈��
	bool RemoveFrightened();
private:
	// ���̖h���Ԃ�\���t���O�萔
	unsigned int isDefend = (1 << 1);
	// ���̋��|��Ԃ�\���t���O�萔
	unsigned int isFrightened = (1 << 2);
	// ���|��Ԃ̎c��^�[����
	int frightenedTurn;
};
