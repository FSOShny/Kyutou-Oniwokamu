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
	// �J�n�e�L�X�g
	cout << "���Q�[�����J�n���܂��B��" << endl;
	cout << "�`���֐i�ށFf�i�܂��́je�`" << "\n �� ";
	while (Input('B'));
	cout << endl;
}

bool Game::Playing()
{
	// ���N���X�A�S�N���X
	Peach peach;
	Demon demon;

	// �����O
	DuelBefore(peach, demon);

	// ���������܂�܂Ń��[�v����
	while (!(win || lose))
	{
		// �ʏ�e�L�X�g2
		cout << "--------------- " << turn << "�^�[�� ---------------" << "\n\n";

		// ���̃^�[��
		PeachTurn(peach, demon);

		// ���̎��_�ŏ��������܂��Ă���΃��[�v���甲���o��
		if (win) break;

		// �S�̃^�[��
		DemonTurn(peach, demon);

		// ���̃^�[���Ɉڍs����
		turn++;
	}

	// ������
	return DuelAfter();
}

void Game::Shutdown()
{
	// �I���e�L�X�g
	cout << "���Q�[�����I�����܂��B��" << endl;
	cout << "�`���֐i�ށFf�i�܂��́je�`" << "\n �� ";
	while (Input('B'));
	cout << endl;
}

void Game::DuelBefore(Peach& peach, Demon& demon)
{
	// �I�����e�L�X�g1
	// �i�����œ��ƋS�̃p�����[�^�����肷��j
	cout << "����Փx��I�����Ă��������B��" << endl;
	cout << "�`��Fa�@���Fs�@���Fd�`" << "\n �� ";
	while (Input('C'));
	cout << endl;
	if (cmd == "a")
	{
		/* ��Փx�u��v�̃p�����[�^�[��ݒ肷�� */

		peach.Setter(350, 35);
		demon.Setter(333, 33);
	}
	else if (cmd == "s")
	{
		/* ��Փx�u���v�̃p�����[�^�[��ݒ肷�� */

		peach.Setter(500, 50);
		demon.Setter(666, 66);
	}
	else
	{
		/* ��Փx�u���v�̃p�����[�^�[��ݒ肷�� */

		peach.Setter(650, 65);
		demon.Setter(999, 99);
	}

	// �ʏ�e�L�X�g1
	cout << "�S�����ꂽ�I�I" << "\n\n";

	// �����e�L�X�g1
	cout << "*********************************************" << "\n\n";
}

void Game::PeachTurn(Peach& peach, Demon& demon)
{
	// �I�����e�L�X�g2
	// �i�����œ��̃A�N�V���������肷��j
	cout << "�����͉������܂����H��" << endl;
	cout << "�`�U���Fa�@�ōU���Fs�@�h��Fd�@�񕜁Ff�`" << "\n �� ";
	while (Input('A'));
	cout << endl;

	// ���̓R�}���h�ɉ����ē��̓A�N�V�������s��
	/*
		���̓R�}���h�ua�v�̂Ƃ��F�U��
		���̓R�}���h�us�v�̂Ƃ��F�ōU��
		���̓R�}���h�ud�v�̂Ƃ��F�h��
		���̓R�}���h�uf�v�̂Ƃ��F��
	*/
	if (cmd == "a")
	{
		/* �S�Ƀ_���[�W�i���ʗʁF���j��^���� */

		cout << "�� ���̍U���I" << "\n\n";
		damage = peach.Attack(2.0);
		cout << "�@�S��" << demon.Damaged(damage) << "�̃_���[�W���󂯂��I" << "\n\n";

		// �S���퓬�s�\���ǂ������m�F����
		// �i���������܂�ΏI������j
		win = demon.CheckDead();
		if (win) return;
	}
	else if (cmd == "s")
	{
		/* �S�Ƀ_���[�W�i���ʗʁF���j��^���A�ŏ�Ԃɂ��� */

		cout << "�� ���͓Őj��������I" << "\n\n";
		damage = peach.Attack(1.5);

		// �i�ŏ�Ԃ̏d�ˊ|���͕s�j
		if (!demon.CheckPoisoned())
		{
			demon.Poisoned();
			cout << "�@�S��" << demon.Damaged(damage) << "�̃_���[�W���󂯁A�ŏ�ԂɂȂ����I" << "\n\n";
		}
		else
		{
			cout << "�@�S��" << demon.Damaged(damage) << "�̃_���[�W���󂯂��I" << "\n\n";
		}

		// �S���퓬�s�\���ǂ������m�F����
		// �i���������܂�ΏI������j
		win = demon.CheckDead();
		if (win) return;
	}
	else if (cmd == "d")
	{
		/* ������h���Ԃɂ��� */

		cout << "�� ���͖h��̍\�����Ƃ����B" << "\n\n";
		peach.Defend();
	}
	else
	{
		/* �������񕜁i���ʗʁF��j���� */

		cout << "�� ���͌��������s�����I" << "\n\n";
		damage = peach.Attack(-2.5);
		cout << "�@����" << -peach.Damaged(damage) << "�񕜂����I" << "\n\n";
	}

	// �S�ɓŃ_���[�W��^����
	if (demon.CheckPoisoned())
	{
		cout << "�@�S�͓łɂ��A" << demon.Damaged(30) << "�̃_���[�W���󂯂��I" << "\n\n";
	}

	// �S���퓬�s�\���ǂ������m�F����
	// �i���������܂�ΏI������j
	win = demon.CheckDead();
	if (win) return;

	// �S�̓ŏ�Ԃ��������Ƃ���
	// ��p�e�L�X�g���o�͂���
	if (demon.RemovePoisoned())
	{
		cout << "�@�S�̓ł��������B" << "\n\n";
	}

	// �S�����{��Ԃł���Ƃ���
	// ��p�e�L�X�g���o�͂���
	if (demon.CheckEnraged())
	{
		if (enragedTurn == 0)
		{
			cout << "�@�S�͌��{��ԂɂȂ����I" << "\n\n";
			cout << "�i�S�̍U���͂��{�ɂȂ����B�C��t����I�j" << "\n\n";
			enragedTurn = turn;
		}
		else
		{
			cout << "�@�S�͌��{��Ԃ̂܂܂��B" << "\n\n";
			enragedTurn++;
		}
	}
}

void Game::DemonTurn(Peach& peach, Demon& demon)
{

	// ���݂̃^�[�����ɉ����ċS�̓A�N�V�������s��
	/*
		�u1, 5, ...�v�^�[���̂Ƃ��F�U��
		�u2, 6, ...�v�^�[���̂Ƃ��F���U��
		�u3, 7, ...�v�^�[���̂Ƃ��F�����i���{��Ԏ��F�U���j
		�u4, 8, ...�v�^�[���̂Ƃ��F���K
	*/
	if (turn % 4 == 1 || enragedTurn % 4 == 3)
	{
		/* ���Ƀ_���[�W�i���ʗʁF���j��^���� */

		cout << "�� �S�̍U���I" << "\n\n";
		damage = demon.Attack(1.0);
		cout << "�@����" << peach.Damaged(damage) << "�̃_���[�W���󂯂��I" << "\n\n";

		// �����퓬�s�\���ǂ������m�F����
		// �i���������܂�ΏI������j
		lose = peach.CheckDead();
		if (lose) return;
	}
	else if (turn % 4 == 2)
	{
		/* ���Ƀ_���[�W�i���ʗʁF��j��^���� */

		cout << "�� �S�͋����ꌂ��������I" << "\n\n";
		damage = demon.Attack(2);
		cout << "�@����" << peach.Damaged(damage) << "�̃_���[�W���󂯂��I" << "\n\n";

		// �����퓬�s�\���ǂ������m�F����
		// �i���������܂�ΏI������j
		lose = peach.CheckDead();
		if (lose) return;
	}
	else if (turn % 4 == 3)
	{
		/* �����������Ȃ� */

		cout << "�� �S�͒������Ă���B" << "\n\n";
	}
	else
	{
		/* �������|��Ԃɂ��� */

		cout << "�� �S�͙��K���s�����I" << "\n\n";

		// �i���|��Ԃ̏d�ˊ|���͕s�j
		if (!peach.CheckFrightened())
		{
			peach.Frightened();
			cout << "�@���͋��|��ԂɂȂ����B" << "\n\n";
			cout << "�i���΂炭�̊ԁA���̍U���͂������ɂȂ��Ă��܂��B�j" << "\n\n";
		}
		else
		{
			cout << "�@���͂��łɋ��|��Ԃ��B" << "\n\n";
		}
	}

	// �����h���Ԃ��������Ƃ���
	// ��p�e�L�X�g���o�͂���
	if (peach.CheckDefend())
	{
		cout << "�@���͖h��̍\������߂��B" << "\n\n";
	}

	// ���̋��|��Ԃ��������Ƃ���
	// ��p�e�L�X�g���o�͂���
	if (peach.RemoveFrightened())
	{
		cout << "�@���̋��|���������B" << "\n\n";
	}
}

bool Game::DuelAfter()
{
	// �����e�L�X�g2
	cout << "*********************************************" << "\n\n";

	// ���������ɉ�������p�e�L�X�g���o�͂���
	if (win)
	{
		cout << "�S�̗̑͂��[���ɂȂ����B" << "\n\n";
		cout << "���̏���!!!" << "\n\n";
		cout << "�`���֐i�ށFf�i�܂��́je�`" << "\n �� ";
		while (Input('B'));
		cout << endl;
		cout << "������ Thank you for playing! ������" << "\n\n";
	}
	else
	{
		cout << "���̗̑͂��[���ɂȂ����B" << "\n\n";
		cout << "���̕���..." << "\n\n";
		cout << "�`���֐i�ށFf�i�܂��́je�`" << "\n �� ";
		while (Input('B'));
		cout << endl;
		cout << "������ May you win someday. ������" << "\n\n";
	}

	// �I�����e�L�X�g2
	// �i�����ŃQ�[���v���C�����g���C���邩�ǂ��������肷��j
	cout << "���Q�[���v���C�����g���C���܂����H��" << endl;
	cout << "�`�͂��Ff�@�������Fe�`" << "\n �� ";
	while (Input('B'));
	cout << endl;
	if (cmd == "f")
	{
		/* �v���C�f�[�^�����������Ă��烊�g���C���� */

		win = false;
		lose = false;
		turn = 1;
		enragedTurn = 0;
		return true;
	}
	else
	{
		/* ���̂܂܃V���b�g�_�E�������Ɉڍs���� */

		return false;
	}
}

bool Game::Input(char pattern)
{
	/*
	
		���������̓R�}���h�͈ȉ��̒ʂ�
		�i���������͂���܂ł̓��[�v����j

		�p�^�[���uA�v�̂Ƃ��Fa, s, d, f
		�p�^�[���uB�v�̂Ƃ��Ff, e
		�p�^�[���uC�v�̂Ƃ��Fa, s, d

	*/
	cin >> cmd;
	switch (pattern)
	{
	case 'A':
		if (cmd == "a" || cmd == "s" || cmd == "d" || cmd == "f") return false;
		break;
	case 'B':
		if (cmd == "f" || cmd == "e") return false;
		break;
	default:
		if (cmd == "a" || cmd == "s" || cmd == "d") return false;
		break;
	}

	// �x���e�L�X�g
	cout << "/*�������R�}���h����͂��Ă��������B*/" << "\n �� ";
	return true;
}
