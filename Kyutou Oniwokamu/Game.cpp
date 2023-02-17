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
	// 開始テキスト
	cout << "＜ゲームを開始します。＞" << endl;
	cout << "～次へ進む：f（または）e～" << "\n ▼ ";
	while (Input('B'));
	cout << endl;
}

bool Game::Playing()
{
	// 桃クラス、鬼クラス
	Peach peach;
	Demon demon;

	// 決闘前
	DuelBefore(peach, demon);

	// 勝負が決まるまでループする
	while (!(win || lose))
	{
		// 通常テキスト2
		cout << "--------------- " << turn << "ターン ---------------" << "\n\n";

		// 桃のターン
		PeachTurn(peach, demon);

		// この時点で勝負が決まっていればループから抜け出す
		if (win) break;

		// 鬼のターン
		DemonTurn(peach, demon);

		// 次のターンに移行する
		turn++;
	}

	// 決闘後
	return DuelAfter();
}

void Game::Shutdown()
{
	// 終了テキスト
	cout << "＜ゲームを終了します。＞" << endl;
	cout << "～次へ進む：f（または）e～" << "\n ▼ ";
	while (Input('B'));
	cout << endl;
}

void Game::DuelBefore(Peach& peach, Demon& demon)
{
	// 選択肢テキスト1
	// （ここで桃と鬼のパラメータを決定する）
	cout << "＜難易度を選択してください。＞" << endl;
	cout << "～弱：a　中：s　強：d～" << "\n ▼ ";
	while (Input('C'));
	cout << endl;
	if (cmd == "a")
	{
		/* 難易度「弱」のパラメーターを設定する */

		peach.Setter(350, 35);
		demon.Setter(333, 33);
	}
	else if (cmd == "s")
	{
		/* 難易度「中」のパラメーターを設定する */

		peach.Setter(500, 50);
		demon.Setter(666, 66);
	}
	else
	{
		/* 難易度「強」のパラメーターを設定する */

		peach.Setter(650, 65);
		demon.Setter(999, 99);
	}

	// 通常テキスト1
	cout << "鬼が現れた！！" << "\n\n";

	// 装飾テキスト1
	cout << "*********************************************" << "\n\n";
}

void Game::PeachTurn(Peach& peach, Demon& demon)
{
	// 選択肢テキスト2
	// （ここで桃のアクションを決定する）
	cout << "＜桃は何をしますか？＞" << endl;
	cout << "～攻撃：a　毒攻撃：s　防御：d　回復：f～" << "\n ▼ ";
	while (Input('A'));
	cout << endl;

	// 入力コマンドに応じて桃はアクションを行う
	/*
		入力コマンド「a」のとき：攻撃
		入力コマンド「s」のとき：毒攻撃
		入力コマンド「d」のとき：防御
		入力コマンド「f」のとき：回復
	*/
	if (cmd == "a")
	{
		/* 鬼にダメージ（効果量：中）を与える */

		cout << "● 桃の攻撃！" << "\n\n";
		damage = peach.Attack(2.0);
		cout << "　鬼は" << demon.Damaged(damage) << "のダメージを受けた！" << "\n\n";

		// 鬼が戦闘不能かどうかを確認する
		// （勝負が決まれば終了する）
		win = demon.CheckDead();
		if (win) return;
	}
	else if (cmd == "s")
	{
		/* 鬼にダメージ（効果量：小）を与え、毒状態にする */

		cout << "● 桃は毒針を放った！" << "\n\n";
		damage = peach.Attack(1.5);

		// （毒状態の重ね掛けは不可）
		if (!demon.CheckPoisoned())
		{
			demon.Poisoned();
			cout << "　鬼は" << demon.Damaged(damage) << "のダメージを受け、毒状態になった！" << "\n\n";
		}
		else
		{
			cout << "　鬼は" << demon.Damaged(damage) << "のダメージを受けた！" << "\n\n";
		}

		// 鬼が戦闘不能かどうかを確認する
		// （勝負が決まれば終了する）
		win = demon.CheckDead();
		if (win) return;
	}
	else if (cmd == "d")
	{
		/* 自分を防御状態にする */

		cout << "● 桃は防御の構えをとった。" << "\n\n";
		peach.Defend();
	}
	else
	{
		/* 自分を回復（効果量：大）する */

		cout << "● 桃は光合成を行った！" << "\n\n";
		damage = peach.Attack(-2.5);
		cout << "　桃は" << -peach.Damaged(damage) << "回復した！" << "\n\n";
	}

	// 鬼に毒ダメージを与える
	if (demon.CheckPoisoned())
	{
		cout << "　鬼は毒により、" << demon.Damaged(30) << "のダメージを受けた！" << "\n\n";
	}

	// 鬼が戦闘不能かどうかを確認する
	// （勝負が決まれば終了する）
	win = demon.CheckDead();
	if (win) return;

	// 鬼の毒状態が消えたときに
	// 専用テキストを出力する
	if (demon.RemovePoisoned())
	{
		cout << "　鬼の毒が消えた。" << "\n\n";
	}

	// 鬼が激怒状態であるときに
	// 専用テキストを出力する
	if (demon.CheckEnraged())
	{
		if (enragedTurn == 0)
		{
			cout << "　鬼は激怒状態になった！" << "\n\n";
			cout << "（鬼の攻撃力が倍になった。気を付けろ！）" << "\n\n";
			enragedTurn = turn;
		}
		else
		{
			cout << "　鬼は激怒状態のままだ。" << "\n\n";
			enragedTurn++;
		}
	}
}

void Game::DemonTurn(Peach& peach, Demon& demon)
{

	// 現在のターン数に応じて鬼はアクションを行う
	/*
		「1, 5, ...」ターンのとき：攻撃
		「2, 6, ...」ターンのとき：強攻撃
		「3, 7, ...」ターンのとき：挑発（激怒状態時：攻撃）
		「4, 8, ...」ターンのとき：咆哮
	*/
	if (turn % 4 == 1 || enragedTurn % 4 == 3)
	{
		/* 桃にダメージ（効果量：中）を与える */

		cout << "◆ 鬼の攻撃！" << "\n\n";
		damage = demon.Attack(1.0);
		cout << "　桃は" << peach.Damaged(damage) << "のダメージを受けた！" << "\n\n";

		// 桃が戦闘不能かどうかを確認する
		// （勝負が決まれば終了する）
		lose = peach.CheckDead();
		if (lose) return;
	}
	else if (turn % 4 == 2)
	{
		/* 桃にダメージ（効果量：大）を与える */

		cout << "◆ 鬼は強い一撃を放った！" << "\n\n";
		damage = demon.Attack(2);
		cout << "　桃は" << peach.Damaged(damage) << "のダメージを受けた！" << "\n\n";

		// 桃が戦闘不能かどうかを確認する
		// （勝負が決まれば終了する）
		lose = peach.CheckDead();
		if (lose) return;
	}
	else if (turn % 4 == 3)
	{
		/* 何も発生しない */

		cout << "◆ 鬼は挑発している。" << "\n\n";
	}
	else
	{
		/* 桃を恐怖状態にする */

		cout << "◆ 鬼は咆哮を行った！" << "\n\n";

		// （恐怖状態の重ね掛けは不可）
		if (!peach.CheckFrightened())
		{
			peach.Frightened();
			cout << "　桃は恐怖状態になった。" << "\n\n";
			cout << "（しばらくの間、桃の攻撃力が半分になってしまう。）" << "\n\n";
		}
		else
		{
			cout << "　桃はすでに恐怖状態だ。" << "\n\n";
		}
	}

	// 桃が防御状態が消えたときに
	// 専用テキストを出力する
	if (peach.CheckDefend())
	{
		cout << "　桃は防御の構えをやめた。" << "\n\n";
	}

	// 桃の恐怖状態が消えたときに
	// 専用テキストを出力する
	if (peach.RemoveFrightened())
	{
		cout << "　桃の恐怖が消えた。" << "\n\n";
	}
}

bool Game::DuelAfter()
{
	// 装飾テキスト2
	cout << "*********************************************" << "\n\n";

	// 勝ち負けに応じた専用テキストを出力する
	if (win)
	{
		cout << "鬼の体力がゼロになった。" << "\n\n";
		cout << "桃の勝ち!!!" << "\n\n";
		cout << "～次へ進む：f（または）e～" << "\n ▼ ";
		while (Input('B'));
		cout << endl;
		cout << "★★★ Thank you for playing! ★★★" << "\n\n";
	}
	else
	{
		cout << "桃の体力がゼロになった。" << "\n\n";
		cout << "桃の負け..." << "\n\n";
		cout << "～次へ進む：f（または）e～" << "\n ▼ ";
		while (Input('B'));
		cout << endl;
		cout << "■■■ May you win someday. ■■■" << "\n\n";
	}

	// 選択肢テキスト2
	// （ここでゲームプレイをリトライするかどうかを決定する）
	cout << "＜ゲームプレイをリトライしますか？＞" << endl;
	cout << "～はい：f　いいえ：e～" << "\n ▼ ";
	while (Input('B'));
	cout << endl;
	if (cmd == "f")
	{
		/* プレイデータを初期化してからリトライする */

		win = false;
		lose = false;
		turn = 1;
		enragedTurn = 0;
		return true;
	}
	else
	{
		/* そのままシャットダウン処理に移行する */

		return false;
	}
}

bool Game::Input(char pattern)
{
	/*
	
		正しい入力コマンドは以下の通り
		（正しく入力するまではループする）

		パターン「A」のとき：a, s, d, f
		パターン「B」のとき：f, e
		パターン「C」のとき：a, s, d

	*/
	cin >> cmd;
	switch (pattern)
	{
	case 'A':
		if (cmd == "a" || cmd == "s" || cmd == "d" || cmd == "f") return false;
		break;
	case 'B':
		if (cmd == "f" || cmd == "e") return false;
		break;
	default:
		if (cmd == "a" || cmd == "s" || cmd == "d") return false;
		break;
	}

	// 警告テキスト
	cout << "/*正しいコマンドを入力してください。*/" << "\n ▼ ";
	return true;
}
