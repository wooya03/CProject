#include "a.h"

extern int sx, sy;
extern int px, py;
int count = 0; // 화면이 넘어갔을 때 몇 번 초기화 되었는지

//화면 넘어갔을 때 초기화 시키는 함수
int ScreenReset() {
	if (sy == 1 || sy == 2) { // 초기화
		for (int i = 1; i <= 30; i++) {
			for (int j = 1; j <= 37; j++) {
				gotoxy(j, i);
				printf(" ");
			}
		}
		gotoxy(px, 25);
		printf("♥");
		py = 25; // 플레이어 변수 초기화
		if (px == sx)
			sy = 24; // 계단 변수 초기화
		else
			sy = 25;
		count++; // 넘어간 횟수 증가
	}
	return 0;
}