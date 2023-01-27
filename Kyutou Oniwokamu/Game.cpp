#include "Game.h"

Game::Game()
	: cmd("")
	, win(false)
	, lose(false)
	, turn(1)
	, damage(0)
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

		// ���̎��_�ŏ��������܂��Ă���΃��[�v�I��
		if (win) break;

		DemonTurn();

		// �^�[����i�߂�
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

	// ���̓R�}���h�ɉ����Ĉȉ��̃A�N�V�������s��
	/*
		���̓R�}���ha�F�U���i�S�֒��_���[�W��^����j
		���̓R�}���hs�F�ōU���i�S�֏��_���[�W��^���A�ŏ�Ԃɂ���j
		���̓R�}���hd�F�h��i������h���Ԃɂ���j
		���̓R�}���hf�F�񕜁i�����𒆉񕜂���j
	*/
	if (cmd == "a")
	{
		cout << "���̍U���I" << endl;
		damage = peach.Attack();
		cout << "�S��" << demon.Damaged(damage) << "�̃_���[�W���󂯂��I" << "\n\n";

		// �S�̗̑͂��[�����ǂ������m�F����
		// �i���̏����ł���ΏI���j
		win = demon.CheckDead();
		if (win) return;
	}
	else if (cmd == "s")
	{
		cout << "���͓Őj��������I" << endl;
		damage = peach.PoisonAtk();

		// �i�ŏ�Ԃ̏d�ˊ|���͕s�j
		if (!demon.CheckPoisoned())
		{
			demon.Poisoned();
		}

		cout << "�S��" << demon.Damaged(damage) << "�̃_���[�W���󂯁A�ŏ�ԂɂȂ����I" << "\n\n";

		// �S�̗̑͂��[�����ǂ������m�F����
		// �i���̏����ł���ΏI���j
		win = demon.CheckDead();
		if (win) return;
	}
	else if (cmd == "d")
	{
		cout << "���͖h��̍\�����Ƃ����B" << "\n\n";
		peach.Defend();
	}
	else
	{
		cout << "���͌��������s�����I" << endl;
		damage = peach.Recover();
		cout << "����" << peach.Damaged(damage) << "�񕜂����I" << "\n\n";
	}

	// �S���{���ԂɂȂ����Ƃ���
	// ��p�e�L�X�g���o�͂���
	if (demon.CheckEnraged())
	{
		cout << "�S�͓{���ԂɂȂ����I" << "\n\n";
	}

	// �S�̓ŏ�Ԃ��������ꂽ�Ƃ���
	// ��p�e�L�X�g���o�͂���
	if (demon.RemovePoisoned() && !demon.CheckDead())
	{
		cout << "�S�̓ł��������B" << "\n\n";
	}

	// �S�̗̑͂��[�����ǂ������m�F����
	// �i���̏����ł���ΏI���j
	win = demon.CheckDead();
	if (win) return;
}

void Game::DemonTurn()
{

	// ���݂̃^�[�����ɉ����Ĉȉ��̃A�N�V�������s��
	/*
		4n+1�i1, 5, 9, ...�j�^�[���F�U���i���֒��_���[�W��^����j
		4n+2�i2, 6, 10, ...�j�^�[���F���U���i���֑�_���[�W��^����j
		4n+3�i3, 7, 11, ...�j�^�[���F�����i�����������Ȃ��j
		4n+4�i4, 8, 12, ...�j�^�[���F���K�i�������|��Ԃɂ���j
	*/
	if (turn % 4 == 1)
	{
		cout << "�S�̍U���I" << endl;
		damage = demon.Attack();
		cout << "����" << peach.Damaged(damage) << "�̃_���[�W���󂯂��I" << "\n\n";

		// ���̗̑͂��[�����ǂ������m�F����
		// �i���̕����ł���ΏI���j
		lose = peach.CheckDead();
		if (lose) return;
	}
	else if (turn % 4 == 2)
	{
		cout << "�S�͋����ꌂ��������I" << endl;
		damage = demon.HeavyAtk();
		cout << "����" << peach.Damaged(damage) << "�̃_���[�W���󂯂��I" << "\n\n";

		// ���̗̑͂��[�����ǂ������m�F����
		// �i���̕����ł���ΏI���j
		lose = peach.CheckDead();
		if (lose) return;
	}
	else if (turn % 4 == 3)
	{
		cout << "�S�͒������Ă���B" << "\n\n";
	}
	else
	{
		cout << "�S�͙��K���s�����I" << endl;

		// �i���|��Ԃ̏d�ˊ|���͕s�j
		if (!peach.CheckFrightened())
		{
			peach.Frightened();
		}

		cout << "���͋��|��ԂɂȂ����B" << "\n\n";
	}

	// �����h���Ԃł���Ƃ���
	// ��Ԃ��������A��p�e�L�X�g���o�͂���
	if (peach.CheckDefend())
	{
		cout << "���͖h��̍\������߂��B" << "\n\n";
	}

	// ���̋��|��Ԃ��������ꂽ�Ƃ���
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
		while (Input(1));
		cout << endl;
		cout << "Thank you for playing!" << endl;
	}
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
	// �ȉ��̃R�}���h����͂���܂Ń��[�v���J��Ԃ�
	/*
		�p�^�[��0�Fa, s, d
		�p�^�[��1�Ff
		�p�^�[��2�Fa, s, d, f
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
