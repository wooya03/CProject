#include "a.h"
int sx = 10, sy = 24; // ����� ��ġ
int check_x, check_y; // �񱳸� ���� ����

// ��� �����ϴ� �Լ�
int Stair() {
	int num = 0; // ���� �� ������ ���� ����
	check_x = sx; // ����� x ��ġ�� check_x�� ����
	check_y = sy; // ����� y ��ġ�� check_y�� ����
	gotoxy(sx, sy); // ��� �̵�
	printf("��");//��� ���
	num = rand() % 3;//0,1, 2�� �Ѱ��� ���� �ޱ�
	if (num == 0 && sx >= 3) { //�������� ��� �̵�
		sx -= 2;
		sy--;
	}
	else if (num == 1 && sx <= 28) { //���������� ��� �̵�
		sx += 2;
		sy--;
	}
	else { //�������� ��� �̵�
		sy -= 2;
	}
	return 0;
}

