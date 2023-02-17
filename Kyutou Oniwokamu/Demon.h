#pragma once
#include "Character.h"

class Demon : public Character
{
public:
	// 鬼クラスのコンストラクタ
	Demon();

	// 鬼がダメージを受けたときのメソッド
	int Damaged(int damage) override;
	// 鬼が激怒状態かどうかを確認するメソッド
	bool CheckEnraged();
	// 鬼が毒状態になるときのメソッド
	void Poisoned();
	// 鬼が毒状態かどうかを確認するメソッド
	bool CheckPoisoned();
	// 鬼の毒状態が消えたかどうかを確認するメソッド
	bool RemovePoisoned();
private:
	// 鬼の激怒状態を表すフラグ定数
	const unsigned int isEnraged = (1 << 1);
	// 鬼の毒状態を表すフラグ定数
	const unsigned int isPoisoned = (1 << 2);
	// 毒状態の残りターン数
	int poisonedTurn;
};
