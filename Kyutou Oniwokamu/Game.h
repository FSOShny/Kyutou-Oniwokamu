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
	// �Q�[�����J�n����Ƃ��̏���
	void Startup();
	// �Q�[�����v���C���Ă���Ƃ��̏���
	void Playing();
	// �Q�[�����I������Ƃ��̏���
	void Shutdown();
private:
	// ���̃^�[���ł���Ƃ��̏���
	void PeachTurn();
	// �S�̃^�[���ł���Ƃ��̏���
	void DemonTurn();
	// �R�}���h����͂���Ƃ��̏���
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
	// ���N���X
	Peach peach;
	// �S�N���X
	Demon demon;
};
