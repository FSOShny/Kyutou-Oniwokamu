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
	cout << "�S�����ꂽ�I" << "\n\n";
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
	cout << "���͉������܂����H" << endl;
	cout << "�U���Fa�@�ōU���Fs�@�h��Fd�@�񕜁Ff" << endl;
	while (Input(2));
	cout << endl;
	if (cmd == "a")
	{
		peach.Attack(demon);
	}
	else if (cmd == "s")
	{
		peach.PoisonAtk(demon);
	}
	else if (cmd == "d")
	{
		peach.Defend();
	}
	else
	{
		peach.Recover();
	}
	lose = peach.StateCheck();
}

void Game::DemonTurn()
{
	if (lose)
	{
		return;
	}
	else if (turn % 4 < 2)
	{
		demon.Attack(peach);
	}
	else if (turn % 4 == 2)
	{
		demon.HeavyAtk(peach);
	}
	else
	{
		demon.Provoke();
	}
	win = demon.StateCheck();
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

bool Game::Input(int p)
{
	cin >> cmd;
	switch (p)
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
