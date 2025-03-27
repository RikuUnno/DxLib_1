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

// previousTime��winmain�ŃZ�b�g�ł���悤�ɂ���
void TimeManager::SetToPreviousTime()
{
	previousTime = high_resolution_clock::now();
}

// deltaTime�̍X�V�i��t���[���Ɉ��j
void TimeManager::SetToDeltaTime()
{
	steady_clock::time_point currentTime = high_resolution_clock::now();
	duration<float> deltaTime = currentTime - previousTime;
	previousTime = currentTime;
	dt = deltaTime.count(); // �o�ߎ��ԁi�b�j
}

// elapsedTime�̍X�V�i��t���[���Ɉ��j
void TimeManager::SetToElapsedTime()
{
	elapsedTime += deltaTime;
	et = elapsedTime.count(); // �o�ߎ��ԁi�b�j
}

float TimeManager::GetDt() const
{
	return dt;
}

float TimeManager::GetEt() const
{
	return et;
}