#pragma once
#include "Character.h"

class Demon : public Character
{
public:
	// �S�N���X�̃R���X�g���N�^
	Demon();

	// �S���_���[�W���󂯂��Ƃ��̃��\�b�h
	int Damaged(int damage) override;
	// �S�����{��Ԃ��ǂ������m�F���郁�\�b�h
	bool CheckEnraged();
	// �S���ŏ�ԂɂȂ�Ƃ��̃��\�b�h
	void Poisoned();
	// �S���ŏ�Ԃ��ǂ������m�F���郁�\�b�h
	bool CheckPoisoned();
	// �S�̓ŏ�Ԃ����������ǂ������m�F���郁�\�b�h
	bool RemovePoisoned();
private:
	// �S�̌��{��Ԃ�\���t���O�萔
	const unsigned int isEnraged = (1 << 1);
	// �S�̓ŏ�Ԃ�\���t���O�萔
	const unsigned int isPoisoned = (1 << 2);
	// �ŏ�Ԃ̎c��^�[����
	int poisonedTurn;
};
