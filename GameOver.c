#include "a.h"

extern int count; // �ʱ�ȭȽ��
extern int px; // player�� x��ǥ
extern int check_x; // �����ġ �񱳸� ���� ����

//���� ���� �Լ�
int GameOver(int gap) {

	if (count == 0 && gap >= 700) { // count(�ʱ�ȭȽ��)�� 0�̰� �Էµ��� ���� �ð��� 700ms �̻��� ���
		gameOverUI();
		DBsys(2); // ���ھ� ������Ʈ
		DBsys(4);  // ���� ������Ʈ
		PlaySound(TEXT("end.wav"), NULL, SND_ASYNC); // �������� �뷡
		return 1;
	}
	else if (count == 1 && gap >= 600) { // count(�ʱ�ȭȽ��)�� 1�̰� �Էµ��� ���� �ð��� 600ms �̻��� ���
		gameOverUI();
		DBsys(2); // ���ھ� ������Ʈ
		DBsys(4);  // ���� ������Ʈ
		PlaySound(TEXT("end.wav"), NULL, SND_ASYNC); // �������� �뷡
		return 1;
	}
	else if (count == 2 && gap >= 500) { // count(�ʱ�ȭȽ��)�� 2�̻��̰� �Էµ��� ���� �ð��� 500ms �̻��� ���
		gameOverUI();
		DBsys(2); // ���ھ� ������Ʈ
		DBsys(4);  // ���� ������Ʈ
		PlaySound(TEXT("end.wav"), NULL, SND_ASYNC); // �������� �뷡
		return 1;
	}

	if (px != check_x) { //���� �����ϴ� ���� (�÷��̾��� x ��ġ�� ����� x ��ġ�� �ٸ� ���
		gameOverUI();
		DBsys(2); // ���ھ� ������Ʈ
		DBsys(4);  // ���� ������Ʈ
		PlaySound(TEXT("end.wav"), NULL, SND_ASYNC); // �������� �뷡
		return 1;
	}
	return 0;
}
