#pragma once
#include "Character.h"

class Demon : public Character
{
public:
	// 鬼クラスのコンストラクタ
	Demon();

	// （キャラクタークラスメソッドのオーバーライド）
	void Setter(int hp, int ap) override;
	int Attack(double rate) override;
	int Damaged(int damage) override;
	bool CheckDead() override;

	// 鬼が激怒状態かどうかを確認する処理
	bool CheckEnraged();
	// 鬼が毒状態になるときの処理
	void Poisoned();
	// 鬼が毒状態かどうかを確認する処理
	bool CheckPoisoned();
	// 鬼の毒状態が消えたかどうかを確認する処理
	bool RemovePoisoned();
private:
	// 鬼の激怒状態を表すフラグ定数
	const unsigned int isEnraged = (1 << 1);
	// 鬼の毒状態を表すフラグ定数
	const unsigned int isPoisoned = (1 << 2);
	// 毒状態の残りターン数
	int poisonedTurn;
};
