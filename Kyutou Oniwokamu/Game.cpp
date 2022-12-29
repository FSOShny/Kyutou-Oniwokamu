#include "Game.h"

Game::Game()
	: cmd("")
	, loop(true)
	, win(false)
{
}

void Game::Startup()
{
	cout << "難易度を選択してください。" << endl;
	cout << "弱：a　中：s　強：d" << endl;
	while (Input(0));
	cout << endl;
	cout << "鬼が現れた！" << "\n\n";
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
	cout << "桃は何をしますか？" << endl;
	cout << "攻撃：a　毒攻撃：s　防御：d　回復：f" << endl;
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
		cout << "鬼の体力がゼロになった。" << endl;
		cout << "桃の勝利!!!" << endl;
		while (Input(1));
		cout << endl;
		cout << "Thank you for playing!" << endl;
	}
	else
	{
		cout << "桃の体力がゼロになった。" << endl;
		cout << "桃の敗北..." << endl;
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
	cout << "（正しいコマンドを入力してください。）" << endl;
	return true;
}
