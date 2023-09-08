#include "a.h"
int px = 10, py = 25; // player�� x��ǥ, player�� y��ǥ

//�÷��̾� ����ִ� �Լ�
void DrawPlayer() {
	gotoxy(px, py);

	printf("��");
}

//�̵��� �÷��̾� �����ִ� �Լ�
void ErasePlayer() {
	gotoxy(px, py);
	printf("  ");
}

//�÷��̾ �����̴� �Լ�
void MovePlayer() {
	int ch = _getch(); // ����Ű�� �޴´�.
	if (0 == ch || 224 == ch)//����Ű�� ������ �ѹ��� �ΰ��� ���� ������ ������ �� ������ �ɾ����� ������ ������ �ι� ���Եȴ�
		ch = _getch();//����Ű�� �޴´�
	switch (ch)
	{
	case LEFT: //�÷��̾� �������� �̵�
		if (px >= 1 && px <= 29 && py >= 1 && py <= 25) {
			ErasePlayer(px, py); // �̵��� �÷��̾� �����
			px -= 2; // x ����(��������)
			py--; // y ����
		}
		break;
	case RIGHT: //�÷��̾� ���������� �̵�
		if (px >= 1 && px <= 29 && py >= 1 && py <= 25) {
			ErasePlayer(px, py); // �̵��� �÷��̾� �����
			px += 2; // x ����(����������)
			py--; // y ����
		}
		break;
	case UP: //�÷��̾� ���� �̵�
		if (px >= 1 && px <= 28 && py >= 2 && py <= 25) {
			ErasePlayer(px, py); // �̵��� �÷��̾� �����
			py -= 2; // y ����
		}
		break;
	default:
		DrawPlayer(); // �÷��̾� �׸���
		break;//�ƹ�Ű�� �Էµ��� �ʾ��� ��
	}
	DrawPlayer(); // �÷��̾� �׸���
}