#include "Game.h"

Game::Game()
	: cmd("")
	, win(false)
	, lose(false)
	, turn(1)
	, enragedTurn(0)
	, damage(0)
{
}

void Game::Startup()
{
	// �ʏ�e�L�X�g1
	cout << "�i�Q�[�����J�n���܂��B�j" << endl;
	while (Input('B'));
	cout << endl;

	// �I�����e�L�X�g1
	// �i�����ŋS�̃p�����[�^�̋��������肷��j
	cout << "��Փx��I�����Ă��������B" << endl;
	cout << "��Fa�@���Fs�@���Fd" << endl;
	while (Input('C'));
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

	// �ʏ�e�L�X�g2
	cout << "�S�����ꂽ�I�I" << "\n\n";
}

void Game::Playing()
{
	/*
	
		�^�[���̗���͈ȉ��̒ʂ�

		�� -> �S -> �� -> �c
	
	*/

	// ���������܂�܂ł̓��[�v����
	while (!(win || lose))
	{
		PeachTurn();

		// ���̎��_�ŏ��������܂��Ă���΃��[�v���甲���o��
		if (win) break;

		DemonTurn();

		// �^�[�����𑝂₷
		turn++;
	}
}

void Game::PeachTurn()
{
	// �I�����e�L�X�g2
	// �i�����œ��̃A�N�V���������肷��j
	cout << "���͉������܂����H" << endl;
	cout << "�U���Fa�@�ōU���Fs�@�h��Fd�@�񕜁Ff" << endl;
	while (Input('A'));
	cout << endl;

	// ���̓R�}���h�ɉ����ē��̓A�N�V�������s��
	/*
		���̓R�}���ha�̂Ƃ��F�U��
		���̓R�}���hs�̂Ƃ��F�ōU��
		���̓R�}���hd�̂Ƃ��F�h��
		���̓R�}���hf�̂Ƃ��F��
	*/
	if (cmd == "a")
	{
		/* �S�ɒ��_���[�W��^���� */

		cout << "���̍U���I" << endl;
		damage = peach.Attack();
		cout << "�S��" << demon.Damaged(damage) << "�̃_���[�W���󂯂��I" << "\n\n";

		// �S���퓬�s�\���ǂ������m�F����
		// �i���̏����ł���ΏI���j
		win = demon.CheckDead();
		if (win) return;
	}
	else if (cmd == "s")
	{
		/* �S�ɏ��_���[�W��^���A�ŏ�Ԃɂ��� */

		cout << "���͓Őj��������I" << endl;
		damage = peach.PoisonAtk();

		// �i�ŏ�Ԃ̏d�ˊ|���͕s�j
		if (!demon.CheckPoisoned())
		{
			demon.Poisoned();
			cout << "�S��" << demon.Damaged(damage) << "�̃_���[�W���󂯁A�ŏ�ԂɂȂ����I" << "\n\n";
		}
		else
		{
			cout << "�S��" << demon.Damaged(damage) << "�̃_���[�W���󂯂��I" << "\n\n";
		}

		// �S���퓬�s�\���ǂ������m�F����
		// �i���̏����ł���ΏI���j
		win = demon.CheckDead();
		if (win) return;
	}
	else if (cmd == "d")
	{
		/* ������h���Ԃɂ��� */

		cout << "���͖h��̍\�����Ƃ����B" << "\n\n";
		peach.Defend();
	}
	else
	{
		/* �����𒆉񕜂��� */

		cout << "���͌��������s�����I" << endl;
		damage = peach.Recover();
		cout << "����" << -peach.Damaged(damage) << "�񕜂����I" << "\n\n";
	}

	// �S�̓ŏ�Ԃ��������Ƃ���
	// ��p�e�L�X�g���o�͂���
	if (demon.RemovePoisoned() && !demon.CheckDead())
	{
		cout << "�S�̓ł��������B" << "\n\n";
	}

	// �S���퓬�s�\���ǂ������m�F����
	// �i���̏����ł���ΏI���j
	win = demon.CheckDead();
	if (win) return;

	// �S�����{��Ԃł���Ƃ���
	// ��p�e�L�X�g���o�͂���
	if (demon.CheckEnraged())
	{
		if (enragedTurn == 0)
		{
			cout << "�S�͌��{��ԂɂȂ����I" << "\n\n";
			enragedTurn = turn;
		}
		else
		{
			cout << "�S�͌��{��Ԃ̂܂܂��B" << "\n\n";
			enragedTurn++;
		}
	}
}

void Game::DemonTurn()
{

	// ���݂̃^�[�����ɉ����ċS�̓A�N�V�������s��
	/*
		1, 5, ... �^�[���̂Ƃ��F�U��
		2, 6, ... �^�[���̂Ƃ��F���U��
		3, 7, ... �^�[���̂Ƃ��F�����i���{��Ԏ��F�U���j
		4, 8, ... �^�[���̂Ƃ��F���K
	*/
	if (turn % 4 == 1 || enragedTurn % 4 == 3)
	{
		/* ���ɒ��_���[�W��^���� */

		cout << "�S�̍U���I" << endl;
		damage = demon.Attack();
		cout << "����" << peach.Damaged(damage) << "�̃_���[�W���󂯂��I" << "\n\n";

		// �����퓬�s�\���ǂ������m�F����
		// �i���̕����ł���ΏI���j
		lose = peach.CheckDead();
		if (lose) return;
	}
	else if (turn % 4 == 2)
	{
		/* ���ɑ�_���[�W��^���� */

		cout << "�S�͋����ꌂ��������I" << endl;
		damage = demon.HeavyAtk();
		cout << "����" << peach.Damaged(damage) << "�̃_���[�W���󂯂��I" << "\n\n";

		// �����퓬�s�\���ǂ������m�F����
		// �i���̕����ł���ΏI���j
		lose = peach.CheckDead();
		if (lose) return;
	}
	else if (turn % 4 == 3)
	{
		/* �����������Ȃ� */
		cout << "�S�͒������Ă���B" << "\n\n";
	}
	else
	{
		/* �������|��Ԃɂ��� */

		cout << "�S�͙��K���s�����I" << endl;

		// �i���|��Ԃ̏d�ˊ|���͕s�j
		if (!peach.CheckFrightened())
		{
			peach.Frightened();
			cout << "���͋��|��ԂɂȂ����B" << "\n\n";
		}
	}

	// �����h���Ԃł���Ƃ���
	// ��Ԃ��������A��p�e�L�X�g���o�͂���
	if (peach.CheckDefend())
	{
		cout << "���͖h��̍\������߂��B" << "\n\n";
	}

	// ���̋��|��Ԃ��������Ƃ���
	// ��p�e�L�X�g���o�͂���
	if (peach.RemoveFrightened())
	{
		cout << "���̋��|���������B" << "\n\n";
	}
}

void Game::Shutdown()
{
	// ���������ɉ����Đ�p�e�L�X�g���o�͂���
	if (win)
	{
		cout << "�S�̗̑͂��[���ɂȂ����B" << endl;
		cout << "���̏���!!!" << endl;
		while (Input('B'));
		cout << endl;
		cout << "Thank you for playing!" << endl;
	}
	else
	{
		cout << "���̗̑͂��[���ɂȂ����B" << endl;
		cout << "���̕���..." << endl;
		while (Input('B'));
		cout << endl;
		cout << "May you win someday." << endl;
	}

	// �ʏ�e�L�X�g3
	cout << endl << "�i�Q�[�����I�����܂��B�j" << endl;
	while (Input('B'));
}

bool Game::Input(char pattern)
{
	/*
	
		���������̓R�}���h�͈ȉ��̒ʂ�
		�i���������͂���܂ł̓��[�v����j

		�p�^�[��A�̂Ƃ��Fa, s, d, f
		�p�^�[��B�̂Ƃ��Ff
		�p�^�[��C�̂Ƃ��Fa, s, d

	*/
	cin >> cmd;
	switch (pattern)
	{
	case 'A':
		if (cmd == "a" || cmd == "s" || cmd == "d" || cmd == "f") return false;
		break;
	case 'B':
		if (cmd == "f") return false;
		break;
	default:
		if (cmd == "a" || cmd == "s" || cmd == "d") return false;
		break;
	}

	// �x���e�L�X�g���o�͂���
	cout << "�i�������R�}���h����͂��Ă��������B�j" << endl;
	return true;
}
