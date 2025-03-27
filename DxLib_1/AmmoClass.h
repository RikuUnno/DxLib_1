#pragma once
#include "DxLib.h"

class Ammo
{
private:
	int m_ammoXPos, m_ammoYPos; // 弾のX.YPos
	int m_ammoGraph; // 弾の画像
	int m_ammoDamage; // 弾のダメージ　※今のところ一発で倒せる
	int m_ammoSpeed; // 弾の速度　※変更できるようにする

public:
	Ammo(int ammoXPos, int ammoYPos, const char* ammoGraph, int ammpDamage);

	// 弾を描画し、移動させる
	void Update(float dt);

	// 画面外（上方向に）出たかを判定
	bool IsOffScreen() const;
};