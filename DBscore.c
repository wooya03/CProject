#include "a.h"

extern int best_score;

void DBscore(char(*p)[15]) {
	MYSQL mysql = { 0 };
	MYSQL* connection = NULL;
	MYSQL_RES* result = NULL;
	MYSQL_ROW* row = { 0 };

	char id[15] = { 0 };
	char buffer[200] = { 0, };
	char buffer2[200] = { 0, };
	// mysql 초기화 : mysql_init(구조체의 주소 => &mysql)
	mysql_init(&mysql);

	// mysql 연결 : mysql_real_connect(8개 구조체의 주소, 호스트 이름,)
	connection = mysql_real_connect(&mysql, HOST, USER, PASS, NAME, PORT, NULL, 0);

	if (connection == NULL) {
		fprintf(stderr, "에러 : %s\n", mysql_error(&mysql));
	}

	sprintf(buffer, "delete from ranking where id='%s'", &p[0]);
	mysql_query(connection, buffer);
	sprintf(buffer2, "INSERT INTO ranking VALUES('%s','%d')", &p[0], best_score);
	mysql_query(connection, buffer2);
	mysql_close(connection);
}