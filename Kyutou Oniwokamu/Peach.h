#pragma once
#include "Character.h"

class Peach : public Character
{
public:
	// 桃クラスのコンストラクタ
	Peach();

	// （キャラクタークラスメソッドのオーバーライド）
	void Setter(int hp, int ap) override;
	int Attack(double rate) override;
	int Damaged(int damage) override;
	bool CheckDead() override;

	// 桃が防御を行うときの処理
	void Defend();
	// 桃が防御状態かどうかを確認する処理
	bool CheckDefend();
	// 桃が恐怖状態になるときの処理
	void Frightened();
	// 桃が恐怖状態かどうかを確認する処理
	bool CheckFrightened();
	// 鬼の毒状態が消えたかどうかを確認する処理
	bool RemoveFrightened();
private:
	// 桃の防御状態を表すフラグ定数
	unsigned int isDefend = (1 << 1);
	// 桃の恐怖状態を表すフラグ定数
	unsigned int isFrightened = (1 << 2);
	// 恐怖状態の残りターン数
	int frightenedTurn;
};
