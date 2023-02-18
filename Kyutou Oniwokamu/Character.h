#pragma once

class Character
{
public:
	// キャラクター（桃, 鬼）クラスのコンストラクタ
	Character();

	// キャラクターのパラメータを設定するときのメソッド
	void Setter(int hp, int ap);
	// キャラクターがダメージを与えるときのメソッド
	int Attack(double rate);
	// キャラクターが戦闘不能かどうかを確認するメソッド
	bool CheckDead();
	// キャラクターがダメージを受けたときのメソッド
	virtual int Damaged(int damage) = 0;
protected:
	// 現在の体力
	int hp;
	// 体力の最大値
	int maxHp;
	// 現在の攻撃力
	int ap;
	// キャラクターが状態異常かどうかのフラグ変数
	unsigned int state;
	// キャラクターの戦闘不能を表すフラグ定数
	const unsigned int isDead = (1 << 0);
};
