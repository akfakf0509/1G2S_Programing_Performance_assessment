#pragma warning(disable:4996)
#include <stdio.h>
#include <iostream>
#include <functional>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include "console.h"

void SingleProcess(int); //ȥ���ϱ�
void MultiProcess(); //�����ϱ�
void CallengesList(); //��������
void MainScene(); //����ȭ��
void Save(); //����
void Read(); //�ҷ�����

int score = 500; //����
bool callenges[6] = { false, false, false, false, false };
bool players[6] = { true, true, true, true, true, true };
bool callenges_update = false;
int player_position; //�÷��̾� ��ġ

int main() {
	Read(); //�����Ҷ� �ҷ�����
	setCursorVisibility(1, false); //���콺 Ŀ�� �����
	setConsoleSize(106, 15); //�ܼ�â ũ�� ����
	MainScene(); //���� ����
}

void CallengesList() {
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	printf("                                                                                                           \n");
	printf("                                                                                                           \n");
	if (callenges[0])
		printf(" %%�ַη� ȥ���ϱ� �ϱ�%%                                �Ƿµ� ���̴�                                       \n");
	else
		printf("                                               ????                                                        \n");
	printf("                                                                                                           \n");

	if (callenges[1])
		printf(" %%���� -1000�� ����%%                               ���� ���� �����ó׿�.                                   \n");
	else
		printf("                                               ????                                                        \n");
	printf("                                                                                                           \n");

	if (callenges[2])
		printf(" %%���� -3000�� ����%%                     �� ������ �������ٸ� ����� 10���� �׾����!                      \n");
	else
		printf("                                               ????                                                        \n");
	printf("                                                                                                           \n");

	if (callenges[3])
		printf(" %%���� 1000�� �̻�%%                                    ������ ���۰�.                                      \n");
	else
		printf("                                               ????                                                        \n");
	printf("                                                                                                           \n");

	if (callenges[4])
		printf(" %%���� 3000�� �̻�%%                                �׷��Գ� �ڽ��ֳ�����?                                 \n");
	else
		printf("                                               ????                                                        \n");
	printf("                                                                                                           \n");

	if (callenges[5])
		printf(" %%���� 5000�� �̻�%%                             �ѱ����ڹ����������� - '1336'                              \n");
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
			printf("                                                  ��                                                       \n");
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
			printf("                                                  �� Die                                                   \n");
		}
		else {
			setCursorPos(0, 2 * i + 3);
			setConsoleColor(2);
			printf("                                                  �� Alive                                                 \n");
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
	
	int bullet_position = random(0, 6); //�Ѿ��� ��ġ
	while (!players[bullet_position])
		bullet_position = random(0, 6);
	//y position = 2x + 3
	//print at x position 53

	setCursorPos(0, 2 * player_position + 3);
	printf("                                           You => ��                                                       \n");
	
	setConsoleColor(4);
	for (int i = 0; i < 6; i++) { //���� �ÿ��̾�� ���������� ǥ��
		if (!players[i]) {
			setCursorPos(0, 2 * i + 3);
			printf("                                                  �� Die                                                   \n");
		}
	}
	setConsoleColor(7);

	for (int i = 0; i < 6; i++) { //�÷��̾� ���� ǥ��
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

	if (player_position == bullet_position) {//�÷��̾ ������
		setCursorPos(0, 0);
		score -= 300;
		printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
		printf("                                                                                                           \n");
		printf("                                                                                                           \n");
		printf("                                              �׾����ϴ�!                                                  \n");
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
	else if (player_count > 2) { //3�� �̻� ��Ƴ�������
		setCursorPos(0, 0);
		printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
		printf("                                                                                                           \n");
		printf("                                                                                                           \n");
		printf("                                  ��� �Ͻðڽ��ϱ�? (��� ���� 2��)                                       \n");
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
	else { //������ �����ϋ�
		setCursorPos(0, 0);
		score += 1000;
		printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
		printf("                                                                                                           \n");
		printf("                                                                                                           \n");
		printf("                                              �����մϴ�!                                                  \n");
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
	int select = 0; //���� ���� �޴�

	setCursorPos(0, 0);
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
	if(callenges_update)
		printf("                                             �ٵ���������                                                  \n");
	else
		printf("                                               ��������                                                    \n");
	printf("                                                                                                           \n");
	printf("                                                 ����                                                      \n");
	printf("                                                                                                           \n");
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
		player_position = random(0, 6 - 1); //�÷��̾� ��ġ �ʱ�ȭ
		
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

	if (fp == NULL) { //���� ����� ���ϻ���
		Save(); 
		fp = fopen("data", "r");
	}

	char str_score[100];

	fgets(str_score, 100, fp);

	score = atoi(str_score); //���ڿ��� �μ��� ��ȯ�� ������ ����

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