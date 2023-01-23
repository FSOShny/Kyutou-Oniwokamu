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
	// テキスト1
	cout << "難易度を選択してください。" << endl;
	cout << "弱：a　中：s　強：d" << endl;
	while (Input(0));
	cout << endl;

	// 桃のパラメータと鬼のパラメータを設定する
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

	// テキスト2
	cout << "鬼が現れた！！" << "\n\n";
}

void Game::Playing()
{
	// 勝負が決まるまでループを繰り返す
	while (!(win || lose))
	{
		PeachTurn();
		DemonTurn();
		turn++;
	}
}

void Game::PeachTurn()
{
	// テキスト3
	cout << "桃は何をしますか？" << endl;
	cout << "攻撃：a　毒攻撃：s　防御：d　回復：f" << endl;
	while (Input(2));
	cout << endl;

	// 入力に応じて以下のアクションを行う

	/* 攻撃 */
	if (cmd == "a")
	{
		cout << "桃の攻撃！" << endl;
		peach.Attack();
		cout << "鬼は" << "（null）" << "のダメージを受けた。" << '\n\n';
	}

	/* 毒攻撃 */
	else if (cmd == "s")
	{
		cout << "桃は毒針を放った！" << endl;
		peach.PoisonAtk();
		cout << "鬼は" << "（null）" << "のダメージを受け、毒状態になった。" << '\n\n';
	}

	/* 防御 */
	else if (cmd == "d")
	{
		cout << "桃は防御の構えをとった。" << '\n\n';
		peach.Defend();
	}

	/* 回復 */
	else
	{
		cout << "桃は光合成を行った！" << endl;
		peach.Recover();
		cout << "桃は" << "（null）" << "だけ回復した。" << '\n\n';
	}
}

void Game::DemonTurn()
{
	// 現在のターン数に応じて以下のアクションを行う

	/* 攻撃 */
	if (turn % 4 == 1)
	{
		cout << "鬼の攻撃！" << endl;
		demon.Attack();
		cout << "桃は" << "（null）" << "のダメージを受けた。" << '\n\n';
	}

	/* 強攻撃 */
	else if (turn % 4 == 2)
	{
		cout << "鬼は強い一撃を放った！" << endl;
		demon.HeavyAtk();
		cout << "桃は" << "（null）" << "のダメージを受けた。" << '\n\n';
	}

	/* 挑発 */
	else if (turn % 4 == 3)
	{
		cout << "鬼は挑発している。" << '\n\n';
	}

	/* 防御 */
	else
	{
		cout << "鬼は防御の構えをとった。" << '\n\n';
		demon.Defend();
	}
}

void Game::Shutdown()
{
	// 勝負結果に応じたテキストを出力する

	/* 桃の勝ちとなった場合 */
	if (win)
	{
		cout << "鬼の体力がゼロになった。" << endl;
		cout << "桃の勝ち!!!" << endl;
		while (Input(1));
		cout << endl;
		cout << "Thank you for playing!" << endl;
	}

	/* 桃の負けとなった場合 */
	else
	{
		cout << "桃の体力がゼロになった。" << endl;
		cout << "桃の負け..." << endl;
		while (Input(1));
		cout << endl;
		cout << "May you win someday." << endl;
	}
}

bool Game::Input(int pattern)
{
	/* 

	以下のコマンドを入力するまでループを繰り返す

	パターン0の場合：a, s, d
	パターン1の場合：f
	パターン2の場合：a, s, d, f
	
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

	// 警告テキストを出力する
	cout << "（正しいコマンドを入力してください。）" << endl;
	return true;
}
