#include "a.h"

extern int coin;
int main_screen() {
	Interface();
	int x = 15; // 메뉴의 x 좌표
	int y = 23; // 메뉴의 y 좌표
	gotoxy(x - 2, y);
	printf("> 게임 시작\n");
	gotoxy(x, y + 1);
	printf("게임 방법\n");
	gotoxy(x, y + 2);
	printf("랭킹 보기\n");
	gotoxy(x, y + 3);
	printf("게임 종료\n");

	gotoxy(13, 28);
	printf("TOTAL COIN : %d", coin); // 코인의 개수를 출력

	while (1) {
		if (_kbhit()) {
			char Choice = _getch(); // Choice 변수에 키보드 입력 값을 받음 
			// 방향키 입력시 224 00이 들어오게 되기에 앞에 있는 값 224를 없앰
			if (Choice == -32) {    // -32로 입력되면
				Choice = _getch(); // 새로 입력값을 판별
				switch (Choice) {
				case UP: // 방향키 ↑ 입력
					if (y > 23) { // 25(메뉴의 가장 상단)보다 클 때
						gotoxy(x - 2, y); // > 지우기
						printf(" ");
						gotoxy(x - 2, --y); // 올라가서 > 재출력
						printf(">");
					}
					break;
				case DOWN: // 방향키 ↓ 입력
					if (y < 26) { // 27(메뉴의 가장 아래)보다 작을 때
						gotoxy(x - 2, y); // > 지우기
						printf(" ");
						gotoxy(x - 2, ++y); // 내려가서 > 재출력
						printf(">");
					}
					break;
				}
			}
			else if (Choice == ENTER) // 엔터 입력
				return y - 23; // 0, 1, 2, 3 값을 리턴
		}
	}
}

