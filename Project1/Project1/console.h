#pragma once
#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <stdbool.h>
#include <time.h>

#define OUTPUT_HANDLE GetStdHandle(STD_OUTPUT_HANDLE)
#define UP 300
#define LEFT 301
#define RIGHT 302
#define DOWN 303
#define SPACE 304

int randomkey = (int)time(NULL);

enum BLOCKTYPE { BLOCK_AIR, BLOCK_WALL, BLOCK_FOOD };
enum SANKETYPE { HEAD_UP, HEAD_LEFT, HEAD_RIGHT, HEAD_DOWN, BODY, TAIL };

typedef struct _BOX_SIZE {
	short width, height;
} BOX_SIZE;

BOX_SIZE consoleSize = { 120, 30 };

void setCursorPos(short x, short y);
void setCursorVisibility(unsigned long size, bool visibility);
void setConsoleSize(short width, short height);
int getKeyDown();

void setCursorPos(short x, short y) {
	COORD position = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}

void setCursorVisibility(unsigned long size, bool visibility) {
	CONSOLE_CURSOR_INFO cursorInfo = { size, visibility };
	SetConsoleCursorInfo(OUTPUT_HANDLE, &cursorInfo);
}

void setConsoleSize(short width, short height) {
	SMALL_RECT rect = { 0, 0, width, height };
	SetConsoleWindowInfo(OUTPUT_HANDLE, TRUE, &rect);

	COORD bufferSize = { width + 1, height + 1 };
	SetConsoleScreenBufferSize(OUTPUT_HANDLE, bufferSize);

	consoleSize.height = height, consoleSize.width = width;
}

int getKeyDown() {
	if (_kbhit()) {
		unsigned char ch = _getch();
		if (ch == 224) {
			switch (_getch()) {
			case 72:
				return UP;
				break;
			case 75:
				return LEFT;
				break;
			case 77:
				return RIGHT;
				break;
			case 80:
				return DOWN;
				break;
			}
		}
		else if (ch == ' ')
			return SPACE;
		else
			return ch;
	}
	return -1;
}

int random(int min, int max) {
	max++;
	srand(randomkey++);
	return rand() % ((max - min) - 1) + min;
}