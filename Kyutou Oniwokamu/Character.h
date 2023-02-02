#pragma once

class Character
{
public:
	// �L�����N�^�[�i��, �S�j�N���X�̃R���X�g���N�^
	Character();
	// �L�����N�^�[�̃p�����[�^��ݒ肷��Ƃ��̏���
	virtual void Setter(int hp, int ap) = 0;
	// �L�����N�^�[���_���[�W���󂯂��Ƃ��̏���
	virtual int Damaged(int damage) = 0;
	// �L�����N�^�[���퓬�s�\���ǂ������m�F���鏈��
	virtual bool CheckDead() = 0;
protected:
	// ���݂̗̑�
	int hp;
	// �̗͂̍ő�l
	int maxHp;
	// �U����
	int ap;
	// �L�����N�^�[����Ԉُ킩�ǂ����̃t���O
	unsigned int state;
	// �L�����N�^�[�̐퓬�s�\��\���t���O�萔
	const unsigned int isDead = (1 << 0);
};
