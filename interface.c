#include "a.h"

void Interface() { // �������̽��� �Լ��� ����� �ʿ��� ���� �ҷ���
	system("cls");
	int a = 8; // X��ǥ
	int b = 12; // Y��ǥ
	gotoxy(a + 2, b + 9); printf("        ���"); Sleep(50);
	gotoxy(a + 2, b + 8); printf("        ���"); Sleep(50);
	gotoxy(a + 2, b + 7); printf("        ���"); Sleep(50);
	gotoxy(a + 2, b + 6); printf("        ���"); Sleep(50);
	gotoxy(a + 2, b + 5); printf("        ���"); Sleep(50);
	gotoxy(a + 2, b + 4); printf("��      ���      ��"); Sleep(50);
	gotoxy(a + 2, b + 3); printf(" ���   ���   ���"); Sleep(50);
	gotoxy(a + 2, b + 2); printf("   ��������"); Sleep(50);
	gotoxy(a + 2, b + 1); printf("     ������"); Sleep(50);
	gotoxy(a + 2, b); printf("       ����"); Sleep(50);
	gotoxy(a + 2, b - 1); printf("         ��"); Sleep(50);
	b = 2;
	gotoxy(a, b + 6);
	printf("========================\n"); Sleep(50);
	gotoxy(a, b + 5);
	printf("     �� �� �� �� ��\n");
	gotoxy(a, b + 4);
	printf("========================\n"); Sleep(50);
	gotoxy(a, b + 3);
	printf("     I N F I N I T E\n");
	gotoxy(a, b + 2);
	printf("========================\n"); Sleep(50);
	gotoxy(a, b + 1);
	printf("   ��  ��  ��  ��  ��\n"); Sleep(50);
	gotoxy(a, b);
	printf("========================\n"); Sleep(50);
}