#pragma once
#include <iostream>
#include "Peach.h"
#include "Demon.h"
using namespace std;

class Game
{
public:
	// ゲームクラスのコンストラクタ
	Game();

	// ゲームを開始するときのメソッド
	void Startup();
	// ゲームをプレイしているときのメソッド
	bool Playing();
	// ゲームを終了するときのメソッド
	void Shutdown();
private:
	// 桃と鬼の決闘前のメソッド
	void DuelBefore(Peach& peach, Demon& demon);
	// 桃のターンであるときのメソッド
	void PeachTurn(Peach& peach, Demon& demon);
	// 鬼のターンであるときのメソッド
	void DemonTurn(Peach& peach, Demon& demon);
	// 桃と鬼の決闘後のメソッド
	bool DuelAfter();
	// コマンドを入力するときのメソッド
	bool Input(char pattern);

	// 入力コマンド
	string cmd;
	// 桃が勝ったかどうかのフラグ変数
	bool win;
	// 桃が負けたかどうかのフラグ変数
	bool lose;
	// 現在のターン数
	int turn;
	// 現在のターン数
	// （激怒状態の鬼のアクションを変化させるための整数）
	int enragedTurn;
	// 与えたダメージ量（または回復量）
	int damage;
};
