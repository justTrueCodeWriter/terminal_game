#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

const int x = 121, y = 40;

#include "character_parameters.h"

int map[y][x];
bool game = true;

Character mas[1];

void DrawMap(); void Move(); void GetMap();

int main() {
	GetMap();
	do {
		DrawMap();
		Move();
		system("cls");
	} while (game == true);
}

void GetMap() {
	FILE* m;

	if (fopen_s(&m, "map.txt", "rt") != 0) {
		printf("File couldn't open\n");
		exit(1);
	}

	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			fscanf_s(m, "%c", &map[i][j]);
		}
	}
	fclose(m);
}

void DrawMap() {

	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			int isCharacterMove = 0;
			if (j == mas->xCharacter and i == mas->yCharacter) {
				map[i][j] = '@';
				isCharacterMove = 1;
			}
			printf("%c", map[i][j]);
			if (isCharacterMove == 1)
				map[i][j] = ' ';
		}
	}
}

void Move() {
	switch (_getch()) {
	case 'z':
		game = false;
		break;
	case 'w':
		mas->yCharacter--;
		break;
	case 'a':
		mas->xCharacter--;
		break;
	case 'd':
		mas->xCharacter++;
		break;
	case 's':
		mas->yCharacter++;
		break;
	}
}
