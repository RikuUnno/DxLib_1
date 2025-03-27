#include "PlayerShipClass.h"

using namespace std;

PlayerShip::PlayerShip(int shipPosX, int shipPosY, const char* shipGraph)
{
	// グラフィックのロード
	m_shipGraph = LoadGraph(shipGraph);

	// キャラクターの初期データをセット
	m_shipPosX = shipPosX;
	m_shipPosY = shipPosY;

	// 移動速度(一秒間に300ピクセル)
	m_movePower = 300;

	// key配列の中身を全部NUllにする
	for (int i = 0; i < keyNum; i++)
	{
		m_keyState[i] = NULL;
	}

}

// プレイヤーを描画する
int PlayerShip::DrawShip() const
{
	return DrawGraph(m_shipPosX, m_shipPosY, m_shipGraph, TRUE);
}

// キーの取得
void PlayerShip::KeyInput(float dt)
{
	// キー入力取得
	GetHitKeyStateAll(m_keyState);

	// D / →を押していたら右に進む
	if (m_keyState[KEY_INPUT_D] || m_keyState[KEY_INPUT_RIGHT]) m_shipPosX += static_cast<int>(m_movePower * dt);

	// A / ←を押していたら左に進む
	if (m_keyState[KEY_INPUT_A] || m_keyState[KEY_INPUT_LEFT]) m_shipPosX -= static_cast<int>(m_movePower * dt);
}

// マウスの取得 
void PlayerShip::MouseInput()
{
	//左クリックをしていたらたまを撃つ
	if (GetMouseInput() & MOUSE_INPUT_LEFT)
	{
		m_ammoList.push_back(Ammo(m_shipPosX, m_shipPosY, "Ammo.png", 1)); //末端に弾を追加
	}
}

//弾を上方へ飛ばす（一定の高さになったら消す）
void PlayerShip::AmmoUpdate(float dt)
{
	// ループ文でリストの中身を更新＆消す消さないの判定
	for (vector<Ammo>::iterator i = m_ammoList.begin(); i != m_ammoList.end();)
	{
		i->Update(dt); 
		if (i->IsOffScreen())
		{
			i = m_ammoList.erase(i); // IsOffScreenで弾の位置を判定して画面外に出たらリストから削除する
		}
		else
		{
			i++;
		}
	}
}
