#include "a.h"

void Ranking() { // ��ŷ�� ����ϴ� �Լ�
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
	printf("    ��ŷ     �г���    ����     ����\n");
	printf("=======================================\n");
	b = DBsys(3); // DBsys(3) - ��ŷ ����, b : ��ŷ ��� �� ������ y��ǥ
	gotoxy(0, b);
	printf("=======================================\n");
	system("pause");
}

