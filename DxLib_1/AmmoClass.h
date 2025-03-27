#pragma once
#include "DxLib.h"

class Ammo
{
private:
	int m_ammoXPos, m_ammoYPos; // �e��X.YPos
	int m_ammoGraph; // �e�̉摜
	int m_ammoDamage; // �e�̃_���[�W�@�����̂Ƃ���ꔭ�œ|����
	int m_ammoSpeed; // �e�̑��x�@���ύX�ł���悤�ɂ���

public:
	Ammo(int ammoXPos, int ammoYPos, const char* ammoGraph, int ammpDamage);

	// �e��`�悵�A�ړ�������
	void Update(float dt);

	// ��ʊO�i������Ɂj�o�����𔻒�
	bool IsOffScreen() const;
};