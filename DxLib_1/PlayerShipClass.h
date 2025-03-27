#pragma once
#include "DxLib.h"
#include "AmmoClass.h"
#include <vector>

using namespace std;

const int keyNum = 256;

class PlayerShip
{
private:
	int m_shipPosX, m_shipPosY; // �v���C���[��X.Ypos
	int m_shipGraph; // �v���C���[�̉摜
	int m_movePower; // �v���C���[�̈ړ����x�i�����l�͂R�j���܂��ύX�ł��Ȃ����ł���悤�ɂ���
	char m_keyState[keyNum];
	vector<Ammo> m_ammoList; // �e���Ǘ��pvector

public:
	PlayerShip(int shipPosX, int shipPosY, const char* shipGraph);

	// �v���C���[��`�悷��
	int DrawShip() const;

	// �L�[�̎擾
	void KeyInput(float dt);

	// �}�E�X�̎擾 
	void MouseInput();

	//�e������֔�΂��i���̍����ɂȂ���������j
	void AmmoUpdate(float dt);
};
