#pragma once

// �ߺ� ���� ����
#ifndef __STDIO_H__ // __STDIO_H__ ��� ��ũ�ΰ� ���ǵǾ����� ������
#define __STDIO_H__ //__STDIO_H__ �� �����Ѵ�
#include <stdio.h> // stdio.h ��������� �����Ѵ�
#endif // ifndef ����

#ifndef __WINDOWS_H__ // __WINDOWS_H__ ��� ��ũ�ΰ� ���ǵǾ����� ������
#define __WINDOWS_H__ // __WINDOWS_H__ �� �����Ѵ�
#include<windows.h> // windows.h ��������� �����Ѵ�
#endif // ifndef ����

#ifndef __CONIO_H__ // __CONIO_H__ ��� ��ũ�ΰ� ���ǵǾ����� ������
#define __CONIO_H__ // __CONIO_H__ �� �����Ѵ�
#include<conio.h> // conio.h
#endif // ifndef ����

#ifndef __TIME_H__ // __TIME_H__ ��� ��ũ�ΰ� ���ǵǾ����� ������
#define __TIME_H__ // __TIME_H__ �� �����Ѵ�
#include<time.h> // time.h ��������� �����Ѵ�
#endif // ifndef ����

#ifndef __STDBOOL_H__ // __STDBOOL_H__ ��� ��ũ�ΰ� ���ǵǾ����� ������
#define __STDBOOL_H__ // __STDBOOL_H__ �� �����Ѵ�
#include <stdbool.h> // stdbool.h ��������� �����Ѵ�
#endif // ifndef ����

#ifndef __STDLIB_H__ // __STDLIB_H__ ��� ��ũ�ΰ� ���ǵǾ����� ������
#define __STDLIB_H__ // __STDLIB_H__ �� �����Ѵ�
#include <stdlib.h> // stdlib.h ��������� �����Ѵ�
#endif // ifndef ����

#define _CRT_SECURE_NO_WARNNINGS

#include <mysql.h>		// mysql.h ��������� �����Ѵ�.
#include <mmsystem.h>   // mmsystem.h ��������� �����Ѵ�. (�뷡)
#pragma comment(lib, "winmm.lib"); 

#define HOST "127.0.0.1" // mysql HOST
#define NAME "i_stairs"	 // mysql NAME
#define USER "root"		 // mysql USER
#define PASS "abc123"    // mysql PASSWD
#define PORT 3306		 // mysql PORT

#define ESC 27 // ESC
#define LEFT 75 // ���� ��
#define RIGHT 77 // ������ ��
#define DOWN 80 // �Ʒ��� ��
#define UP  72 // ���� ��
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