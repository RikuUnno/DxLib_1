#include "PlayerShipClass.h"

using namespace std;

PlayerShip::PlayerShip(int shipPosX, int shipPosY, const char* shipGraph)
{
	// �O���t�B�b�N�̃��[�h
	m_shipGraph = LoadGraph(shipGraph);

	// �L�����N�^�[�̏����f�[�^���Z�b�g
	m_shipPosX = shipPosX;
	m_shipPosY = shipPosY;

	// �ړ����x(��b�Ԃ�300�s�N�Z��)
	m_movePower = 300;

	// key�z��̒��g��S��NUll�ɂ���
	for (int i = 0; i < keyNum; i++)
	{
		m_keyState[i] = NULL;
	}

}

// �v���C���[��`�悷��
int PlayerShip::DrawShip() const
{
	return DrawGraph(m_shipPosX, m_shipPosY, m_shipGraph, TRUE);
}

// �L�[�̎擾
void PlayerShip::KeyInput(float dt)
{
	// �L�[���͎擾
	GetHitKeyStateAll(m_keyState);

	// D / ���������Ă�����E�ɐi��
	if (m_keyState[KEY_INPUT_D] || m_keyState[KEY_INPUT_RIGHT]) m_shipPosX += static_cast<int>(m_movePower * dt);

	// A / ���������Ă����獶�ɐi��
	if (m_keyState[KEY_INPUT_A] || m_keyState[KEY_INPUT_LEFT]) m_shipPosX -= static_cast<int>(m_movePower * dt);
}

// �}�E�X�̎擾 
void PlayerShip::MouseInput()
{
	//���N���b�N�����Ă����炽�܂�����
	if (GetMouseInput() & MOUSE_INPUT_LEFT)
	{
		m_ammoList.push_back(Ammo(m_shipPosX, m_shipPosY, "Ammo.png", 1)); //���[�ɒe��ǉ�
	}
}

//�e������֔�΂��i���̍����ɂȂ���������j
void PlayerShip::AmmoUpdate(float dt)
{
	// ���[�v���Ń��X�g�̒��g���X�V�����������Ȃ��̔���
	for (vector<Ammo>::iterator i = m_ammoList.begin(); i != m_ammoList.end();)
	{
		i->Update(dt); 
		if (i->IsOffScreen())
		{
			i = m_ammoList.erase(i); // IsOffScreen�Œe�̈ʒu�𔻒肵�ĉ�ʊO�ɏo���烊�X�g����폜����
		}
		else
		{
			i++;
		}
	}
}
