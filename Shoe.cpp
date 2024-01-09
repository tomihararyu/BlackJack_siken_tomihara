#include "Shoe.h"
#include <iostream>
#include <random> //乱数生成

using namespace std;

//シャッフル（フィッシャーイェーツ）
void Shoe::_shuffle()
{
	for (int i = _cardNum; i > 1; --i) {
		int a = i - 1;
		int b = rand() % i;
		swap(_cardShoe[a], _cardShoe[b]);
	}
	for (int i = 0; i < 52; i++)
	{
		cout << _cardShoe[i] << endl;
	}
}
void Shoe::_Set()
{
	//カードを入れてく0.... /13でカード種類とする
	for (int i = 0; i < CARD; i++) {
		_cardShoe[i] = i;
	}
	_cardNum = CARD-1; //カード枚数の設定
}

//コンストラクタ
Shoe::Shoe() {

	_Set();//カードの追加
	//シャッフル
	_shuffle();
}

//カードシューを表示(デバッグ用)
void Shoe::showShoe(SHOW_TYPE type) const 
{
	int roopCnt = NUM;
	if (type == CARD_ONLY) {	//カード枚数分表示
		//カードのみ表示にする。
		roopCnt = _cardNum;
	}

	for (int i = 0; i < roopCnt; i++) {
		cout << _cardShoe[i] << ' ';
	}
	cout << endl;
}

//カードを1枚取り出す
int Shoe::takeCard() {
	//カード枚数が0以下だった場合,エラーとして出力
	if (_cardNum <= 0) {
		cout << "シューにカードがありません。" << endl;
		cout << "シャッフルします" << endl;
		_Set();
		_shuffle();
		_cardNum = CARD-1;
	}
	int card = _cardShoe[_cardNum];
	--_cardNum;
	return card;
}
