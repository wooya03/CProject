#include "a.h"

void Tutorial() {
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

	gotoxy(a + 6, 11);
	printf("[ ����Ű ]\n"); Sleep(50);
	gotoxy(a+4, 13); 
	printf("������ : �� key"); Sleep(50);
	gotoxy(a + 5, 15);
	printf("���� : �� key\n"); Sleep(50);
	gotoxy(a + 5, 17);
	printf("���� : �� key\n"); Sleep(50);
	 
	gotoxy(a + 4, 19);
	printf("[ ���� ���� ]"); Sleep(50);
	gotoxy(3, 21);
	printf("����Ű�� ����� ������ �����Դϴ�."); Sleep(50);
	gotoxy(0, 22);
	printf("�Է� �ð� �ʰ��� ��ܿ��� �������� Ż��!"); Sleep(50);
	gotoxy(9, 23);
	printf("�ְ��Ͽ� �����ϼ���!\n\n"); Sleep(50);
	system("pause");
}

