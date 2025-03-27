#pragma once
#include <chrono>

using namespace std::chrono;

class TimeManager
{
private:
	steady_clock::time_point previousTime, currentTime; // 下記のdeltaTimeとelapsedTime等を求めるために使う変数
	duration<float> deltaTime; // 1フレームごとの経過時間(移動・弾の速度等に使う)
	duration<float> elapsedTime; // 計測開始してからの経過時間を入れる(timer等に使う)
	float dt, et; // 上記二つをfloat型にして渡す為の変数(役割は上記といっしょか)

public:
	TimeManager();

	// previousTimeをwinmainでセットできるようにする
	void SetToPreviousTime();

	// deltaTimeの更新
	void SetToDeltaTime();

	// elapsedTimeの更新（一フレームに一回）
	void SetToElapsedTime();

	// dtゲッター
	float GetDt() const;

	// etのゲッター
	float GetEt() const;
};