#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <math.h>

#include "character_parameters.h"

const int x = SCREEN_WIDTH, y = SCREEN_HEIGHT;

int map[y][x];
bool game = true;

Character hero[1];

Enemy villian[1];

void draw_map(); 
void characterMoves(); 
void GetMap();

void enemy_activation();
void enemy_moves();

int main() {
	GetMap();
	do {
		draw_map();
		printf("\n");
		enemy_activation();
		characterMoves();
		system("cls");
	} while (game == true);
}

void GetMap() {
	FILE* m;

	if (fopen_s(&m, "map_2.txt", "rt") != 0) {
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

void draw_map() {

	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			int isCharacterMove = 0;
			int isVillianMove = 0;
			int isWall = 0;
			if (j == hero->xCharacter and i == hero->yCharacter) {
				map[i][j] = '@';
				isCharacterMove = 1;
			}
			if (j == villian->xEnemy and i == villian->yEnemy) {
				map[i][j] = 'E';
				isVillianMove = 1;
			}
			printf("%c", map[i][j]);
			if (isCharacterMove == 1)
				map[i][j] = ' ';
		}
	}
}

void enemy_activation() {
	if (abs(villian->xEnemy - hero->xCharacter) <= 5 && abs(villian->yEnemy - hero->yCharacter) <= 5)
		enemy_moves();

}

void enemy_moves() {

	if ()

}

void characterMoves() {
	switch (_getch()) {
	case 'z':
		game = false;
		break;
	case 'w':
		if (map[(hero->yCharacter) - 1][hero->xCharacter] != 'E' && map[(hero->yCharacter) - 1][hero->xCharacter] != 219)
			hero->yCharacter--;
		break;
	case 'a':
		if (map[hero->yCharacter][(hero->xCharacter) - 1] != 'E' && map[hero->yCharacter][(hero->xCharacter) - 1] != 219)
			hero->xCharacter--;
		break;
	case 'd':
		if (map[hero->yCharacter][(hero->xCharacter)+1]!='E' && map[hero->yCharacter][(hero->xCharacter) + 1] != 219)
			hero->xCharacter++;
		break;
	case 's':
		if (map[(hero->yCharacter)+1][hero->xCharacter]!='E' && map[(hero->yCharacter) + 1][hero->xCharacter] != 219)
			hero->yCharacter++;
		break;
	}
}
