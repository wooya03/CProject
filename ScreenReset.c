#include "a.h"

extern int sx, sy;
extern int px, py;
int count = 0; // ȭ���� �Ѿ�� �� �� �� �ʱ�ȭ �Ǿ�����

//ȭ�� �Ѿ�� �� �ʱ�ȭ ��Ű�� �Լ�
int ScreenReset() {
	if (sy == 1 || sy == 2) { // �ʱ�ȭ
		for (int i = 1; i <= 30; i++) {
			for (int j = 1; j <= 37; j++) {
				gotoxy(j, i);
				printf(" ");
			}
		}
		gotoxy(px, 25);
		printf("��");
		py = 25; // �÷��̾� ���� �ʱ�ȭ
		if (px == sx)
			sy = 24; // ��� ���� �ʱ�ȭ
		else
			sy = 25;
		count++; // �Ѿ Ƚ�� ����
	}
	return 0;
}