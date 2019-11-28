#pragma warning(disable:4996)
#include <stdio.h>
#include <iostream>
#include <functional>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include "console.h"

void SingleProcess(int); //혼자하기
void MultiProcess(); //같이하기
void CallengesList(); //도전과제
void MainScene(); //메인화면
void Save(); //저장
void Read(); //불러오기

int score = 500; //점수
bool callenges[6] = { false, false, false, false, false };
bool players[6] = { true, true, true, true, true, true };
bool callenges_update = false;
int player_position; //플레이어 위치

int main() {
	Read(); //시작할때 불러오기
	setCursorVisibility(1, false); //마우스 커서 숨기기
	setConsoleSize(106, 15); //콘솔창 크기 조절
	MainScene(); //루프 시작
}

void CallengesList() {
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	printf("                                                                                                           \n");
	printf("                                                                                                           \n");
	if (callenges[0])
		printf(" %%최로로 혼자하기 하기%%                                실력도 운이다                                       \n");
	else
		printf("                                               ????                                                        \n");
	printf("                                                                                                           \n");

	if (callenges[1])
		printf(" %%점수 -1000점 이하%%                               정말 운이 없으시네요.                                   \n");
	else
		printf("                                               ????                                                        \n");
	printf("                                                                                                           \n");

	if (callenges[2])
		printf(" %%점수 -3000점 이하%%                     이 게임이 실제였다면 당신은 10번은 죽었어요!                      \n");
	else
		printf("                                               ????                                                        \n");
	printf("                                                                                                           \n");

	if (callenges[3])
		printf(" %%점수 1000점 이상%%                                    도박은 나쁜것.                                      \n");
	else
		printf("                                               ????                                                        \n");
	printf("                                                                                                           \n");

	if (callenges[4])
		printf(" %%점수 3000점 이상%%                                그렇게나 자신있나보죠?                                 \n");
	else
		printf("                                               ????                                                        \n");
	printf("                                                                                                           \n");

	if (callenges[5])
		printf(" %%점수 5000점 이상%%                             한국도박문제관리센터 - '1336'                              \n");
	else
		printf("                                               ????                                                        \n");
	printf("                                                                                                           \n");
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");

	getch();
	MainScene();
}

void MultiProcess() {
	setCursorPos(0, 0);
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	printf("                                                                                                           \n");
	printf("                                                                                                           \n");
	printf("                                                                                                           \n");
	printf("                                                                                                           \n");
	printf("                                     Input Player Count (Max : 6)                                          \n");
	printf("                                                                                                           \n");
	printf("                                                                                                           \n");
	printf("                                                                                                           \n");
	printf("                                                                                                           \n");
	printf("                                                                                                           \n");
	printf("                                                                                                           \n");
	printf("                                                                                                           \n");
	printf("                                                                                                           \n");
	printf("                                                                                                           \n");
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
	setCursorPos(50, 8);
	bool players_open[6] = { true,true,true,true,true,true };
	int player_count;
	scanf("%d", &player_count);

	setCursorPos(0, 0);
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	printf("                                                                                                           \n");
	printf("                                                                                                           \n");
	for (int i = 0; i < 6; i++) {
		if (i < player_count) {
			printf("                                                  ♤                                                       \n");
			printf("                                                                                                           \n");
		}
		else {
			printf("                                                                                                           \n");
			printf("                                                                                                           \n");
		}
	}
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
	int bullet_position = random(0, player_count);

	for (int i = 0; i < player_count; i++) {
		getch();
		if (bullet_position == i) {
			setCursorPos(0, 2 * i + 3);
			setConsoleColor(4);
			printf("                                                  ♤ Die                                                   \n");
		}
		else {
			setCursorPos(0, 2 * i + 3);
			setConsoleColor(2);
			printf("                                                  ♤ Alive                                                 \n");
		}
	}

	setConsoleColor(7);

	Sleep(1000);
	MainScene();
}

void SingleProcess(int player_count) {
	setCursorPos(0, 0);
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
	
	int bullet_position = random(0, 6); //총알의 위치
	while (!players[bullet_position])
		bullet_position = random(0, 6);
	//y position = 2x + 3
	//print at x position 53

	setCursorPos(0, 2 * player_position + 3);
	printf("                                           You => ♤                                                       \n");
	
	setConsoleColor(4);
	for (int i = 0; i < 6; i++) { //죽은 플에이어는 빨간색으로 표시
		if (!players[i]) {
			setCursorPos(0, 2 * i + 3);
			printf("                                                  ♤ Die                                                   \n");
		}
	}
	setConsoleColor(7);

	for (int i = 0; i < 6; i++) { //플레이어 상태 표시
		if (players[i]) {
			if (i == bullet_position) {
				setCursorPos(53, 2 * i + 3);
				players[i] = false;
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
	}

	setCursorPos(0, 14);
	printf("                                      Press any key to continue                                            \n");
	getch();

	if (player_position == bullet_position) {//플레이어가 죽으면
		setCursorPos(0, 0);
		score -= 300;
		printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
		printf("                                                                                                           \n");
		printf("                                                                                                           \n");
		printf("                                              죽었습니다!                                                  \n");
		printf("                                                                                                           \n");
		printf("                                                                                                           \n");
		printf("                                                                                                           \n");
		printf("                                                                                                           \n");
		printf("                                      Press any key to continue                                            \n");
		printf("                                                                                                           \n");
		printf("                                                                                                           \n");
		printf("                                             Score : %5d                                              \n", score);
		printf("                                                                                                           \n");
		printf("                                                                                                           \n");
		printf("                                                                                                           \n");
		printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
		if (!callenges[1] && score <= -1000) {
			callenges[1] = true;
			callenges_update = true;
		}
		if (!callenges[2] && score <= -3000) {
			callenges[2] = true;
			callenges_update = true;
		}
		Save();
		getch();
		MainScene();
	}
	else if (player_count > 2) { //3명 이상 살아남았으면
		setCursorPos(0, 0);
		printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
		printf("                                                                                                           \n");
		printf("                                                                                                           \n");
		printf("                                  계속 하시겠습니까? (얻는 점수 2배)                                       \n");
		printf("                                                                                                           \n");
		printf("                                                                                                           \n");
		printf("                                                                                                           \n");
		printf("                                                                                                           \n");
		printf("                                                Y or N                                                     \n");
		printf("                                                                                                           \n");
		printf("                                                                                                           \n");
		printf("                                             Score : %5d                                              \n", score);
		printf("                                                                                                           \n");
		printf("                                                                                                           \n");
		printf("                                                                                                           \n");
		printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");

		while (1) {
			switch (getKeyDown())
			{
			case 'y':
				if (!callenges[3] && score >= 1000) {
					callenges[3] = true;
					callenges_update = true;
				}
				if (!callenges[4] && score >= 3000) {
					callenges[4] = true;
					callenges_update = true;
				}
				if (!callenges[5] && score >= 5000) {
					callenges[5] = true;
					callenges_update = true;
				}
				SingleProcess(player_count - 1);
				break;
			case 'n':
				score += (6 - player_count) * 200;
				Save();
				MainScene();
				break;
			default:
				break;
			}
		}
	}
	else { //최후의 승자일떄
		setCursorPos(0, 0);
		score += 1000;
		printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
		printf("                                                                                                           \n");
		printf("                                                                                                           \n");
		printf("                                              축하합니다!                                                  \n");
		printf("                                                                                                           \n");
		printf("                                                                                                           \n");
		printf("                                                                                                           \n");
		printf("                                                                                                           \n");
		printf("                                      Press any key to continue                                            \n");
		printf("                                                                                                           \n");
		printf("                                                                                                           \n");
		printf("                                             Score : %5d                                              \n", score);
		printf("                                                                                                           \n");
		printf("                                                                                                           \n");
		printf("                                                                                                           \n");
		printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
		if (!callenges[3] && score >= 1000) {
			callenges[3] = true;
			callenges_update = true;
		}
		if (!callenges[4] && score >= 3000) {
			callenges[4] = true;
			callenges_update = true;
		}
		if (!callenges[5] && score >= 5000) {
			callenges[5] = true;
			callenges_update = true;
		}
		Save();
		getch();
		MainScene();
	}
}

void MainScene() {
	int select = 0; //현재 선택 메뉴

	setCursorPos(0, 0);
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
	if(callenges_update)
		printf("                                             ☆도전과제☆                                                  \n");
	else
		printf("                                               도전과제                                                    \n");
	printf("                                                                                                           \n");
	printf("                                                 종료                                                      \n");
	printf("                                                                                                           \n");
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
		player_position = random(0, 6 - 1); //플레이어 위치 초기화
		
		for (int i = 0; i < 6; i++) {
			players[i] = true;
		}

		if (!callenges[0]) {
			callenges[0] = true;
			callenges_update = true;
		}
		SingleProcess(6);
		break;
	case 1:
		MultiProcess();
		break;
	case 2:
		callenges_update = false;
		CallengesList();
		break;
	case 3:
		Save();
		exit(0);
		break;
	default:
		break;
	}
}

void Save() {
	FILE* fp;

	fp = fopen("data", "w");
	
	fprintf(fp, "%d\n", score);

	for (int i = 0; i < 6; i++) {
			fprintf(fp, "%d\n", callenges[i]);
	}

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

	for (int i = 0; i < 6; i++) {
		char callenge_clear[10];

		fgets(callenge_clear, 10, fp);
		
		if (callenge_clear[0] == '1')
			callenges[i] = true;
		else
			callenges[i] = false;
	}

	fclose(fp);
}