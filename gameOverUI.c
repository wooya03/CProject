#include "a.h"
extern current_score; // 현재 점수
extern best_score; // 최고 점수

void gameOverUI(void){
	system("cls");
	if (current_score > best_score) { // 현재 점수가 최고기록보다 크면 최고 기록 갱신
		best_score = current_score;
	}
	gotoxy(12, 1);
	printf(" ##  #  # # ### \n");
	gotoxy(12, 2);
	printf("#   # # ### #  \n");
	gotoxy(12, 3);
	printf("# # ### ### ##  \n");
	gotoxy(12, 4);
	printf("# # # # # # # \n");
	gotoxy(12, 5);
	printf(" ## # # # # ### \n");
	gotoxy(12, 7);
	printf(" #  # # ### ##  \n");
	gotoxy(12, 8);
	printf("# # # # #   # # \n");
	gotoxy(12, 9);
	printf("# # # # ##  ##  \n");
	gotoxy(12, 10);
	printf("# # # # #   # # \n");
	gotoxy(12, 11);
	printf(" #   #  ### # # \n");
	gotoxy(15, 15);
	printf("SCORE : %d", current_score);//현재점수 출력
	gotoxy(13, 17);
	printf("BEST SCORE : %d\n", best_score);//최고 점수 출력
	if (current_score >= best_score) {
		gotoxy(11, 19);
		printf("RECORD BREAKING!!!\n\n");
	}//점수 갱신되었을때 출력하는 안내 메세지
}
