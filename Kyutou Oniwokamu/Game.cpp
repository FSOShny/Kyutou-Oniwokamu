#include "Game.h"

Game::Game()
	: cmd("")
	, win(false)
	, lose(false)
	, turn(0)
{
}

void Game::Startup()
{
	cout << "��Փx��I�����Ă��������B" << endl;
	cout << "��Fa�@���Fs�@���Fd" << endl;
	while (Input(0));
	cout << endl;
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

	cout << "�S�����ꂽ�I�I" << "\n\n";
}

void Game::Playing()
{
	while (!(win || lose))
	{
		turn++;
		PeachTurn();
		DemonTurn();
	}
}

void Game::PeachTurn()
{
	if (peach.RemoveDefend())
	{
		cout << "�i���̖h�䂪�������ꂽ�B�j" << '\n\n';
	}

	cout << "���͉������܂����H" << endl;
	cout << "�U���Fa�@�ōU���Fs�@�h��Fd�@�񕜁Ff" << endl;
	while (Input(2));
	cout << endl;

	if (cmd == "a")
	{
		cout << "���̍U���I" << endl;
		cout << "�S��" << peach.Attack(demon) << "�̃_���[�W���󂯂��B" << '\n\n';
	}
	else if (cmd == "s")
	{
		cout << "���͓Őj��������I" << endl;
		cout << "�S��" << peach.PoisonAtk(demon) << "�̃_���[�W���󂯁A�ŏ�ԂɂȂ����B" << '\n\n';
	}
	else if (cmd == "d")
	{
		peach.Defend();
		cout << "���͐g������Ă���B" << '\n\n';
	}
	else
	{
		cout << "���͌��������s�����I" << endl;
		cout << "����" << peach.Recover() << "�����񕜂����B" << '\n\n';
	}

	win = demon.CheckDead();
}

void Game::DemonTurn()
{
	if (win) return;

	if (demon.RemovePoisoned())
	{
		if (!demon.CheckDead())
		{
			cout << "�i�S�̓ŏ�Ԃ��������ꂽ�B�j" << '\n\n';
		}
	}

	win = demon.CheckDead();
	if (win) return;

	if (demon.RemoveDefend())
	{
		cout << "�i�S�̖h�䂪�������ꂽ�B�j" << '\n\n';
	}

	if (demon.CheckAngered())
	{
		cout << "�S�͓{���ԂɂȂ����I" << '\n\n';
	}

	if (turn % 4 == 1 || 
		turn % 4 == 3 && demon.IsAngered())
	{
		cout << "�S�̍U���I" << endl;
		cout << "����" << demon.Attack(peach) << "�̃_���[�W���󂯂��B" << '\n\n';
	}
	else if (turn % 4 == 2)
	{
		cout << "�S�͋����ꌂ��������I" << endl;
		cout << "����" << demon.HeavyAtk(peach) << "�̃_���[�W���󂯂��B" << '\n\n';
	}
	else if (turn % 4 == 3)
	{
		cout << "�S�͒������Ă���B" << '\n\n';
	}
	else
	{
		demon.Defend();
		cout << "�S�͐g������Ă���B" << '\n\n';
	}

	lose = peach.CheckDead();
}

void Game::Shutdown()
{
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
		cout << "���̔s�k..." << endl;
		while (Input(1));
		cout << endl;
		cout << "May you win someday." << endl;
	}
}

bool Game::Input(int pattern)
{
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
	cout << "�i�������R�}���h����͂��Ă��������B�j" << endl;
	return true;
}
