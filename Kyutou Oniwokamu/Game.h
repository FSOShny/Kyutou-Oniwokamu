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
	// ゲームを開始するときの処理
	void Startup();
	// ゲームをプレイしているときの処理
	void Playing();
	// ゲームを終了するときの処理
	void Shutdown();
private:
	// 桃のターンであるときの処理
	void PeachTurn();
	// 鬼のターンであるときの処理
	void DemonTurn();
	// コマンドを入力するときの処理
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
	// 桃クラス
	Peach peach;
	// 鬼クラス
	Demon demon;
};
