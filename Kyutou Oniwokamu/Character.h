#pragma once

class Character
{
public:
	// キャラクター（桃, 鬼）クラスのコンストラクタ
	Character();
	// キャラクターのパラメータを設定するときの処理
	virtual void Setter(int hp, int ap) = 0;
	// キャラクターがダメージを与えるときの処理
	virtual int Attack(double rate) = 0;
	// キャラクターがダメージを受けたときの処理
	virtual int Damaged(int damage) = 0;
	// キャラクターが戦闘不能かどうかを確認する処理
	virtual bool CheckDead() = 0;
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
