#pragma once
#include "Character.h"

class Demon : public Character
{
public:
	// �S�N���X�̃R���X�g���N�^
	Demon();

	// �i�L�����N�^�[�N���X���\�b�h�̃I�[�o�[���C�h�j
	void Setter(int hp, int ap) override;
	int Attack(double rate) override;
	int Damaged(int damage) override;
	bool CheckDead() override;

	// �S�����{��Ԃ��ǂ������m�F���鏈��
	bool CheckEnraged();
	// �S���ŏ�ԂɂȂ�Ƃ��̏���
	void Poisoned();
	// �S���ŏ�Ԃ��ǂ������m�F���鏈��
	bool CheckPoisoned();
	// �S�̓ŏ�Ԃ����������ǂ������m�F���鏈��
	bool RemovePoisoned();
private:
	// �S�̌��{��Ԃ�\���t���O�萔
	const unsigned int isEnraged = (1 << 1);
	// �S�̓ŏ�Ԃ�\���t���O�萔
	const unsigned int isPoisoned = (1 << 2);
	// �ŏ�Ԃ̎c��^�[����
	int poisonedTurn;
};
