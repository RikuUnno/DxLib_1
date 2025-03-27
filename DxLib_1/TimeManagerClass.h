#pragma once
#include <chrono>

using namespace std::chrono;

class TimeManager
{
private:
	steady_clock::time_point previousTime, currentTime; // ���L��deltaTime��elapsedTime�������߂邽�߂Ɏg���ϐ�
	duration<float> deltaTime; // 1�t���[�����Ƃ̌o�ߎ���(�ړ��E�e�̑��x���Ɏg��)
	duration<float> elapsedTime; // �v���J�n���Ă���̌o�ߎ��Ԃ�����(timer���Ɏg��)
	float dt, et; // ��L���float�^�ɂ��ēn���ׂ̕ϐ�(�����͏�L�Ƃ������傩)

public:
	TimeManager();

	// previousTime��winmain�ŃZ�b�g�ł���悤�ɂ���
	void SetToPreviousTime();

	// deltaTime�̍X�V
	void SetToDeltaTime();

	// elapsedTime�̍X�V�i��t���[���Ɉ��j
	void SetToElapsedTime();

	// dt�Q�b�^�[
	float GetDt() const;

	// et�̃Q�b�^�[
	float GetEt() const;
};