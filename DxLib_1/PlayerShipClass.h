#pragma once
#include "DxLib.h"
#include "AmmoClass.h"
#include <vector>

using namespace std;

const int keyNum = 256;

class PlayerShip
{
private:
	int m_shipPosX, m_shipPosY; // プレイヤーのX.Ypos
	int m_shipGraph; // プレイヤーの画像
	int m_movePower; // プレイヤーの移動速度（初期値は３）※まだ変更できないができるようにする
	char m_keyState[keyNum];
	vector<Ammo> m_ammoList; // 弾を管理用vector

public:
	PlayerShip(int shipPosX, int shipPosY, const char* shipGraph);

	// プレイヤーを描画する
	int DrawShip() const;

	// キーの取得
	void KeyInput(float dt);

	// マウスの取得 
	void MouseInput();

	//弾を上方へ飛ばす（一定の高さになったら消す）
	void AmmoUpdate(float dt);
};
