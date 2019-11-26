#pragma warning(disable:4996)
#include <stdio.h>
#include <iostream>
#include <functional>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include "console.h"

void singleProcess(int); //혼자하기
//void multiProcess(); //같이하기
//void CallengesList(); //도전과제
void MainScene(); //메인화면
void Save(); //저장
void Read(); //불러오기

int score = 100; //점수

int main() {
	Read(); //시작할때 불러오기
	setCursorVisibility(1, false); //마우스 커서 숨기기
	MainScene(); //루프 시작
}

void singleProcess(int player_count) {
	bool players[6] = { true, true, true, true, true, true};
	setCursorPos(0, 0);
	setConsoleSize(106, 15);
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	printf("                                                                                          Score : %5d \n",score);
	printf("                                                                                                           \n");
	printf("                                                  ♤                                                       \n");
	printf("                                                                                                           \n");
	printf("                                                  ♤                                                       \n");
	printf("                                                                                                           \n");
	printf("                                                  ♤                                                       \n");
	printf("                                                                                                           \n");
	printf("                                                  ♤                                                       \n");
	printf("                                                                                                           \n");
	printf("                                                  ♤                                                       \n");
	printf("                                                                                                           \n");
	printf("                                                  ♤                                                       \n");
	printf("                                                                                                           \n");
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");

	int player_position = random(0, player_count - 1); //플레이어 위치
	int bullet_position = random(0, player_count - 1); //총알의 위치
	//y position = 2x + 3
	//print at x position 53

	setCursorPos(0, 2 * player_position + 3);
	printf("                                           You => ♤                                                       \n");
	
	for (int i = 0; i < 6; i++) {
		if (i == bullet_position) {
			setCursorPos(53, 2 * i + 3);
			printf("Die");
		}
		else {
			setCursorPos(53, 2 * i + 3);
			printf("Alive");
		}

		if (i < bullet_position)
			Sleep(700);
		Sleep(300);
	}

	setCursorPos(0, 14);
	printf("                                      Press any key to continue                                            \n");
	getch();
}

void MainScene() {
	int select = 0; //현재 선택 메뉴

	setCursorPos(0, 0);
	setConsoleSize(106, 14);
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	printf("                                                                                                           \n");
	printf("                                              러시안 룰렛                                                  \n");
	printf("                                                                                                           \n");
	printf("                                                                                                           \n");
	printf("                                                                                                           \n");
	printf("                                             ▷혼자하기◁                                                  \n");
	printf("                                                                                                           \n");
	printf("                                               같이하기                                                    \n");
	printf("                                                                                                           \n");
	printf("                                               도전과제                                                    \n");
	printf("                                                                                                           \n");
	printf("                                                 종료                                                      \n");
	printf("                                                                                                           \n");
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");

	std::function<void()> update = [&]() { //메인화면에서만 사용할 함수, 즉 포인터 함수 선언 후 람다식 대입
		switch (select)
		{
		case 0:
			setCursorPos(0, 6);
			printf("                                             ▷혼자하기◁                                                  \n");
			printf("                                                                                                           \n");
			printf("                                               같이하기                                                    \n");
			printf("                                                                                                           \n");
			printf("                                               도전과제                                                    \n");
			printf("                                                                                                           \n");
			printf("                                                 종료                                                      \n");
			break;
		case 1:
			setCursorPos(0, 6);
			printf("                                               혼자하기                                                    \n");
			printf("                                                                                                           \n");
			printf("                                             ▷같이하기◁                                                  \n");
			printf("                                                                                                           \n");
			printf("                                               도전과제                                                    \n");
			printf("                                                                                                           \n");
			printf("                                                 종료                                                      \n");
			break;
		case 2:
			setCursorPos(0, 6);
			printf("                                               혼자하기                                                    \n");
			printf("                                                                                                           \n");
			printf("                                               같이하기                                                    \n");
			printf("                                                                                                           \n");
			printf("                                             ▷도전과제◁                                                  \n");
			printf("                                                                                                           \n");
			printf("                                                 종료                                                      \n");
			break;
		case 3:
			setCursorPos(0, 6);
			printf("                                               혼자하기                                                    \n");
			printf("                                                                                                           \n");
			printf("                                               같이하기                                                    \n");
			printf("                                                                                                           \n");
			printf("                                               도전과제                                                    \n");
			printf("                                                                                                           \n");
			printf("                                               ▷종료◁                                                     \n");
			break;
		default:
			break;
		}
	};

	bool selecting = true; //반복문을 나오기위한 변수
	while (selecting) { //루프
		switch (getKeyDown()) 
		{
		case UP:
			if (select > 0)
				select--;
			update();
			break;
		case DOWN:
			if (select < 3)
				select++;
			update();
			break;
		case SPACE:
			selecting = false;
			break;
		default:
			break;
		}
	}

	switch (select) //선택된 이벤트 실행
	{
	case 0 :
		singleProcess(6);
		break;
	case 1:
		break;
	case 2:
		break;
	case 3:
		exit(0);
		break;
	default:
		break;
	}
}

void Save() {
	FILE* fp;

	fp = fopen("data", "w");
	
	fprintf(fp, "%d", score);

	fclose(fp);
}

void Read() {
	FILE* fp;

	fp = fopen("data", "r");

	if (fp == NULL) { //최초 실행시 파일생성
		Save(); 
		fp = fopen("data", "r");
	}

	char str_score[100];

	fgets(str_score, 100, fp);

	score = atoi(str_score); //문자열을 인수로 변환해 변수에 대입

	fclose(fp);
}