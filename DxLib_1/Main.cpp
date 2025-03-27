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
//	int m_ammoXPos, m_ammoYPos; // 弾のX.YPos
//	int m_ammoGraph; // 弾の画像
//	int m_ammoDamage; // 弾のダメージ　※今のところ一発で倒せる
//	int m_ammoSpeed; // 弾の速度　※変更できるようにする
//
//public:
//	Ammo(int ammoXPos, int ammoYPos, const char* ammoGraph, int ammpDamage)
//	{
//		// 弾の画像セット
//		m_ammoGraph = LoadGraph(ammoGraph);
//
//		// X.Yの初期化
//		m_ammoXPos = ammoXPos;
//		m_ammoYPos = ammoYPos;
//
//		// 弾のダメージセット
//		m_ammoDamage = ammpDamage;
//
//		// 弾の速さ初期化（初期値は５）
//		m_ammoSpeed = 5;
//	}
//
//	// 弾を描画し、移動させる
//	void Update()
//	{
//		DrawGraph(m_ammoXPos, m_ammoYPos, m_ammoGraph, TRUE);
//		// 弾は上方向へ移動（画面上部が0なので減算）
//		m_ammoYPos -= m_ammoSpeed;
//	}
//
//	// 画面外（上方向に）出たかを判定
//	bool IsOffScreen() const
//	{
//		return m_ammoYPos < 0;
//	}
//};
//
//class PlayerShip
//{
//private:
//	int m_shipPosX, m_shipPosY; // プレイヤーのX.Ypos
//	int m_shipGraph; // プレイヤーの画像
//	int m_movePower; // プレイヤーの移動速度（初期値は３）※まだ変更できないができるようにする
//	char m_keyState[keyNum];
//	vector<Ammo> m_ammoList; // 弾を管理用vector
//
//public:
//	PlayerShip(int shipPosX, int shipPosY, const char* shipGraph)
//	{
//		// グラフィックのロード
//		m_shipGraph = LoadGraph(shipGraph);
//
//		// キャラクターの初期データをセット
//		m_shipPosX = shipPosX;
//		m_shipPosY = shipPosY;
//
//		// 移動速度
//		m_movePower = 3;
//
//		// key配列の中身を全部NUllにする
//		for (int i = 0; i < keyNum; i++)
//		{
//			m_keyState[i] = NULL;
//		}
//
//	}
//
//	// プレイヤーを描画する
//	int DrawShip() const
//	{
//		return DrawGraph(m_shipPosX, m_shipPosY, m_shipGraph, TRUE);
//	}
//
//	// キーの取得
//	void KeyInput()
//	{
//		// キー入力取得
//		GetHitKeyStateAll(m_keyState);
//
//		// D / →を押していたら右に進む
//		if (m_keyState[KEY_INPUT_D] || m_keyState[KEY_INPUT_RIGHT]) m_shipPosX += m_movePower;
//
//		// A / ←を押していたら左に進む
//		if (m_keyState[KEY_INPUT_A] || m_keyState[KEY_INPUT_LEFT]) m_shipPosX -= m_movePower;
//	}
//
//	// マウスの取得 
//	void MouseInput()
//	{
//		//左クリックをしていたらたまを撃つ
//		if (GetMouseInput() & MOUSE_INPUT_LEFT)
//		{
//			m_ammoList.push_back(Ammo(m_shipPosX, m_shipPosY, "Ammo.png", 1)); //末端に弾を追加
//		}
//	}
//
//	//弾を上方へ飛ばす（一定の高さになったら消す）
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
	ChangeWindowMode(TRUE); // フルスクリーンからウィンドウ表示に変更

	SetGraphMode(1280, 720, 32); // 画面サイズのセット
	if (DxLib_Init() == -1)	// ＤＸライブラリ初期化処理
	{
		return -1;				// エラーが起きたら直ちに終了
	}

	//PlayerShipClassの引数は（第一引数:プレイヤーのX 第二引数:プレイヤーのY 第三引数:プレイヤーの画像）
	PlayerShip Play1(640, 550, "Player.bmp"); 
	// TimeManagerの生成
	TimeManager timeManager;

	// 描画先画面を裏画面にセット
	SetDrawScreen(DX_SCREEN_BACK);

	// 前フレームの時間を記録
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

	DxLib_End(); // プロジェクトの停止
}
