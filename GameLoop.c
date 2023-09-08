#include "a.h"

extern int py; // player의 y좌표
extern int current_score; //현재 점수
extern int check_c1, check_c2; // 동전 관련 변수들
extern coin; // 동전 개수
int GameLoop() {

	int start_time = 0, end_time, gap = 0;//타이머 기능을 쓰기위해 필요한 변수
	system("cls");
	Score(); //게임 화면 만들기
	DrawPlayer(); //시작 플레이어 찍기
	// 시작 계단
	gotoxy(10, 26);
	printf("〓");
	//게임 플레이 화면
	while (1) {
		int temp = py; // py를 temp 변수에 저장
		Stair();//계단 먼저 찍기
		start_time = clock(); // 시작 시간
		CoinScore();//동전 출력하기
		MovePlayer();//플레이어 움직이기
		end_time = clock();  // 종료 시간
		// 일정 시간동안 키 입력하지 않으면 게임종료
		gap = (int)(end_time - start_time); // 종료시간 - 시작시간
		if (GameOver(gap)) {
			system("pause");
			break;
		}

		if (py < temp) { //현재 점수 올려주기
			current_score++;
		}

		ScreenReset();//화면 초기화
		if (check_c1 > check_c2) { //동전 갯수 올리기
			coin++;
		}
		Score(); // 점수 출력


	}
	return;
}