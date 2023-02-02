#pragma once
#include "Character.h"

class Demon : public Character
{
public:
	// �S�N���X�̃R���X�g���N�^
	Demon();

	void Setter(int hp, int ap) override;
	int Damaged(int damage) override;
	bool CheckDead() override;

	// �S���U�����s���Ƃ��̏���
	int Attack();
	// �S�����U�����s���Ƃ��̏���
	int HeavyAtk();
	// �S�����{��Ԃ��ǂ������m�F���鏈��
	bool CheckEnraged();
	// �S���ŏ�ԂɂȂ�Ƃ��̏���
	void Poisoned();
	// �S���ŏ�Ԃ��ǂ������m�F���鏈��
	bool CheckPoisoned();
	// �S�̓ŏ�Ԃ����������ǂ������m�F���鏈��
	bool RemovePoisoned();
private:
	// �ŏ�Ԃ̎c��^�[����
	int poisonedTurn;
	// �S�̌��{��Ԃ�\���t���O�萔
	const unsigned int isEnraged = (1 << 1);
	// �S�̓ŏ�Ԃ�\���t���O�萔
	const unsigned int isPoisoned = (1 << 2);
};
