#include "a.h"

int GameChoice(void) {
	system("cls");
	int a = 8;
	int b = 2;
	gotoxy(a, b);
	printf("========================\n");
	gotoxy(a, b + 1);
	printf("   ��  ��  ��  ��  ��\n");
	gotoxy(a, b + 2);
	printf("========================\n");
	gotoxy(a, b + 3);
	printf("     I N F I N I T E\n");
	gotoxy(a, b + 4);
	printf("========================\n");
	gotoxy(a, b + 5);
	printf("     �� �� �� �� ��\n");
	gotoxy(a, b + 6);
	printf("========================\n");

	int x = 15;
	int y = 15;
	gotoxy(x - 2, y);
	printf("> �Ϲ� ����");
	gotoxy(x, y + 1);
	printf("��� ����");

	return;
}