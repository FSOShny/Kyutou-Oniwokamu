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
	cout << "難易度を選択してください。" << endl;
	cout << "弱：a　中：s　強：d" << endl;
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
	cout << "鬼が現れた！" << "\n\n";
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
	cout << "桃は何をしますか？" << endl;
	cout << "攻撃：a　毒攻撃：s　防御：d　回復：f" << endl;
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
