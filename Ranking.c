#include "a.h"

void Ranking() { // 랭킹을 출력하는 함수
	int a = 6, b = 0;
	gotoxy(a, 5);
	printf("##   #  ### # # ### ###  ## \n");
	gotoxy(a, 6);
	printf("# # # # # # # #  #  # # #  \n");
	gotoxy(a, 7);
	printf("##  ### # # ##   #  # # # #\n");
	gotoxy(a, 8);
	printf("# # # # # # # #  #  # # # # \n");
	gotoxy(a, 9);
	printf("# # # # # # # # ### # #  ## \n");
	gotoxy(0, 10);
	printf("=======================================\n");
	printf("    랭킹     닉네임    순위     코인\n");
	printf("=======================================\n");
	b = DBsys(3); // DBsys(3) - 랭킹 보기, b : 랭킹 출력 후 마지막 y좌표
	gotoxy(0, b);
	printf("=======================================\n");
	system("pause");
}

