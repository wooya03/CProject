#include "a.h"

void Tutorial() {
	system("cls");

	int a = 8;
	int b = 2;
	gotoxy(a, b);
	printf("========================\n");
	gotoxy(a, b + 1);
	printf("   ▲  ▲  ▲  ▲  ▲\n");
	gotoxy(a, b + 2);
	printf("========================\n");
	gotoxy(a, b + 3);
	printf("     I N F I N I T E\n");
	gotoxy(a, b + 4);
	printf("========================\n");
	gotoxy(a, b + 5);
	printf("     무 한 의 계 단\n");
	gotoxy(a, b + 6);
	printf("========================\n");

	gotoxy(a + 6, 11);
	printf("[ 방향키 ]\n"); Sleep(50);
	gotoxy(a+4, 13); 
	printf("오른쪽 : → key"); Sleep(50);
	gotoxy(a + 5, 15);
	printf("왼쪽 : ← key\n"); Sleep(50);
	gotoxy(a + 5, 17);
	printf("위쪽 : ↑ key\n"); Sleep(50);
	 
	gotoxy(a + 4, 19);
	printf("[ 게임 설명 ]"); Sleep(50);
	gotoxy(3, 21);
	printf("방향키로 계단을 오르는 게임입니다."); Sleep(50);
	gotoxy(0, 22);
	printf("입력 시간 초과나 계단에서 떨어지면 탈락!"); Sleep(50);
	gotoxy(9, 23);
	printf("최고기록에 도전하세요!\n\n"); Sleep(50);
	system("pause");
}

