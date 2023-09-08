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

	// MySQL 초기화 : mysql_init(구조체의 주소 => &mysql)
	mysql_init(&mysql);

	// MySQL 연결 : mysql_real_connect(8개 구조체의 주소, 호스트 이름,)
	connection = mysql_real_connect(&mysql, HOST, USER, PASS, NAME, PORT, NULL, 0);

	// MySQL 서버에 연결하는 과정에서 발생하는 오류를 처리
	if (connection == NULL) {
		fprintf(stderr, "에러 : %s\n", mysql_error(&mysql));
	}

	if (a == 0) { // 로그인
		system("cls");
		printf("=========로그인=========\n");
		printf("아이디를 입력 : ");
		gets(id); // 아이디 입력
		if (id[0] == 0) { // 아이디에 공백을 입력할 경우
			printf("아이디를 입력해주세요.\n");
			system("pause");
			return;
		}
		printf("패스워드 입력 : ");
		gets(passwd); // 비밀번호 입력
		if (passwd[0] == 0) { // 비밀번호에 공백을 입력할 경우
			printf("패스워드를 입력해주세요.\n");
			system("pause");
			return;
		}


		sprintf(buffer, "SELECT * FROM user WHERE id='%s' AND passwd='%s'", id, passwd); 
		// user 테이블에서 where 조건에 맞는 모든 칼럼을 출력
		mysql_query(connection, buffer); 
		// mysql콘솔창에 쓰는 명령어를 입력하는 함수
		result = mysql_store_result(connection); //mysql에 나온 결과를 저장한다.

		while ((row = mysql_fetch_row(result)) != NULL) 
			// result에서 한 행(row)씩 데이터를 가져와서 반복적으로 처리
		{
			if (strcmp(row[0], id) == 0 && strcmp(row[2], passwd) == 0)
			{
				printf("로그인되었습니다.\n");
				coin = atoi(row[3]);
				buffer[0] = 0; // 버퍼 초기화
				sprintf(buffer, "SELECT score FROM ranking WHERE id='%s'", row[0]);
				mysql_query(connection, buffer); 
				// mysql콘솔창에 쓰는 명령어를 입력하는 함수
				mysql_free_result(result); 
				// result에 대한 메모리(memory)에 있는 내용을 모두 제거한다.
				result = mysql_store_result(connection); 
				//mysql에 나온 결과를 저장한다.
				while ((row2 = mysql_fetch_row(result)) != NULL) 
				// result에서 한 행(row)의 데이터를 가져와서 반복적으로 처리
				{
					best_score = atoi(row2[0]);
				}
				system("pause");
				return 1;
			}
			else {
				printf("아이디 또는 비밀번호가 맞지 않습니다.");
			}
		}
		if ((row = mysql_fetch_row(result)) == NULL) {
			printf("아이디 혹은 비밀번호가 틀렸습니다.");
		}
	}

	else if (a == 1) { // 회원가입
		system("cls");
		printf("=========회원가입=========\n");
		printf("아이디를 입력 : ");
		gets(id); // 아이디 입력
		if (id[0] == 0) { // 아이디에 공백을 입력할 경우
			printf("아이디를 입력해주세요.\n");
			system("pause");
			return;
		}
		printf("패스워드 입력 : ");
		gets(passwd); // 비밀번호 입력
		if (passwd[0] == 0) { // 비밀번호에 공백을 입력할 경우
			printf("패스워드를 입력해주세요.\n");
			system("pause");
			return;
		}
		printf("닉네임 입력 : ");
		gets(name); // 닉네임 입력 
		if (name[0] == 0) {// 닉네임에 공백을 입력할 경우
			printf("닉네임을 입력해주세요.\n");
			system("pause");
			return;
		}

		sprintf(buffer, "SELECT * FROM user WHERE id='%s'", id);
		// user 테이블에서 where 조건에 맞는 모든 칼럼을 출력
		mysql_query(connection, buffer); // mysql콘솔창에 쓰는 명령어를 입력하는 함수
		result = mysql_store_result(connection); //mysql에 나온 결과를 저장한다.

		if ((row = mysql_fetch_row(result)) == NULL) { 
			buffer[0] = 0; // 버퍼 초기화 
			sprintf(buffer, "insert into user(id, name, passwd) values('%s', '%s', '%s')", id, name, passwd);
			// 데이터 삽입
			mysql_query(connection, buffer); // mysql콘솔창에 쓰는 명령어를 입력하는 함수
		}
		else {
			// row가 null이 아닐 경우
			printf("이미 아이디가 존재합니다.\n");
		}
		system("pause");
		return 2;
	}

	else if (a == 2) { // 스코어 추가

		sprintf(buffer, "SELECT * FROM ranking WHERE id='%s' ORDER BY 2 desc", id);
		// ranking 테이블에서 where 조건에 맞는 모든 칼럼을 점수 내림차순으로 출력
		mysql_query(connection, buffer); // mysql콘솔창에 쓰는 명령어를 입력하는 함수
		result = mysql_store_result(connection); //mysql에 나온 결과를 저장한다.

		if ((row = mysql_fetch_row(result)) != NULL) { // result에서 한 행(row)의 데이터를 가져옴
			if (atoi(row[1]) < best_score) {
				// row[1](score)이 best_score보다 작을 경우
				buffer[0] = 0; // 버퍼 초기화
				sprintf(buffer, "UPDATE ranking SET score = %d WHERE id = '%s'", best_score, id);
				// ranking의 socre를 best_score의 값으로 변경
				mysql_free_result(result); //  result에 대한 메모리(memory)에 있는 내용을 모두 제거한다.
				mysql_query(connection, buffer); // mysql콘솔창에 쓰는 명령어를 입력하는 함수
				return;
			}
			else {
				mysql_free_result(result); //  result에 대한 메모리(memory)에 있는 내용을 모두 제거한다.
				return;
			}
			
		}
		else {
			mysql_free_result(result); //  result에 대한 메모리(memory)에 있는 내용을 모두 제거한다.
			buffer[0] = 0; // 버퍼 초기화
			sprintf(buffer, "insert into ranking values('%s', '%d')", id, best_score);
			// 랭킹에 칼럼 삽입
			mysql_query(connection, buffer); // mysql콘솔창에 쓰는 명령어를 입력하는 함수
			return;
		}
	}
	else if (a == 3) { // 랭킹 확인
		sprintf(buffer, "SELECT u.name, r.score, u.coin FROM ranking r, user u where r.id = u.id ORDER BY 2 desc");
		// user 테이블과 ranking 테이블의 조인하여 나온 칼럼을 점수의 내림차순으로 출력
		mysql_query(connection, buffer); // mysql콘솔창에 쓰는 명령어를 입력하는 함수
		result = mysql_store_result(connection); //mysql에 나온 결과를 저장한다.
		int count = 1, b = 13; // count : 성적, b : y좌표
		while ((row = mysql_fetch_row(result)) != NULL) // result에서 한 행(row)씩 데이터를 가져와서 반복적으로 처리
		{	
			gotoxy(6, b);
			printf("%-5d   %-6s   %-5s    %-5s\n", count, row[0], row[1], row[2]);
			count++;
			b++;
		}
		return b; // y좌표 리턴
	}

	else if (a == 4) { // 코인 추가

		sprintf(buffer, "SELECT * FROM user WHERE id='%s'", id);
		// user 테이블에서 where 조건에 맞는 모든 칼럼을 출력
		// user 테이블에서 where 조건에 맞는 모든 칼럼을 출력
		mysql_query(connection, buffer); // mysql콘솔창에 쓰는 명령어를 입력하는 함수
		result = mysql_store_result(connection); //mysql에 나온 결과를 저장한다.


		if ((row = mysql_fetch_row(result)) != NULL) { // result에서 한 행(row)의 데이터를 가져옴
			buffer[0] = 0; // 버퍼 초기화
			mysql_free_result(result); //  result에 대한 메모리(memory)에 있는 내용을 모두 제거한다.
			sprintf(buffer, "UPDATE user SET coin = %d WHERE id = '%s'", coin, id);
			// 코인값을 업데이트
			mysql_query(connection, buffer); // mysql콘솔창에 쓰는 명령어를 입력하는 함수
			return;
		}
	}
	mysql_close(connection); // MySQL 종료 
}
