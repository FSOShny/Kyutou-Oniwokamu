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

		// この時点で勝負が決まっていればループ終了
		if (win) break;

		DemonTurn();

		// ターンを進める
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

	// 入力コマンドに応じて以下のアクションを行う
	/*
		入力コマンドa：攻撃（鬼へ中ダメージを与える）
		入力コマンドs：毒攻撃（鬼へ小ダメージを与え、毒状態にする）
		入力コマンドd：防御（自分を防御状態にする）
		入力コマンドf：回復（自分を中回復する）
	*/
	if (cmd == "a")
	{
		cout << "桃の攻撃！" << endl;
		damage = peach.Attack();
		cout << "鬼は" << demon.Damaged(damage) << "のダメージを受けた！" << "\n\n";

		// 鬼の体力がゼロかどうかを確認する
		// （桃の勝利であれば終了）
		win = demon.CheckDead();
		if (win) return;
	}
	else if (cmd == "s")
	{
		cout << "桃は毒針を放った！" << endl;
		damage = peach.PoisonAtk();

		// （毒状態の重ね掛けは不可）
		if (!demon.CheckPoisoned())
		{
			demon.Poisoned();
		}

		cout << "鬼は" << demon.Damaged(damage) << "のダメージを受け、毒状態になった！" << "\n\n";

		// 鬼の体力がゼロかどうかを確認する
		// （桃の勝利であれば終了）
		win = demon.CheckDead();
		if (win) return;
	}
	else if (cmd == "d")
	{
		cout << "桃は防御の構えをとった。" << "\n\n";
		peach.Defend();
	}
	else
	{
		cout << "桃は光合成を行った！" << endl;
		damage = peach.Recover();
		cout << "桃は" << peach.Damaged(damage) << "回復した！" << "\n\n";
	}

	// 鬼が怒り状態になったときに
	// 専用テキストを出力する
	if (demon.CheckEnraged())
	{
		cout << "鬼は怒り状態になった！" << "\n\n";
	}

	// 鬼の毒状態が解除されたときに
	// 専用テキストを出力する
	if (demon.RemovePoisoned() && !demon.CheckDead())
	{
		cout << "鬼の毒が消えた。" << "\n\n";
	}

	// 鬼の体力がゼロかどうかを確認する
	// （桃の勝利であれば終了）
	win = demon.CheckDead();
	if (win) return;
}

void Game::DemonTurn()
{

	// 現在のターン数に応じて以下のアクションを行う
	/*
		4n+1（1, 5, 9, ...）ターン：攻撃（桃へ中ダメージを与える）
		4n+2（2, 6, 10, ...）ターン：強攻撃（桃へ大ダメージを与える）
		4n+3（3, 7, 11, ...）ターン：挑発（何も発生しない）
		4n+4（4, 8, 12, ...）ターン：咆哮（桃を恐怖状態にする）
	*/
	if (turn % 4 == 1)
	{
		cout << "鬼の攻撃！" << endl;
		damage = demon.Attack();
		cout << "桃は" << peach.Damaged(damage) << "のダメージを受けた！" << "\n\n";

		// 桃の体力がゼロかどうかを確認する
		// （桃の負けであれば終了）
		lose = peach.CheckDead();
		if (lose) return;
	}
	else if (turn % 4 == 2)
	{
		cout << "鬼は強い一撃を放った！" << endl;
		damage = demon.HeavyAtk();
		cout << "桃は" << peach.Damaged(damage) << "のダメージを受けた！" << "\n\n";

		// 桃の体力がゼロかどうかを確認する
		// （桃の負けであれば終了）
		lose = peach.CheckDead();
		if (lose) return;
	}
	else if (turn % 4 == 3)
	{
		cout << "鬼は挑発している。" << "\n\n";
	}
	else
	{
		cout << "鬼は咆哮を行った！" << endl;

		// （恐怖状態の重ね掛けは不可）
		if (!peach.CheckFrightened())
		{
			peach.Frightened();
		}

		cout << "桃は恐怖状態になった。" << "\n\n";
	}

	// 桃が防御状態であるときに
	// 状態を解除し、専用テキストを出力する
	if (peach.CheckDefend())
	{
		cout << "桃は防御の構えをやめた。" << "\n\n";
	}

	// 桃の恐怖状態が解除されたときに
	// 専用テキストを出力する
	if (peach.RemoveFrightened())
	{
		cout << "桃の恐怖が消えた。" << "\n\n";
	}
}

void Game::Shutdown()
{
	// 勝ち負けに応じて専用テキストを出力する
	if (win)
	{
		cout << "鬼の体力がゼロになった。" << endl;
		cout << "桃の勝ち!!!" << endl;
		while (Input(1));
		cout << endl;
		cout << "Thank you for playing!" << endl;
	}
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
	// 以下のコマンドを入力するまでループを繰り返す
	/*
		パターン0：a, s, d
		パターン1：f
		パターン2：a, s, d, f
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
