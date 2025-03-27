#include "DxLib.h"
#include "AmmoClass.h"
#include "PlayerShipClass.h"
#include "TimeManagerClass.h"
#include <vector>

using namespace std;
using namespace std::chrono;

//const int keyNum = 256;
//
//class Ammo
//{
//private:
//	int m_ammoXPos, m_ammoYPos; // �e��X.YPos
//	int m_ammoGraph; // �e�̉摜
//	int m_ammoDamage; // �e�̃_���[�W�@�����̂Ƃ���ꔭ�œ|����
//	int m_ammoSpeed; // �e�̑��x�@���ύX�ł���悤�ɂ���
//
//public:
//	Ammo(int ammoXPos, int ammoYPos, const char* ammoGraph, int ammpDamage)
//	{
//		// �e�̉摜�Z�b�g
//		m_ammoGraph = LoadGraph(ammoGraph);
//
//		// X.Y�̏�����
//		m_ammoXPos = ammoXPos;
//		m_ammoYPos = ammoYPos;
//
//		// �e�̃_���[�W�Z�b�g
//		m_ammoDamage = ammpDamage;
//
//		// �e�̑����������i�����l�͂T�j
//		m_ammoSpeed = 5;
//	}
//
//	// �e��`�悵�A�ړ�������
//	void Update()
//	{
//		DrawGraph(m_ammoXPos, m_ammoYPos, m_ammoGraph, TRUE);
//		// �e�͏�����ֈړ��i��ʏ㕔��0�Ȃ̂Ō��Z�j
//		m_ammoYPos -= m_ammoSpeed;
//	}
//
//	// ��ʊO�i������Ɂj�o�����𔻒�
//	bool IsOffScreen() const
//	{
//		return m_ammoYPos < 0;
//	}
//};
//
//class PlayerShip
//{
//private:
//	int m_shipPosX, m_shipPosY; // �v���C���[��X.Ypos
//	int m_shipGraph; // �v���C���[�̉摜
//	int m_movePower; // �v���C���[�̈ړ����x�i�����l�͂R�j���܂��ύX�ł��Ȃ����ł���悤�ɂ���
//	char m_keyState[keyNum];
//	vector<Ammo> m_ammoList; // �e���Ǘ��pvector
//
//public:
//	PlayerShip(int shipPosX, int shipPosY, const char* shipGraph)
//	{
//		// �O���t�B�b�N�̃��[�h
//		m_shipGraph = LoadGraph(shipGraph);
//
//		// �L�����N�^�[�̏����f�[�^���Z�b�g
//		m_shipPosX = shipPosX;
//		m_shipPosY = shipPosY;
//
//		// �ړ����x
//		m_movePower = 3;
//
//		// key�z��̒��g��S��NUll�ɂ���
//		for (int i = 0; i < keyNum; i++)
//		{
//			m_keyState[i] = NULL;
//		}
//
//	}
//
//	// �v���C���[��`�悷��
//	int DrawShip() const
//	{
//		return DrawGraph(m_shipPosX, m_shipPosY, m_shipGraph, TRUE);
//	}
//
//	// �L�[�̎擾
//	void KeyInput()
//	{
//		// �L�[���͎擾
//		GetHitKeyStateAll(m_keyState);
//
//		// D / ���������Ă�����E�ɐi��
//		if (m_keyState[KEY_INPUT_D] || m_keyState[KEY_INPUT_RIGHT]) m_shipPosX += m_movePower;
//
//		// A / ���������Ă����獶�ɐi��
//		if (m_keyState[KEY_INPUT_A] || m_keyState[KEY_INPUT_LEFT]) m_shipPosX -= m_movePower;
//	}
//
//	// �}�E�X�̎擾 
//	void MouseInput()
//	{
//		//���N���b�N�����Ă����炽�܂�����
//		if (GetMouseInput() & MOUSE_INPUT_LEFT)
//		{
//			m_ammoList.push_back(Ammo(m_shipPosX, m_shipPosY, "Ammo.png", 1)); //���[�ɒe��ǉ�
//		}
//	}
//
//	//�e������֔�΂��i���̍����ɂȂ���������j
//	void AmmoUpdate()
//	{
//		for (auto i = m_ammoList.begin(); i != m_ammoList.end();)
//		{
//			i->Update();
//			if (i->IsOffScreen())
//			{
//				i = m_ammoList.erase(i);
//			}
//			else
//			{
//				i++;
//			}
//		}
//	}
//};

int WinMain(HINSTANCE hIstance, HINSTANCE hPRrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE); // �t���X�N���[������E�B���h�E�\���ɕύX

	SetGraphMode(1280, 720, 32); // ��ʃT�C�Y�̃Z�b�g
	if (DxLib_Init() == -1)	// �c�w���C�u��������������
	{
		return -1;				// �G���[���N�����璼���ɏI��
	}

	//PlayerShipClass�̈����́i������:�v���C���[��X ������:�v���C���[��Y ��O����:�v���C���[�̉摜�j
	PlayerShip Play1(640, 550, "Player.bmp"); 
	// TimeManager�̐���
	TimeManager timeManager;

	// �`����ʂ𗠉�ʂɃZ�b�g
	SetDrawScreen(DX_SCREEN_BACK);

	// �O�t���[���̎��Ԃ��L�^
	timeManager.SetToPreviousTime();


	while(ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		timeManager.SetToDeltaTime();
		timeManager.SetToElapsedTime();

		ClearDrawScreen(); 

		Play1.KeyInput(timeManager.GetDt());

		Play1.MouseInput();

		Play1.DrawShip();

		Play1.AmmoUpdate(timeManager.GetDt());

		ScreenFlip();
	}

	DxLib_End(); // �v���W�F�N�g�̒�~
}
