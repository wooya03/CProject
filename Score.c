#include "a.h"

int current_score = 0;//현재 점수
extern best_score; //최고 점수
extern int coin;

// 점수를 출력하는 함수
int Score() {
	gotoxy(1, 0);
	printf("SCORE : %d", current_score); // 현재 점수
	gotoxy(13, 0);
	printf("BEST SCORE : %d", best_score); // 최고 점수
	gotoxy(29, 0);
	printf("COIN : %d", coin); // 획득 코인
	return 0;
}