#include "a.h"

int current_score = 0;//���� ����
extern best_score; //�ְ� ����
extern int coin;

// ������ ����ϴ� �Լ�
int Score() {
	gotoxy(1, 0);
	printf("SCORE : %d", current_score); // ���� ����
	gotoxy(13, 0);
	printf("BEST SCORE : %d", best_score); // �ְ� ����
	gotoxy(29, 0);
	printf("COIN : %d", coin); // ȹ�� ����
	return 0;
}