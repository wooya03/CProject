#include "a.h"
int sx = 10, sy = 24; // 계단의 위치
int check_x, check_y; // 비교를 위한 변수

// 계단 생성하는 함수
int Stair() {
	int num = 0; // 랜덤 값 대입을 위한 변수
	check_x = sx; // 계단의 x 위치를 check_x에 대입
	check_y = sy; // 계단의 y 위치를 check_y에 대입
	gotoxy(sx, sy); // 계단 이동
	printf("〓");//계단 출력
	num = rand() % 3;//0,1, 2중 한개의 변수 받기
	if (num == 0 && sx >= 3) { //왼쪽으로 계단 이동
		sx -= 2;
		sy--;
	}
	else if (num == 1 && sx <= 28) { //오른쪽으로 계단 이동
		sx += 2;
		sy--;
	}
	else { //위쪽으로 계단 이동
		sy -= 2;
	}
	return 0;
}

