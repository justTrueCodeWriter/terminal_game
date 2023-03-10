#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <math.h>

#include "character_parameters.h"
#include "fight.h"

const int x = SCREEN_WIDTH, y = SCREEN_HEIGHT;

int map[y][x];
bool game = true;

Character hero[1];
Healing heal[1];
Treasure chest[1];
Enemy villian[1];
DungeonEnemy arrayDungeonEnemy[1];
Boss arrayBoss[1];

void Menu();
void draw_map(); 
void characterMoves(); 
void GetMap();
void SaveFile();
void BinaryFileOutput();
void InteractionWithTheChest();
void enemy_activation();

int main() {
	srand(NULL);
	Menu();
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
			int isWall = 0;
			if (j == hero->xCharacter and i == hero->yCharacter) {
				map[i][j] = '@';
				isCharacterMove = 1;
			}
			if (i == chest->yChest and j == chest->xChest) {
				map[i][j] = 'T';
			}
			if (hero->xCharacter == chest->xChest and hero->yCharacter == chest->yChest) {
				InteractionWithTheChest();
			}
			printf("%c", map[i][j]);
			if (isCharacterMove == 1)
				map[i][j] = ' ';
		}
	}
	printf("\nhealth: %d", hero->health);
	printf("\ndamage: %d", hero->damage);
	printf("\ngold: %d", hero->gold);
	printf("\nsteps: %d", hero->steps);
}

void enemy_activation() {
	int IndexEnemy = 0;

	if (map[(hero->yCharacter) - 1][hero->xCharacter] == 'E' || map[hero->yCharacter][(hero->xCharacter) - 1] == 'E' ||
		map[hero->yCharacter][(hero->xCharacter) + 1] == 'E' || map[(hero->yCharacter) + 1][hero->xCharacter] == 'E' ||
		map[hero->yCharacter][hero->xCharacter] == 'E')
		IndexEnemy = 1;
	else if (map[(hero->yCharacter) - 1][hero->xCharacter] == 'B' || map[hero->yCharacter][(hero->xCharacter) - 1] == 'B' ||
		map[hero->yCharacter][(hero->xCharacter) + 1] == 'B' || map[(hero->yCharacter) + 1][hero->xCharacter] == 'B' ||
		map[hero->yCharacter][hero->xCharacter] == 'B')
		IndexEnemy = 2;
	else if (map[(hero->yCharacter) - 1][hero->xCharacter] == 'D' || map[hero->yCharacter][(hero->xCharacter) - 1] == 'D' ||
		map[hero->yCharacter][(hero->xCharacter) + 1] == 'D' || map[(hero->yCharacter) + 1][hero->xCharacter] == 'D' ||
		map[hero->yCharacter][hero->xCharacter] == 'D')
		IndexEnemy = 3;

	printf("\n");
	EnemyStats(villian);
	BossStats(arrayBoss);
	DungeonEnemyStats(arrayDungeonEnemy);

	Battle(IndexEnemy, hero, villian, arrayBoss, arrayDungeonEnemy);
}

void characterMoves() {
	switch (_getch()) {
	case 'z':
		SaveFile();
		system("cls");
		system("\npause");
		game = false;
		break;
	case 'w':
		if (map[(hero->yCharacter) - 1][hero->xCharacter] != 'E' && map[(hero->yCharacter) - 1][hero->xCharacter] != 219)
			hero->yCharacter--;
		hero->steps++;
		break;
	case 'a':
		if (map[hero->yCharacter][(hero->xCharacter) - 1] != 'E' && map[hero->yCharacter][(hero->xCharacter) - 1] != 219)
			hero->xCharacter--;
		hero->steps++;
		break;
	case 'd':
		if (map[hero->yCharacter][(hero->xCharacter)+1]!='E' && map[hero->yCharacter][(hero->xCharacter) + 1] != 219)
			hero->xCharacter++;
		hero->steps++;
		break;
	case 's':
		if (map[(hero->yCharacter)+1][hero->xCharacter]!='E' && map[(hero->yCharacter) + 1][hero->xCharacter] != 219)
			hero->yCharacter++;
		hero->steps++;
		break;
	}
}


void SaveFile() {
	FILE* printBinary = NULL;
	if (fopen_s(&printBinary, "save.bin", "wb") != NULL) {
		printf("\nError opening file");
			exit(1);
	}
	fwrite(&hero->health, sizeof(int), 1, printBinary);
	fwrite(&hero->damage, sizeof(int), 1, printBinary);
	fwrite(&hero->gold, sizeof(int), 1, printBinary);
	fwrite(&hero->steps, sizeof(int), 1, printBinary);
	fclose(printBinary);
}

void BinaryFileOutput() {
	FILE* output = NULL;
	if (fopen_s(&output, "save.bin", "rb") != NULL) {
		printf("\nNo saves\n");
		exit(1);
	}
	fread(&hero->health, sizeof(int), 1, output);
	fread(&hero->damage, sizeof(int), 1, output);
	fread(&hero->gold, sizeof(int), 1, output);
	fread(&hero->steps, sizeof(int), 1, output);
	fclose(output);
}

void InteractionWithTheChest() {
	system("cls");
	int switcher = 0;
	do {
		printf("Do you want to open the chest?\n"); printf("1 - Yes\n2 - No\n"); scanf_s("%d", &switcher);
	} while (switcher > 3 or switcher < 1);
	system("cls");
	switch (switcher) {
	case 1:
		hero->gold += chest->gold;
		printf("%d gold received\n", chest->gold); Sleep(520);
		system("cls");
		chest->xChest = -1; chest->yChest = -1;
		break;
	case 2:
		hero->xCharacter = chest->xChest + 1;
		break;
	}
}

void Menu() {
	int selection;
	printf("\tRoguelike Game\n\n");
	printf("\t1: New game\n");
	printf("\t2: Continue game\n");
	printf("\t3: Exit game\n");
	do {
		printf("Choose to start the game or continue or exit\n");
		printf("Please note that if you start the game again, the data will be overwritten\n");
		scanf_s("%d", &selection);
	} while (selection < 1 or selection > 4);
	system("cls");
	if (selection == 1) {
		Character hero[1];
	}
	if (selection == 2) {
		BinaryFileOutput();
	}
	if (selection == 3) {
		exit(1);
	}
}