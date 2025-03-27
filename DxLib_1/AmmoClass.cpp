#include  "AmmoClass.h"

Ammo::Ammo(int ammoXPos, int ammoYPos, const char* ammoGraph, int ammpDamage)
{
	// �e�̉摜�Z�b�g
	m_ammoGraph = LoadGraph(ammoGraph);

	// X.Y�̏�����
	m_ammoXPos = ammoXPos;
	m_ammoYPos = ammoYPos;

	// �e�̃_���[�W�Z�b�g
	m_ammoDamage = ammpDamage;

	// �e�̑����i��b�Ԃ�200�s�N�Z���j
	m_ammoSpeed = 200;
}

// �e��`�悵�A�ړ�������
void Ammo::Update(float dt)
{
	DrawGraph(m_ammoXPos, m_ammoYPos, m_ammoGraph, TRUE); // �e�̕`��
	// �e�͏�����ֈړ��i��ʏ㕔��0�Ȃ̂Ō��Z�j
	m_ammoYPos -= static_cast<int>(m_ammoSpeed * dt); // 
}

// ��ʊO�i������Ɂj�o�����𔻒�
bool Ammo::IsOffScreen() const
{
	return m_ammoYPos < 0;
}