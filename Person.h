#pragma once

#include "common.h"

class Shoe;

class Person
{
private:
	int _hand[HAND_SIZE];	// 理論上これくらい持てばOK...に今回はしちゃう
	bool _calcUpdate;
	int _cardNum;//所持しているカード枚数
	int _score;//スコア

public:
	// コンストラクタ
	Person();

	//スコアの取得(hitされた時のみ再計算される)
	int getScore();

	//カードの追加
	void hit(Shoe* shoe);

	//手札を表示
	void showHand();

	//ターン処理
	bool play(Shoe* shoe);

protected:
	virtual void playBase(Shoe* shoe);	//ターン処理本体
	char* p_num;

};

