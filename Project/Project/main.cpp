#pragma warning(disable:4996)
#include <stdio.h>
#include <vector>
#include "console.h"

int main() {
	std::vector<int> vec;

	int player_count;

	printf("input player count : ");
	scanf("%d", &player_count);

	int input_bullet = random(0, player_count - 1);

	for (int i = 0; i < player_count; i++) {
		if (i == input_bullet)
			vec.push_back(1);
		else
			vec.push_back(0);
	}

	while (!vec.empty()) {
		printf("push any key\n");
		getch();

		if (vec.back()) {
			printf("you died!\n");
		}
		else
			printf("you live!\n");

		vec.pop_back();
	}
	
	getch();
}