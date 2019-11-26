#pragma warning(disable:4996)
#include <stdio.h>
#include <iostream>
#include <functional>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include "console.h"

void singleProcess(int); //ȥ���ϱ�
//void multiProcess(); //�����ϱ�
//void CallengesList(); //��������
void MainScene(); //����ȭ��
void Save(); //����
void Read(); //�ҷ�����

int score = 100; //����

int main() {
	Read(); //�����Ҷ� �ҷ�����
	setCursorVisibility(1, false); //���콺 Ŀ�� �����
	MainScene(); //���� ����
}

void singleProcess(int player_count) {
	bool players[6] = { true, true, true, true, true, true};
	setCursorPos(0, 0);
	setConsoleSize(106, 15);
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	printf("                                                                                          Score : %5d \n",score);
	printf("                                                                                                           \n");
	printf("                                                  ��                                                       \n");
	printf("                                                                                                           \n");
	printf("                                                  ��                                                       \n");
	printf("                                                                                                           \n");
	printf("                                                  ��                                                       \n");
	printf("                                                                                                           \n");
	printf("                                                  ��                                                       \n");
	printf("                                                                                                           \n");
	printf("                                                  ��                                                       \n");
	printf("                                                                                                           \n");
	printf("                                                  ��                                                       \n");
	printf("                                                                                                           \n");
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");

	int player_position = random(0, player_count - 1); //�÷��̾� ��ġ
	int bullet_position = random(0, player_count - 1); //�Ѿ��� ��ġ
	//y position = 2x + 3
	//print at x position 53

	setCursorPos(0, 2 * player_position + 3);
	printf("                                           You => ��                                                       \n");
	
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
	int select = 0; //���� ���� �޴�

	setCursorPos(0, 0);
	setConsoleSize(106, 14);
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	printf("                                                                                                           \n");
	printf("                                              ���þ� �귿                                                  \n");
	printf("                                                                                                           \n");
	printf("                                                                                                           \n");
	printf("                                                                                                           \n");
	printf("                                             ��ȥ���ϱ⢷                                                  \n");
	printf("                                                                                                           \n");
	printf("                                               �����ϱ�                                                    \n");
	printf("                                                                                                           \n");
	printf("                                               ��������                                                    \n");
	printf("                                                                                                           \n");
	printf("                                                 ����                                                      \n");
	printf("                                                                                                           \n");
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");

	std::function<void()> update = [&]() { //����ȭ�鿡���� ����� �Լ�, �� ������ �Լ� ���� �� ���ٽ� ����
		switch (select)
		{
		case 0:
			setCursorPos(0, 6);
			printf("                                             ��ȥ���ϱ⢷                                                  \n");
			printf("                                                                                                           \n");
			printf("                                               �����ϱ�                                                    \n");
			printf("                                                                                                           \n");
			printf("                                               ��������                                                    \n");
			printf("                                                                                                           \n");
			printf("                                                 ����                                                      \n");
			break;
		case 1:
			setCursorPos(0, 6);
			printf("                                               ȥ���ϱ�                                                    \n");
			printf("                                                                                                           \n");
			printf("                                             �������ϱ⢷                                                  \n");
			printf("                                                                                                           \n");
			printf("                                               ��������                                                    \n");
			printf("                                                                                                           \n");
			printf("                                                 ����                                                      \n");
			break;
		case 2:
			setCursorPos(0, 6);
			printf("                                               ȥ���ϱ�                                                    \n");
			printf("                                                                                                           \n");
			printf("                                               �����ϱ�                                                    \n");
			printf("                                                                                                           \n");
			printf("                                             ������������                                                  \n");
			printf("                                                                                                           \n");
			printf("                                                 ����                                                      \n");
			break;
		case 3:
			setCursorPos(0, 6);
			printf("                                               ȥ���ϱ�                                                    \n");
			printf("                                                                                                           \n");
			printf("                                               �����ϱ�                                                    \n");
			printf("                                                                                                           \n");
			printf("                                               ��������                                                    \n");
			printf("                                                                                                           \n");
			printf("                                               �����ᢷ                                                     \n");
			break;
		default:
			break;
		}
	};

	bool selecting = true; //�ݺ����� ���������� ����
	while (selecting) { //����
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

	switch (select) //���õ� �̺�Ʈ ����
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

	if (fp == NULL) { //���� ����� ���ϻ���
		Save(); 
		fp = fopen("data", "r");
	}

	char str_score[100];

	fgets(str_score, 100, fp);

	score = atoi(str_score); //���ڿ��� �μ��� ��ȯ�� ������ ����

	fclose(fp);
}