#pragma once

// 중복 선언 방지
#ifndef __STDIO_H__ // __STDIO_H__ 라는 매크로가 정의되어있지 않으면
#define __STDIO_H__ //__STDIO_H__ 를 정의한다
#include <stdio.h> // stdio.h 헤더파일을 선언한다
#endif // ifndef 종료

#ifndef __WINDOWS_H__ // __WINDOWS_H__ 라는 매크로가 정의되어있지 않으면
#define __WINDOWS_H__ // __WINDOWS_H__ 를 정의한다
#include<windows.h> // windows.h 헤더파일을 선언한다
#endif // ifndef 종료

#ifndef __CONIO_H__ // __CONIO_H__ 라는 매크로가 정의되어있지 않으면
#define __CONIO_H__ // __CONIO_H__ 를 정의한다
#include<conio.h> // conio.h
#endif // ifndef 종료

#ifndef __TIME_H__ // __TIME_H__ 라는 매크로가 정의되어있지 않으면
#define __TIME_H__ // __TIME_H__ 를 정의한다
#include<time.h> // time.h 헤더파일을 선언한다
#endif // ifndef 종료

#ifndef __STDBOOL_H__ // __STDBOOL_H__ 라는 매크로가 정의되어있지 않으면
#define __STDBOOL_H__ // __STDBOOL_H__ 를 정의한다
#include <stdbool.h> // stdbool.h 헤더파일을 선언한다
#endif // ifndef 종료

#ifndef __STDLIB_H__ // __STDLIB_H__ 라는 매크로가 정의되어있지 않으면
#define __STDLIB_H__ // __STDLIB_H__ 를 정의한다
#include <stdlib.h> // stdlib.h 헤더파일을 선언한다
#endif // ifndef 종료

#define _CRT_SECURE_NO_WARNNINGS

#include <mysql.h>		// mysql.h 헤더파일을 선언한다.
#include <mmsystem.h>   // mmsystem.h 헤더파일을 선언한다. (노래)
#pragma comment(lib, "winmm.lib"); 

#define HOST "127.0.0.1" // mysql HOST
#define NAME "i_stairs"	 // mysql NAME
#define USER "root"		 // mysql USER
#define PASS "abc123"    // mysql PASSWD
#define PORT 3306		 // mysql PORT

#define ESC 27 // ESC
#define LEFT 75 // 왼쪽 ←
#define RIGHT 77 // 오른쪽 →
#define DOWN 80 // 아래쪽 ↓
#define UP  72 // 위쪽 ↑
#define ENTER 13 // ENTER

int main_screen();
void Tutorial();
void gotoxy(int, int);
void DrawPlayer();
void ErasePlayer();
void MovePlayer();
int Score();
int GameOver(int);
int Stair();
int CoinScore();
int ScreenReset();
void Interface();
int LoginScreen();
void gameOverUI();
void Ranking();
int GameLoop();
int DBsys(int a);
void cursor();