#include "a.h"

extern int py; // player�� y��ǥ
extern int current_score; //���� ����
extern int check_c1, check_c2; // ���� ���� ������
extern coin; // ���� ����
int GameLoop() {

	int start_time = 0, end_time, gap = 0;//Ÿ�̸� ����� �������� �ʿ��� ����
	system("cls");
	Score(); //���� ȭ�� �����
	DrawPlayer(); //���� �÷��̾� ���
	// ���� ���
	gotoxy(10, 26);
	printf("��");
	//���� �÷��� ȭ��
	while (1) {
		int temp = py; // py�� temp ������ ����
		Stair();//��� ���� ���
		start_time = clock(); // ���� �ð�
		CoinScore();//���� ����ϱ�
		MovePlayer();//�÷��̾� �����̱�
		end_time = clock();  // ���� �ð�
		// ���� �ð����� Ű �Է����� ������ ��������
		gap = (int)(end_time - start_time); // ����ð� - ���۽ð�
		if (GameOver(gap)) {
			system("pause");
			break;
		}

		if (py < temp) { //���� ���� �÷��ֱ�
			current_score++;
		}

		ScreenReset();//ȭ�� �ʱ�ȭ
		if (check_c1 > check_c2) { //���� ���� �ø���
			coin++;
		}
		Score(); // ���� ���


	}
	return;
}