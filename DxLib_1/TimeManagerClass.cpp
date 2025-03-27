#include "TimeManagerClass.h"

using namespace std;

TimeManager::TimeManager()
{
	previousTime = high_resolution_clock::now();
	currentTime = high_resolution_clock::now();

	deltaTime = currentTime - previousTime;
	elapsedTime += deltaTime;

	dt = NULL;
	et = NULL;
}

// previousTimeをwinmainでセットできるようにする
void TimeManager::SetToPreviousTime()
{
	previousTime = high_resolution_clock::now();
}

// deltaTimeの更新（一フレームに一回）
void TimeManager::SetToDeltaTime()
{
	steady_clock::time_point currentTime = high_resolution_clock::now();
	duration<float> deltaTime = currentTime - previousTime;
	previousTime = currentTime;
	dt = deltaTime.count(); // 経過時間（秒）
}

// elapsedTimeの更新（一フレームに一回）
void TimeManager::SetToElapsedTime()
{
	elapsedTime += deltaTime;
	et = elapsedTime.count(); // 経過時間（秒）
}

float TimeManager::GetDt() const
{
	return dt;
}

float TimeManager::GetEt() const
{
	return et;
}