#include "a.h"

int best_score;
int coin;

int DBsys(int a) {
	MYSQL mysql = { 0 };
	MYSQL* connection = NULL;
	MYSQL_RES* result = NULL;
	MYSQL_ROW* row = { 0 };
	MYSQL_ROW* row2 = { 0 };
	static char id[15] = { 0 };
	char passwd[15] = { 0 };
	char name[15] = { 0 }; // 
	char buffer[200] = { 0, };	// buffer1
	char buffer2[200] = { 0, }; // buffer 2

	// MySQL �ʱ�ȭ : mysql_init(����ü�� �ּ� => &mysql)
	mysql_init(&mysql);

	// MySQL ���� : mysql_real_connect(8�� ����ü�� �ּ�, ȣ��Ʈ �̸�,)
	connection = mysql_real_connect(&mysql, HOST, USER, PASS, NAME, PORT, NULL, 0);

	// MySQL ������ �����ϴ� �������� �߻��ϴ� ������ ó��
	if (connection == NULL) {
		fprintf(stderr, "���� : %s\n", mysql_error(&mysql));
	}

	if (a == 0) { // �α���
		system("cls");
		printf("=========�α���=========\n");
		printf("���̵� �Է� : ");
		gets(id); // ���̵� �Է�
		if (id[0] == 0) { // ���̵� ������ �Է��� ���
			printf("���̵� �Է����ּ���.\n");
			system("pause");
			return;
		}
		printf("�н����� �Է� : ");
		gets(passwd); // ��й�ȣ �Է�
		if (passwd[0] == 0) { // ��й�ȣ�� ������ �Է��� ���
			printf("�н����带 �Է����ּ���.\n");
			system("pause");
			return;
		}


		sprintf(buffer, "SELECT * FROM user WHERE id='%s' AND passwd='%s'", id, passwd); 
		// user ���̺��� where ���ǿ� �´� ��� Į���� ���
		mysql_query(connection, buffer); 
		// mysql�ܼ�â�� ���� ��ɾ �Է��ϴ� �Լ�
		result = mysql_store_result(connection); //mysql�� ���� ����� �����Ѵ�.

		while ((row = mysql_fetch_row(result)) != NULL) 
			// result���� �� ��(row)�� �����͸� �����ͼ� �ݺ������� ó��
		{
			if (strcmp(row[0], id) == 0 && strcmp(row[2], passwd) == 0)
			{
				printf("�α��εǾ����ϴ�.\n");
				coin = atoi(row[3]);
				buffer[0] = 0; // ���� �ʱ�ȭ
				sprintf(buffer, "SELECT score FROM ranking WHERE id='%s'", row[0]);
				mysql_query(connection, buffer); 
				// mysql�ܼ�â�� ���� ��ɾ �Է��ϴ� �Լ�
				mysql_free_result(result); 
				// result�� ���� �޸�(memory)�� �ִ� ������ ��� �����Ѵ�.
				result = mysql_store_result(connection); 
				//mysql�� ���� ����� �����Ѵ�.
				while ((row2 = mysql_fetch_row(result)) != NULL) 
				// result���� �� ��(row)�� �����͸� �����ͼ� �ݺ������� ó��
				{
					best_score = atoi(row2[0]);
				}
				system("pause");
				return 1;
			}
			else {
				printf("���̵� �Ǵ� ��й�ȣ�� ���� �ʽ��ϴ�.");
			}
		}
		if ((row = mysql_fetch_row(result)) == NULL) {
			printf("���̵� Ȥ�� ��й�ȣ�� Ʋ�Ƚ��ϴ�.");
		}
	}

	else if (a == 1) { // ȸ������
		system("cls");
		printf("=========ȸ������=========\n");
		printf("���̵� �Է� : ");
		gets(id); // ���̵� �Է�
		if (id[0] == 0) { // ���̵� ������ �Է��� ���
			printf("���̵� �Է����ּ���.\n");
			system("pause");
			return;
		}
		printf("�н����� �Է� : ");
		gets(passwd); // ��й�ȣ �Է�
		if (passwd[0] == 0) { // ��й�ȣ�� ������ �Է��� ���
			printf("�н����带 �Է����ּ���.\n");
			system("pause");
			return;
		}
		printf("�г��� �Է� : ");
		gets(name); // �г��� �Է� 
		if (name[0] == 0) {// �г��ӿ� ������ �Է��� ���
			printf("�г����� �Է����ּ���.\n");
			system("pause");
			return;
		}

		sprintf(buffer, "SELECT * FROM user WHERE id='%s'", id);
		// user ���̺��� where ���ǿ� �´� ��� Į���� ���
		mysql_query(connection, buffer); // mysql�ܼ�â�� ���� ��ɾ �Է��ϴ� �Լ�
		result = mysql_store_result(connection); //mysql�� ���� ����� �����Ѵ�.

		if ((row = mysql_fetch_row(result)) == NULL) { 
			buffer[0] = 0; // ���� �ʱ�ȭ 
			sprintf(buffer, "insert into user(id, name, passwd) values('%s', '%s', '%s')", id, name, passwd);
			// ������ ����
			mysql_query(connection, buffer); // mysql�ܼ�â�� ���� ��ɾ �Է��ϴ� �Լ�
		}
		else {
			// row�� null�� �ƴ� ���
			printf("�̹� ���̵� �����մϴ�.\n");
		}
		system("pause");
		return 2;
	}

	else if (a == 2) { // ���ھ� �߰�

		sprintf(buffer, "SELECT * FROM ranking WHERE id='%s' ORDER BY 2 desc", id);
		// ranking ���̺��� where ���ǿ� �´� ��� Į���� ���� ������������ ���
		mysql_query(connection, buffer); // mysql�ܼ�â�� ���� ��ɾ �Է��ϴ� �Լ�
		result = mysql_store_result(connection); //mysql�� ���� ����� �����Ѵ�.

		if ((row = mysql_fetch_row(result)) != NULL) { // result���� �� ��(row)�� �����͸� ������
			if (atoi(row[1]) < best_score) {
				// row[1](score)�� best_score���� ���� ���
				buffer[0] = 0; // ���� �ʱ�ȭ
				sprintf(buffer, "UPDATE ranking SET score = %d WHERE id = '%s'", best_score, id);
				// ranking�� socre�� best_score�� ������ ����
				mysql_free_result(result); //  result�� ���� �޸�(memory)�� �ִ� ������ ��� �����Ѵ�.
				mysql_query(connection, buffer); // mysql�ܼ�â�� ���� ��ɾ �Է��ϴ� �Լ�
				return;
			}
			else {
				mysql_free_result(result); //  result�� ���� �޸�(memory)�� �ִ� ������ ��� �����Ѵ�.
				return;
			}
			
		}
		else {
			mysql_free_result(result); //  result�� ���� �޸�(memory)�� �ִ� ������ ��� �����Ѵ�.
			buffer[0] = 0; // ���� �ʱ�ȭ
			sprintf(buffer, "insert into ranking values('%s', '%d')", id, best_score);
			// ��ŷ�� Į�� ����
			mysql_query(connection, buffer); // mysql�ܼ�â�� ���� ��ɾ �Է��ϴ� �Լ�
			return;
		}
	}
	else if (a == 3) { // ��ŷ Ȯ��
		sprintf(buffer, "SELECT u.name, r.score, u.coin FROM ranking r, user u where r.id = u.id ORDER BY 2 desc");
		// user ���̺�� ranking ���̺��� �����Ͽ� ���� Į���� ������ ������������ ���
		mysql_query(connection, buffer); // mysql�ܼ�â�� ���� ��ɾ �Է��ϴ� �Լ�
		result = mysql_store_result(connection); //mysql�� ���� ����� �����Ѵ�.
		int count = 1, b = 13; // count : ����, b : y��ǥ
		while ((row = mysql_fetch_row(result)) != NULL) // result���� �� ��(row)�� �����͸� �����ͼ� �ݺ������� ó��
		{	
			gotoxy(6, b);
			printf("%-5d   %-6s   %-5s    %-5s\n", count, row[0], row[1], row[2]);
			count++;
			b++;
		}
		return b; // y��ǥ ����
	}

	else if (a == 4) { // ���� �߰�

		sprintf(buffer, "SELECT * FROM user WHERE id='%s'", id);
		// user ���̺��� where ���ǿ� �´� ��� Į���� ���
		// user ���̺��� where ���ǿ� �´� ��� Į���� ���
		mysql_query(connection, buffer); // mysql�ܼ�â�� ���� ��ɾ �Է��ϴ� �Լ�
		result = mysql_store_result(connection); //mysql�� ���� ����� �����Ѵ�.


		if ((row = mysql_fetch_row(result)) != NULL) { // result���� �� ��(row)�� �����͸� ������
			buffer[0] = 0; // ���� �ʱ�ȭ
			mysql_free_result(result); //  result�� ���� �޸�(memory)�� �ִ� ������ ��� �����Ѵ�.
			sprintf(buffer, "UPDATE user SET coin = %d WHERE id = '%s'", coin, id);
			// ���ΰ��� ������Ʈ
			mysql_query(connection, buffer); // mysql�ܼ�â�� ���� ��ɾ �Է��ϴ� �Լ�
			return;
		}
	}
	mysql_close(connection); // MySQL ���� 
}