#include <iostream>
#include "Player.h"
#include "Shoe.h"

using namespace std;

//�Q�[�����s
void Player::playBase(Shoe* shoe) {
	//�o�[�X�g����܂Ń��[�v����
	while (getScore()) {
		cout << "hit or stand >> ";

		//����
		char str[16]; //������^
		cin >> str; //����������
		//hit�����͂��ꂽ�ꍇ
		if (strcmp(str, "hit") == 0) {
			//�J�[�h�̔z�z
			hit(shoe);

			//��D�̕\��
			cout << "====================" << endl;
			cout << "player" << endl;
			showHand();
			cout << "====================" << endl;
		}
		else if (strcmp(str, "stand") == 0) {
			//�I������
			break;
		}
	}
}
