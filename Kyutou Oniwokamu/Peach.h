#pragma once
#include "Character.h"

class Peach : public Character
{
public:
	// 桃クラスのコンストラクタ
	Peach();

	// 桃がダメージを受けたときのメソッド
	int Damaged(int damage) override;
	// 桃が防御を行うときのメソッド
	void Defend();
	// 桃が防御状態かどうかを確認するメソッド
	bool CheckDefend();
	// 桃が恐怖状態になるときのメソッド
	void Frightened();
	// 桃が恐怖状態かどうかを確認するメソッド
	bool CheckFrightened();
	// 鬼の毒状態が消えたかどうかを確認するメソッド
	bool RemoveFrightened();
private:
	// 桃の防御状態を表すフラグ定数
	unsigned int isDefend = (1 << 1);
	// 桃の恐怖状態を表すフラグ定数
	unsigned int isFrightened = (1 << 2);
	// 恐怖状態の残りターン数
	int frightenedTurn;
};
