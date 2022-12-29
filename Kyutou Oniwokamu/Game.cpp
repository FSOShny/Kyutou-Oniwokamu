#include "Game.h"

Game::Game()
	: cmd("")
	, loop(true)
	, win(false)
{
}

void Game::Startup()
{
	cout << "��Փx��I�����Ă��������B" << endl;
	cout << "��Fa�@���Fs�@���Fd" << endl;
	while (Input(0));
	cout << endl;
	cout << "�S�����ꂽ�I" << "\n\n";
}

void Game::Playing()
{
	Setting();

	while (loop)
	{
		PeachTurn();
		DemonTurn();
	}
}

void Game::Setting()
{
}

void Game::PeachTurn()
{
	cout << "���͉������܂����H" << endl;
	cout << "�U���Fa�@�ōU���Fs�@�h��Fd�@�񕜁Ff" << endl;
	while (Input(2));
	cout << endl;
}

void Game::DemonTurn()
{
	loop = false;
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
