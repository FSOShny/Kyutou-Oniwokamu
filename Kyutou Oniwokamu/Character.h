#pragma once

class Character
{
public:
	// �L�����N�^�[�i��, �S�j�N���X�̃R���X�g���N�^
	Character();

	// �L�����N�^�[�̃p�����[�^��ݒ肷��Ƃ��̃��\�b�h
	void Setter(int hp, int ap);
	// �L�����N�^�[���_���[�W��^����Ƃ��̃��\�b�h
	int Attack(double rate);
	// �L�����N�^�[���퓬�s�\���ǂ������m�F���郁�\�b�h
	bool CheckDead();
	// �L�����N�^�[���_���[�W���󂯂��Ƃ��̃��\�b�h
	virtual int Damaged(int damage) = 0;
protected:
	// ���݂̗̑�
	int hp;
	// �̗͂̍ő�l
	int maxHp;
	// ���݂̍U����
	int ap;
	// �L�����N�^�[����Ԉُ킩�ǂ����̃t���O�ϐ�
	unsigned int state;
	// �L�����N�^�[�̐퓬�s�\��\���t���O�萔
	const unsigned int isDead = (1 << 0);
};
