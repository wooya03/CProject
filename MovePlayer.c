#include "a.h"
//�÷��̾ �����̴� �Լ�
void MovePlayer() {
	int ch = _getch(); // ����Ű�� �޴´�.
	if (0 == ch || 224 == ch)//����Ű�� ������ �ѹ��� �ΰ��� ���� ������ ������ �� ������ �ɾ����� ������ ������ �ι� ���Եȴ�
		ch = _getch();//����Ű�� �޴´�
	switch (ch)
	{
	case LEFT: //�÷��̾� �������� �̵�
		if (px >= 3 && px <= 28 && py >= 1 && py <= 25) {
			ErasePlayer(px, py); // �̵��� �÷��̾� �����
			px -= 2; // x ����(��������)
			py--; // y ����
		}
		break;
	case RIGHT: //�÷��̾� ���������� �̵�
		if (px >= 1 && px <= 26 && py >= 1 && py <= 25) {
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
		DrawPlayer(px, py); // �÷��̾� �׸���
		break;//�ƹ�Ű�� �Էµ��� �ʾ��� ��
	}
	DrawPlayer(px, py); // �÷��̾� �׸���
}