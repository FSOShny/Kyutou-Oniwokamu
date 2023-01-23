#include "Game.h"

Game::Game()
	: cmd("")
	, win(false)
	, lose(false)
	, turn(1)
{
}

void Game::Startup()
{
	// �e�L�X�g1
	cout << "��Փx��I�����Ă��������B" << endl;
	cout << "��Fa�@���Fs�@���Fd" << endl;
	while (Input(0));
	cout << endl;

	// ���̃p�����[�^�ƋS�̃p�����[�^��ݒ肷��
	peach.Setter(500, 50);
	if (cmd == "a")
	{
		demon.Setter(300, 30);
	}
	else if (cmd == "s")
	{
		demon.Setter(600, 60);
	}
	else
	{
		demon.Setter(999, 99);
	}

	// �e�L�X�g2
	cout << "�S�����ꂽ�I�I" << "\n\n";
}

void Game::Playing()
{
	// ���������܂�܂Ń��[�v���J��Ԃ�
	while (!(win || lose))
	{
		PeachTurn();
		DemonTurn();
		turn++;
	}
}

void Game::PeachTurn()
{
	// �e�L�X�g3
	cout << "���͉������܂����H" << endl;
	cout << "�U���Fa�@�ōU���Fs�@�h��Fd�@�񕜁Ff" << endl;
	while (Input(2));
	cout << endl;

	// ���͂ɉ����Ĉȉ��̃A�N�V�������s��

	/* �U�� */
	if (cmd == "a")
	{
		cout << "���̍U���I" << endl;
		peach.Attack();
		cout << "�S��" << "�inull�j" << "�̃_���[�W���󂯂��B" << '\n\n';
	}

	/* �ōU�� */
	else if (cmd == "s")
	{
		cout << "���͓Őj��������I" << endl;
		peach.PoisonAtk();
		cout << "�S��" << "�inull�j" << "�̃_���[�W���󂯁A�ŏ�ԂɂȂ����B" << '\n\n';
	}

	/* �h�� */
	else if (cmd == "d")
	{
		cout << "���͖h��̍\�����Ƃ����B" << '\n\n';
		peach.Defend();
	}

	/* �� */
	else
	{
		cout << "���͌��������s�����I" << endl;
		peach.Recover();
		cout << "����" << "�inull�j" << "�����񕜂����B" << '\n\n';
	}
}

void Game::DemonTurn()
{
	// ���݂̃^�[�����ɉ����Ĉȉ��̃A�N�V�������s��

	/* �U�� */
	if (turn % 4 == 1)
	{
		cout << "�S�̍U���I" << endl;
		demon.Attack();
		cout << "����" << "�inull�j" << "�̃_���[�W���󂯂��B" << '\n\n';
	}

	/* ���U�� */
	else if (turn % 4 == 2)
	{
		cout << "�S�͋����ꌂ��������I" << endl;
		demon.HeavyAtk();
		cout << "����" << "�inull�j" << "�̃_���[�W���󂯂��B" << '\n\n';
	}

	/* ���� */
	else if (turn % 4 == 3)
	{
		cout << "�S�͒������Ă���B" << '\n\n';
	}

	/* �h�� */
	else
	{
		cout << "�S�͖h��̍\�����Ƃ����B" << '\n\n';
		demon.Defend();
	}
}

void Game::Shutdown()
{
	// �������ʂɉ������e�L�X�g���o�͂���

	/* ���̏����ƂȂ����ꍇ */
	if (win)
	{
		cout << "�S�̗̑͂��[���ɂȂ����B" << endl;
		cout << "���̏���!!!" << endl;
		while (Input(1));
		cout << endl;
		cout << "Thank you for playing!" << endl;
	}

	/* ���̕����ƂȂ����ꍇ */
	else
	{
		cout << "���̗̑͂��[���ɂȂ����B" << endl;
		cout << "���̕���..." << endl;
		while (Input(1));
		cout << endl;
		cout << "May you win someday." << endl;
	}
}

bool Game::Input(int pattern)
{
	/* 

	�ȉ��̃R�}���h����͂���܂Ń��[�v���J��Ԃ�

	�p�^�[��0�̏ꍇ�Fa, s, d
	�p�^�[��1�̏ꍇ�Ff
	�p�^�[��2�̏ꍇ�Fa, s, d, f
	
	*/

	cin >> cmd;
	switch (pattern)
	{
	case 1:
		if (cmd == "f") return false;
		break;
	case 2:
		if (cmd == "a" || cmd == "s" || cmd == "d" || cmd == "f") return false;
		break;
	default:
		if (cmd == "a" || cmd == "s" || cmd == "d") return false;
		break;
	}

	// �x���e�L�X�g���o�͂���
	cout << "�i�������R�}���h����͂��Ă��������B�j" << endl;
	return true;
}
