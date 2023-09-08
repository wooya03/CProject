#include "a.h"

extern int count; // 초기화횟수
extern int px; // player의 x좌표
extern int check_x; // 계단위치 비교를 위한 변수

//게임 오버 함수
int GameOver(int gap) {

	if (count == 0 && gap >= 700) { // count(초기화횟수)가 0이고 입력되지 않은 시간이 700ms 이상일 경우
		gameOverUI();
		DBsys(2); // 스코어 업데이트
		DBsys(4);  // 코인 업데이트
		PlaySound(TEXT("end.wav"), NULL, SND_ASYNC); // 게임종료 노래
		return 1;
	}
	else if (count == 1 && gap >= 600) { // count(초기화횟수)가 1이고 입력되지 않은 시간이 600ms 이상일 경우
		gameOverUI();
		DBsys(2); // 스코어 업데이트
		DBsys(4);  // 코인 업데이트
		PlaySound(TEXT("end.wav"), NULL, SND_ASYNC); // 게임종료 노래
		return 1;
	}
	else if (count == 2 && gap >= 500) { // count(초기화횟수)가 2이상이고 입력되지 않은 시간이 500ms 이상일 경우
		gameOverUI();
		DBsys(2); // 스코어 업데이트
		DBsys(4);  // 코인 업데이트
		PlaySound(TEXT("end.wav"), NULL, SND_ASYNC); // 게임종료 노래
		return 1;
	}

	if (px != check_x) { //게임 종료하는 조건 (플레이어의 x 위치와 계단의 x 위치가 다를 경우
		gameOverUI();
		DBsys(2); // 스코어 업데이트
		DBsys(4);  // 코인 업데이트
		PlaySound(TEXT("end.wav"), NULL, SND_ASYNC); // 게임종료 노래
		return 1;
	}
	return 0;
}
