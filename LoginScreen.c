#include "a.h"

int LoginScreen() {
	while (1) {
		Interface(); 
		int x = 15; // �޴��� x ��ǥ
		int y = 23; // �޴��� y ��ǥ

		gotoxy(x - 2, y);
		printf("> �α���");
		gotoxy(x, y + 1);
		printf("ȸ������");
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
						if (y < 24) { // 27(�޴��� ���� �Ʒ�)���� ���� ��
							gotoxy(x - 2, y); // > �����
							printf(" ");
							gotoxy(x - 2, ++y); // �������� > �����
							printf(">");
						}
						break;
					}
				}
				else if (Choice == ENTER) // ���� �Է�
				{
					int a = y - 23; // 0 �Ǵ� 1�� ����
					char result = 0; // DBsys �Լ��� ���ϰ��� �ޱ� ���� ����
					result = DBsys(a);  // DBsys �Լ��� 0 �Ǵ� 1�� ���� ������
					if (result == 1) { // 1�� ��ȯ�Ǹ� ����
						return;
					}
					if (result == 2) { // 2�� ��ȯ�Ǹ� break
						break;
					}
				}
			}
		}
	}
	
}

