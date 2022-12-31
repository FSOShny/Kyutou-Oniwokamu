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

	cout << "鬼が現れた！！" << "\n\n";
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
		cout << "（桃の防御が解除された。）" << '\n\n';
	}

	cout << "桃は何をしますか？" << endl;
	cout << "攻撃：a　毒攻撃：s　防御：d　回復：f" << endl;
	while (Input(2));
	cout << endl;

	if (cmd == "a")
	{
		cout << "桃の攻撃！" << endl;
		cout << "鬼は" << peach.Attack(demon) << "のダメージを受けた。" << '\n\n';
	}
	else if (cmd == "s")
	{
		cout << "桃は毒針を放った！" << endl;
		cout << "鬼は" << peach.PoisonAtk(demon) << "のダメージを受け、毒状態になった。" << '\n\n';
	}
	else if (cmd == "d")
	{
		peach.Defend();
		cout << "桃は身を守っている。" << '\n\n';
	}
	else
	{
		cout << "桃は光合成を行った！" << endl;
		cout << "桃は" << peach.Recover() << "だけ回復した。" << '\n\n';
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
			cout << "（鬼の毒状態が解除された。）" << '\n\n';
		}
	}

	win = demon.CheckDead();
	if (win) return;

	if (demon.RemoveDefend())
	{
		cout << "（鬼の防御が解除された。）" << '\n\n';
	}

	if (demon.CheckAngered())
	{
		cout << "鬼は怒り状態になった！" << '\n\n';
	}

	if (turn % 4 == 1 || 
		turn % 4 == 3 && demon.IsAngered())
	{
		cout << "鬼の攻撃！" << endl;
		cout << "桃は" << demon.Attack(peach) << "のダメージを受けた。" << '\n\n';
	}
	else if (turn % 4 == 2)
	{
		cout << "鬼は強い一撃を放った！" << endl;
		cout << "桃は" << demon.HeavyAtk(peach) << "のダメージを受けた。" << '\n\n';
	}
	else if (turn % 4 == 3)
	{
		cout << "鬼は挑発している。" << '\n\n';
	}
	else
	{
		demon.Defend();
		cout << "鬼は身を守っている。" << '\n\n';
	}

	lose = peach.CheckDead();
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
	cout << "（正しいコマンドを入力してください。）" << endl;
	return true;
}
