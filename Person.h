#pragma once

#include "common.h"

class Shoe;

class Person
{
private:
	int _hand[HAND_SIZE];	// ���_�ケ�ꂭ�炢���Ă�OK...�ɍ���͂����Ⴄ
	bool _calcUpdate;
	int _cardNum;//�������Ă���J�[�h����
	int _score;//�X�R�A

public:
	// �R���X�g���N�^
	Person();

	//�X�R�A�̎擾(hit���ꂽ���̂ݍČv�Z�����)
	int getScore();

	//�J�[�h�̒ǉ�
	void hit(Shoe* shoe);

	//��D��\��
	void showHand();

	//�^�[������
	bool play(Shoe* shoe);

protected:
	virtual void playBase(Shoe* shoe);	//�^�[�������{��
	char* p_num;

};

