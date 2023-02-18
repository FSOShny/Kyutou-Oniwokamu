#pragma once
#include <iostream>
#include "Peach.h"
#include "Demon.h"
using namespace std;

class Game
{
public:
	// �Q�[���N���X�̃R���X�g���N�^
	Game();

	// �Q�[�����J�n����Ƃ��̃��\�b�h
	void Startup();
	// �Q�[�����v���C���Ă���Ƃ��̃��\�b�h
	bool Playing();
	// �Q�[�����I������Ƃ��̃��\�b�h
	void Shutdown();
private:
	// ���ƋS�̌����O�̃��\�b�h
	void DuelBefore(Peach& peach, Demon& demon);
	// ���̃^�[���ł���Ƃ��̃��\�b�h
	void PeachTurn(Peach& peach, Demon& demon);
	// �S�̃^�[���ł���Ƃ��̃��\�b�h
	void DemonTurn(Peach& peach, Demon& demon);
	// ���ƋS�̌�����̃��\�b�h
	bool DuelAfter();
	// �R�}���h����͂���Ƃ��̃��\�b�h
	bool Input(char pattern);

	// ���̓R�}���h
	string cmd;
	// �������������ǂ����̃t���O�ϐ�
	bool win;
	// �������������ǂ����̃t���O�ϐ�
	bool lose;
	// ���݂̃^�[����
	int turn;
	// ���݂̃^�[����
	// �i���{��Ԃ̋S�̃A�N�V������ω������邽�߂̐����j
	int enragedTurn;
	// �^�����_���[�W�ʁi�܂��͉񕜗ʁj
	int damage;
};
