#include "a.h"

extern int check_x, check_y;
int cx, cy, check_c1 = 0, check_c2 = 0; // 동전 관련 변수들

//동전 출력하는 함수
int CoinScore() {
	int num; // 랜덤 변수  
	cx = check_x; //동전 갯수를 세기 위해서 계속 변하는 값인 cx와 cy의 값 대신 조건을 비교 할 변수를 선언함
	cy = check_y - 1; //동전 갯수를 세기 위해서 계속 변하는 값인 cx와 cy의 값 대신 조건을 비교 할 변수를 선언함
	num = rand() % 1000; // 랜덤 값 입력
	if (num % 3 == 0) { // 3의 배수일 경우
		gotoxy(cx, cy);
		printf("○"); // 위치에 동전 출력
		check_c2 = check_c1;  // 이전의 동전 갯수
		check_c1++;//만약 동전이 출력되면 동전갯수도 올려주어야함
	}
	else {
		check_c2 = check_c1; // 이전의 동전 갯수
		check_c1--;//이 값을 줄여주지 않으면 계속 동전 점수가 늘어나기 때문에 줄여줌
	}
	return 0;
}
