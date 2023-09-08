#include "a.h"
//플레이어를 움직이는 함수
void MovePlayer() {
	int ch = _getch(); // 방향키를 받는다.
	if (0 == ch || 224 == ch)//방향키를 누르면 한번에 두개의 값이 들어오기 때문에 이 조건을 걸어주지 않으면 루프가 두번 돌게된다
		ch = _getch();//방향키를 받는다
	switch (ch)
	{
	case LEFT: //플레이어 왼쪽으로 이동
		if (px >= 3 && px <= 28 && py >= 1 && py <= 25) {
			ErasePlayer(px, py); // 이동한 플레이어 지우기
			px -= 2; // x 감소(왼쪽으로)
			py--; // y 감소
		}
		break;
	case RIGHT: //플레이어 오른쪽으로 이동
		if (px >= 1 && px <= 26 && py >= 1 && py <= 25) {
			ErasePlayer(px, py); // 이동한 플레이어 지우기
			px += 2; // x 증가(오른쪽으로)
			py--; // y 감소
		}
		break;
	case UP: //플레이어 위로 이동
		if (px >= 1 && px <= 28 && py >= 2 && py <= 25) {
			ErasePlayer(px, py); // 이동한 플레이어 지우기
			py -= 2; // y 감소
		}
		break;
	default:
		DrawPlayer(px, py); // 플레이어 그리기
		break;//아무키도 입력되지 않았을 때
	}
	DrawPlayer(px, py); // 플레이어 그리기
}