#include "a.h"

extern int px, py; // �÷��̾� ��ġ
extern int current_score;//���� ����
extern int best_score;//�ְ� ����
extern int coin;//���� ����
extern int sx, sy; // ����� ��ġ
extern int check_x, check_y; // �񱳸� ���� ����
extern int check_c1, check_c2; // ���� �� ����

int main(void) {
	system("mode con cols=40 lines=30");
	cursor(); // �ܼ� Ŀ�� �����
	int Choice = 0; // ���� Choice
	LoginScreen();
	while (1) {
		PlaySound(TEXT("ami.wav"), NULL, SND_ASYNC | SND_LOOP); // ���������� ���ѹݺ����� �����Ų��.
		px = 10; py = 25; // �÷��̾� ���� �ʱ�ȭ
		sx = 10; sy = 24; // ��� ���� �ʱ�ȭ
		current_score = 0; // ���� ���� ���� �ʱ�ȭ
		Choice = main_screen(); // Choice�� main_screen();�� �� ����
		if (Choice == 0) { // Choice�� 0�̸� ���� ����
			GameLoop();
		}
		else if (Choice == 1) { // Choice�� 1�̸� Ʃ�丮��
			system("cls");
			Tutorial();
		}
		else if (Choice == 2) { // Choice�� 2�� ��ŷ����
			system("cls");
			Ranking();
		}
		else if (Choice == 3) { // Choice�� 4�̸� ���� ����
			system("cls");
			break;
		}

	}
	return 0;
}

