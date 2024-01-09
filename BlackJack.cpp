#include <iostream> //入出力

#include "Shoe.h"
#include "Player.h"
#include "Dealer.h"

using namespace std;

//
// 試験用ブラックジャックソース
// 正常動作していない。

// ★★★★★★★★★★★★★★★★
static void showResult(Person** p)
{
	cout << "============================" << endl;
	cout << "            result          " << endl;
	cout << "============================" << endl;
	cout << "============================" << endl;
	cout << "player1" << endl;
	p[0]->showHand();
	cout << "============================" << endl;
	cout << "player2" << endl;
	p[1]->showHand();
	cout << "============================" << endl;
	cout << "player3" << endl;
	p[2]->showHand();
	cout << "dealer" << endl;
	p[3]->showHand();
	cout << "============================" << endl;

	for (int i = 0; i < 3; i++)
	{
		if (p[i]->getScore() > p[3]->getScore()) {
			cout << "Player Win!" << endl;
		}
		else if (p[i]->getScore() < p[3]->getScore()) {
			cout << "Player Lose" << endl;
		}
		else {
			cout << "Push" << endl;
		}
	}

}

static void showHand(Person* p, const char* name = "player")
{
	//手札の表示
	cout << "====================" << endl;
	cout << name << endl;
	p->showHand();
	cout << "====================" << endl;

}

//メイン関数
int main() {

	srand((unsigned int)time(NULL));

	enum PERSON
	{
		PLAYER, DEALER
	};

	//各オブジェクトの生成
	Shoe shoe;
	Person* persons[] = { new Player, new Player, new Player,new Dealer};
	const char* name[] = {"player1","player2","player3","dealer"};
	const int num = sizeof(persons) / sizeof(Person*);

	//----カードの配布 ... 初期
	cout << "====================" << endl;
	for (int i = 0; i < num; i++)
	{
		persons[i]->hit(&shoe);
		showHand(persons[i], name[i]);
	}
	//プレイヤーに2枚目を配布
	persons[PLAYER]->hit(&shoe);
	showHand(persons[PLAYER]);

	//ディーラーに2枚目を配布
	persons[DEALER]->hit(&shoe);

	// ----　勝負開始
	//プレイヤーの実行
	//バーストしているかどうか判別
	for(int i=0;i<3;i++)
	{
		cout << name[i] << ":" << endl;
		if (persons[i]->play(&shoe)) {
		//バーストせずstandした
		//ディーラーの手札を表示

		}
		else {
			cout << "Burst Player Lose" << endl;
		}
	}
	showHand(persons[DEALER], "dealer");
	//ディーラーの自動実行
	persons[DEALER]->play(&shoe);

	//結果の表示
	showResult(persons);
	cout << "====================" << endl;
	return 0;
}