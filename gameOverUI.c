#include "a.h"
extern current_score; // ���� ����
extern best_score; // �ְ� ����

void gameOverUI(void){
	system("cls");
	if (current_score > best_score) { // ���� ������ �ְ��Ϻ��� ũ�� �ְ� ��� ����
		best_score = current_score;
	}
	gotoxy(12, 1);
	printf(" ##  #  # # ### \n");
	gotoxy(12, 2);
	printf("#   # # ### #  \n");
	gotoxy(12, 3);
	printf("# # ### ### ##  \n");
	gotoxy(12, 4);
	printf("# # # # # # # \n");
	gotoxy(12, 5);
	printf(" ## # # # # ### \n");
	gotoxy(12, 7);
	printf(" #  # # ### ##  \n");
	gotoxy(12, 8);
	printf("# # # # #   # # \n");
	gotoxy(12, 9);
	printf("# # # # ##  ##  \n");
	gotoxy(12, 10);
	printf("# # # # #   # # \n");
	gotoxy(12, 11);
	printf(" #   #  ### # # \n");
	gotoxy(15, 15);
	printf("SCORE : %d", current_score);//�������� ���
	gotoxy(13, 17);
	printf("BEST SCORE : %d\n", best_score);//�ְ� ���� ���
	if (current_score >= best_score) {
		gotoxy(11, 19);
		printf("RECORD BREAKING!!!\n\n");
	}//���� ���ŵǾ����� ����ϴ� �ȳ� �޼���
}