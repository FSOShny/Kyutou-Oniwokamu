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
	// 通常テキスト1
	cout << "（ゲームを開始します。）" << endl;
	while (Input('B'));
	cout << endl;

	// 選択肢テキスト1
	// （ここで鬼のパラメータの強さを決定する）
	cout << "難易度を選択してください。" << endl;
	cout << "弱：a　中：s　強：d" << endl;
	while (Input('C'));
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

	// 通常テキスト2
	cout << "鬼が現れた！！" << "\n\n";
}

void Game::Playing()
{
	/*
	
		ターンの流れは以下の通り

		桃 -> 鬼 -> 桃 -> …
	
	*/

	// 勝負が決まるまではループする
	while (!(win || lose))
	{
		PeachTurn();

		// この時点で勝負が決まっていればループから抜け出す
		if (win) break;

		DemonTurn();

		// ターン数を増やす
		turn++;
	}
}

void Game::PeachTurn()
{
	// 選択肢テキスト2
	// （ここで桃のアクションを決定する）
	cout << "桃は何をしますか？" << endl;
	cout << "攻撃：a　毒攻撃：s　防御：d　回復：f" << endl;
	while (Input('A'));
	cout << endl;

	// 入力コマンドに応じて桃はアクションを行う
	/*
		入力コマンドaのとき：攻撃
		入力コマンドsのとき：毒攻撃
		入力コマンドdのとき：防御
		入力コマンドfのとき：回復
	*/
	if (cmd == "a")
	{
		/* 鬼に中ダメージを与える */

		cout << "桃の攻撃！" << endl;
		damage = peach.Attack();
		cout << "鬼は" << demon.Damaged(damage) << "のダメージを受けた！" << "\n\n";

		// 鬼が戦闘不能かどうかを確認する
		// （桃の勝利であれば終了）
		win = demon.CheckDead();
		if (win) return;
	}
	else if (cmd == "s")
	{
		/* 鬼に小ダメージを与え、毒状態にする */

		cout << "桃は毒針を放った！" << endl;
		damage = peach.PoisonAtk();

		// （毒状態の重ね掛けは不可）
		if (!demon.CheckPoisoned())
		{
			demon.Poisoned();
			cout << "鬼は" << demon.Damaged(damage) << "のダメージを受け、毒状態になった！" << "\n\n";
		}
		else
		{
			cout << "鬼は" << demon.Damaged(damage) << "のダメージを受けた！" << "\n\n";
		}

		// 鬼が戦闘不能かどうかを確認する
		// （桃の勝利であれば終了）
		win = demon.CheckDead();
		if (win) return;
	}
	else if (cmd == "d")
	{
		/* 自分を防御状態にする */

		cout << "桃は防御の構えをとった。" << "\n\n";
		peach.Defend();
	}
	else
	{
		/* 自分を中回復する */

		cout << "桃は光合成を行った！" << endl;
		damage = peach.Recover();
		cout << "桃は" << -peach.Damaged(damage) << "回復した！" << "\n\n";
	}

	// 鬼の毒状態が消えたときに
	// 専用テキストを出力する
	if (demon.RemovePoisoned() && !demon.CheckDead())
	{
		cout << "鬼の毒が消えた。" << "\n\n";
	}

	// 鬼が戦闘不能かどうかを確認する
	// （桃の勝利であれば終了）
	win = demon.CheckDead();
	if (win) return;

	// 鬼が激怒状態であるときに
	// 専用テキストを出力する
	if (demon.CheckEnraged())
	{
		if (enragedTurn == 0)
		{
			cout << "鬼は激怒状態になった！" << "\n\n";
			enragedTurn = turn;
		}
		else
		{
			cout << "鬼は激怒状態のままだ。" << "\n\n";
			enragedTurn++;
		}
	}
}

void Game::DemonTurn()
{

	// 現在のターン数に応じて鬼はアクションを行う
	/*
		1, 5, ... ターンのとき：攻撃
		2, 6, ... ターンのとき：強攻撃
		3, 7, ... ターンのとき：挑発（激怒状態時：攻撃）
		4, 8, ... ターンのとき：咆哮
	*/
	if (turn % 4 == 1 || enragedTurn % 4 == 3)
	{
		/* 桃に中ダメージを与える */

		cout << "鬼の攻撃！" << endl;
		damage = demon.Attack();
		cout << "桃は" << peach.Damaged(damage) << "のダメージを受けた！" << "\n\n";

		// 桃が戦闘不能かどうかを確認する
		// （桃の負けであれば終了）
		lose = peach.CheckDead();
		if (lose) return;
	}
	else if (turn % 4 == 2)
	{
		/* 桃に大ダメージを与える */

		cout << "鬼は強い一撃を放った！" << endl;
		damage = demon.HeavyAtk();
		cout << "桃は" << peach.Damaged(damage) << "のダメージを受けた！" << "\n\n";

		// 桃が戦闘不能かどうかを確認する
		// （桃の負けであれば終了）
		lose = peach.CheckDead();
		if (lose) return;
	}
	else if (turn % 4 == 3)
	{
		/* 何も発生しない */
		cout << "鬼は挑発している。" << "\n\n";
	}
	else
	{
		/* 桃を恐怖状態にする */

		cout << "鬼は咆哮を行った！" << endl;

		// （恐怖状態の重ね掛けは不可）
		if (!peach.CheckFrightened())
		{
			peach.Frightened();
			cout << "桃は恐怖状態になった。" << "\n\n";
		}
	}

	// 桃が防御状態であるときに
	// 状態を解除し、専用テキストを出力する
	if (peach.CheckDefend())
	{
		cout << "桃は防御の構えをやめた。" << "\n\n";
	}

	// 桃の恐怖状態が消えたときに
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
		while (Input('B'));
		cout << endl;
		cout << "Thank you for playing!" << endl;
	}
	else
	{
		cout << "桃の体力がゼロになった。" << endl;
		cout << "桃の負け..." << endl;
		while (Input('B'));
		cout << endl;
		cout << "May you win someday." << endl;
	}

	// 通常テキスト3
	cout << endl << "（ゲームを終了します。）" << endl;
	while (Input('B'));
}

bool Game::Input(char pattern)
{
	/*
	
		正しい入力コマンドは以下の通り
		（正しく入力するまではループする）

		パターンAのとき：a, s, d, f
		パターンBのとき：f
		パターンCのとき：a, s, d

	*/
	cin >> cmd;
	switch (pattern)
	{
	case 'A':
		if (cmd == "a" || cmd == "s" || cmd == "d" || cmd == "f") return false;
		break;
	case 'B':
		if (cmd == "f") return false;
		break;
	default:
		if (cmd == "a" || cmd == "s" || cmd == "d") return false;
		break;
	}

	// 警告テキストを出力する
	cout << "（正しいコマンドを入力してください。）" << endl;
	return true;
}
