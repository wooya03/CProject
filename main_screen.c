#include "a.h"

extern int coin;
int main_screen() {
	Interface();
	int x = 15; // �޴��� x ��ǥ
	int y = 23; // �޴��� y ��ǥ
	gotoxy(x - 2, y);
	printf("> ���� ����\n");
	gotoxy(x, y + 1);
	printf("���� ���\n");
	gotoxy(x, y + 2);
	printf("��ŷ ����\n");
	gotoxy(x, y + 3);
	printf("���� ����\n");

	gotoxy(13, 28);
	printf("TOTAL COIN : %d", coin); // ������ ������ ���

	while (1) {
		if (_kbhit()) {
			char Choice = _getch(); // Choice ������ Ű���� �Է� ���� ���� 
			// ����Ű �Է½� 224 00�� ������ �Ǳ⿡ �տ� �ִ� �� 224�� ����
			if (Choice == -32) {    // -32�� �ԷµǸ�
				Choice = _getch(); // ���� �Է°��� �Ǻ�
				switch (Choice) {
				case UP: // ����Ű �� �Է�
					if (y > 23) { // 25(�޴��� ���� ���)���� Ŭ ��
						gotoxy(x - 2, y); // > �����
						printf(" ");
						gotoxy(x - 2, --y); // �ö󰡼� > �����
						printf(">");
					}
					break;
				case DOWN: // ����Ű �� �Է�
					if (y < 26) { // 27(�޴��� ���� �Ʒ�)���� ���� ��
						gotoxy(x - 2, y); // > �����
						printf(" ");
						gotoxy(x - 2, ++y); // �������� > �����
						printf(">");
					}
					break;
				}
			}
			else if (Choice == ENTER) // ���� �Է�
				return y - 23; // 0, 1, 2, 3 ���� ����
		}
	}
}

