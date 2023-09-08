#include "a.h"

int LoginScreen() {
	while (1) {
		Interface(); 
		int x = 15; // 메뉴의 x 좌표
		int y = 23; // 메뉴의 y 좌표

		gotoxy(x - 2, y);
		printf("> 로그인");
		gotoxy(x, y + 1);
		printf("회원가입");
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
						if (y < 24) { // 27(메뉴의 가장 아래)보다 작을 때
							gotoxy(x - 2, y); // > 지우기
							printf(" ");
							gotoxy(x - 2, ++y); // 내려가서 > 재출력
							printf(">");
						}
						break;
					}
				}
				else if (Choice == ENTER) // 엔터 입력
				{
					int a = y - 23; // 0 또는 1을 대입
					char result = 0; // DBsys 함수의 리턴값을 받기 위한 변수
					result = DBsys(a);  // DBsys 함수에 0 또는 1의 값을 보낸다
					if (result == 1) { // 1이 반환되면 리턴
						return;
					}
					if (result == 2) { // 2가 반환되면 break
						break;
					}
				}
			}
		}
	}
	
}

