#include  "AmmoClass.h"

Ammo::Ammo(int ammoXPos, int ammoYPos, const char* ammoGraph, int ammpDamage)
{
	// 弾の画像セット
	m_ammoGraph = LoadGraph(ammoGraph);

	// X.Yの初期化
	m_ammoXPos = ammoXPos;
	m_ammoYPos = ammoYPos;

	// 弾のダメージセット
	m_ammoDamage = ammpDamage;

	// 弾の速さ（一秒間に200ピクセル）
	m_ammoSpeed = 200;
}

// 弾を描画し、移動させる
void Ammo::Update(float dt)
{
	DrawGraph(m_ammoXPos, m_ammoYPos, m_ammoGraph, TRUE); // 弾の描画
	// 弾は上方向へ移動（画面上部が0なので減算）
	m_ammoYPos -= static_cast<int>(m_ammoSpeed * dt); // 
}

// 画面外（上方向に）出たかを判定
bool Ammo::IsOffScreen() const
{
	return m_ammoYPos < 0;
}