#include "a.h"

extern int px, py; // 플레이어 위치
extern int current_score;//현재 점수
extern int best_score;//최고 점수
extern int coin;//동전 갯수
extern int sx, sy; // 계단의 위치
extern int check_x, check_y; // 비교를 위한 변수
extern int check_c1, check_c2; // 동전 비교 변수

int main(void) {
	system("mode con cols=40 lines=30");
	cursor(); // 콘솔 커서 숨기기
	int Choice = 0; // 유저 Choice
	LoginScreen();
	while (1) {
		PlaySound(TEXT("ami.wav"), NULL, SND_ASYNC | SND_LOOP); // 시작음악을 무한반복으로 재생시킨다.
		px = 10; py = 25; // 플레이어 변수 초기화
		sx = 10; sy = 24; // 계단 변수 초기화
		current_score = 0; // 현재 점수 변수 초기화
		Choice = main_screen(); // Choice에 main_screen();의 값 대입
		if (Choice == 0) { // Choice가 0이면 게임 시작
			GameLoop();
		}
		else if (Choice == 1) { // Choice가 1이면 튜토리얼
			system("cls");
			Tutorial();
		}
		else if (Choice == 2) { // Choice가 2면 랭킹보기
			system("cls");
			Ranking();
		}
		else if (Choice == 3) { // Choice가 4이면 게임 종료
			system("cls");
			break;
		}

	}
	return 0;
}

