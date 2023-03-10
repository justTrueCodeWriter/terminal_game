#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <math.h>

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

#include "character_parameters.h"
#include "fight.h"
#include "trade.h"

const int x = SCREEN_WIDTH, y = SCREEN_HEIGHT;

int map[y][x];
bool game = true;
int difficultyWaveCount = 1;

Character hero[1];
Healing heal[1];
Treasure chest[1];
Enemy villian[1];
DungeonEnemy arrayDungeonEnemy[1];
Boss arrayBoss[1];

Healing arrayHealing[1];

void Menu();
void draw_map();
void characterMoves();
void GetMap();
void ViewInventoryOnTheButton();
void SaveFile();
void BinaryFileOutput();
void InteractionWithTheChest();
void enemy_activation();

void wasted();

int main() {
	srand(NULL);
	Menu();
	GetMap();
	EnemyStats(villian);
	BossStats(arrayBoss);
	hero[0].inventory = 1;
	DungeonEnemyStats(arrayDungeonEnemy);
	do {
		draw_map();
		printf("\n");
		enemy_activation();
		characterMoves();
		system("cls");
		IncreaseDifficulty(hero->steps, difficultyWaveCount, villian, arrayBoss, arrayDungeonEnemy);
	} while (game == true);
}

void GetMap() {
	FILE* m;

	if (fopen_s(&m, "map_4.txt", "rt") != 0) {
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

			else if (map[hero->yCharacter][hero->xCharacter] == 'A') {
				map[hero->yCharacter][hero->xCharacter] = ' ';
				CharacterHealing(1, hero, arrayHealing);
			}

			else if (map[hero->yCharacter][hero->xCharacter] == 'T') {
				map[hero->yCharacter][hero->xCharacter] = ' ';
				InteractionWithTheChest();
			}

			else if (map[hero->yCharacter][hero->xCharacter] == '$') {
				TradingWindow(hero);
				hero->yCharacter = hero->yCharacter - 2;

			}
			printf("%c", map[i][j]);
			if (isCharacterMove == 1)
				map[i][j] = ' ';
		}
	}
	printf("\nHealth: %d | Damage: %d", hero->health, hero->damage);
	printf("\nGold: %d | Steps: %d", hero->gold, hero->steps);
	printf("\nDifficulty Wave: %d", difficultyWaveCount - 1);
}

void enemy_activation() {
	int IndexEnemy = 0;
	char death;

	if (map[(hero->yCharacter) - 1][hero->xCharacter] == 'E' || map[hero->yCharacter][(hero->xCharacter) - 1] == 'E' ||
		map[hero->yCharacter][(hero->xCharacter) + 1] == 'E' || map[(hero->yCharacter) + 1][hero->xCharacter] == 'E' ||
		map[hero->yCharacter][hero->xCharacter] == 'E')
		IndexEnemy = 1;
	else if (map[(hero->yCharacter) - 1][hero->xCharacter] == 'B' || map[hero->yCharacter][(hero->xCharacter) - 1] == 'B' ||
		map[hero->yCharacter][(hero->xCharacter) + 1] == 'B' || map[(hero->yCharacter) + 1][hero->xCharacter] == 'B' ||
		map[hero->yCharacter][hero->xCharacter] == 'B')
		IndexEnemy = 2;
	else if (map[(hero->yCharacter) - 1][hero->xCharacter] == 'D' || map[hero->yCharacter][(hero->xCharacter) - 1] == 'D' ||
		map[hero->yCharacter][(hero->xCharacter) + 1] == 'D' || map[(hero->yCharacter) + 1][hero->xCharacter] == 'D' || map[hero->yCharacter][hero->xCharacter] == 'D') IndexEnemy = 3;
	printf("\n");

	death = Battle(IndexEnemy, hero, villian, arrayBoss, arrayDungeonEnemy);

	if (map[(hero->yCharacter) - 1][hero->xCharacter] == death || map[hero->yCharacter][(hero->xCharacter) - 1] == death ||
		map[hero->yCharacter][(hero->xCharacter) + 1] == death || map[(hero->yCharacter) + 1][hero->xCharacter] == death ||
		map[hero->yCharacter][hero->xCharacter] == death) {
		map[(hero->yCharacter) - 1][hero->xCharacter] = ' ';
		map[hero->yCharacter][(hero->xCharacter) - 1] = ' ';
		map[hero->yCharacter][(hero->xCharacter) + 1] = ' ';
		map[(hero->yCharacter) + 1][hero->xCharacter] = ' ';
		EnemyStats(villian);
		BossStats(arrayBoss);
		DungeonEnemyStats(arrayDungeonEnemy);

		IncreaseDifficulty(hero->steps, difficultyWaveCount, villian, arrayBoss, arrayDungeonEnemy);
	}
	if (death == 'B')
		map[(hero->yCharacter) + 3][(hero->xCharacter) + 3] = 'T';

	else if (death == '@') {
		wasted();
	}

}
void inventory(int viewingInv) {
	if (viewingInv == 1) hero[0].health += 10; //Apple
	if (viewingInv == 2) hero[0].health += 25; //Healing Potion
	if (viewingInv == 3) hero[0].damage = 12;  //Iron Sword
	if (viewingInv == 4) hero[0].damage = 25;  //Steel Sword
	if (viewingInv == 5) hero[0].health += 28; // Iron Armor
	if (viewingInv == 6) hero[0].health += 45; // Steel Armor;
}

void characterMoves() {
	int viewingInv = 0, inv;
	inv = hero[0].inventory;
	if (inv < 10) inv = inv * 10;
	if (inv < 100) inv = inv * 10;
	switch (_getch()) {
	case 'z':
		SaveFile();
		system("cls");
		system("\npause");
		game = false;
		break;
	case 'w':
		if (((map[(hero->yCharacter) - 1][hero->xCharacter] != 219) &&
			(map[(hero->yCharacter) - 1][hero->xCharacter] != 'E') &&
			(map[(hero->yCharacter) - 1][hero->xCharacter] != 'B') && 
			(map[(hero->yCharacter) - 1][hero->xCharacter] != 'D') && 
			(map[(hero->yCharacter) - 1][hero->xCharacter] != '|')))
			hero->yCharacter--;
		hero->steps++;
		break;
	case 'a':
		if (((map[hero->yCharacter][(hero->xCharacter)-1] != 219) && 
			(map[hero->yCharacter][(hero->xCharacter)-1] != 'E') && 
			(map[hero->yCharacter][(hero->xCharacter)-1] != 'B') &&
			(map[hero->yCharacter][(hero->xCharacter)-1] != 'D') && 
			(map[hero->yCharacter][(hero->xCharacter)-1] != '|')))
			hero->xCharacter--;
		hero->steps++;
		break;
	case 'd':
		if (((map[hero->yCharacter][(hero->xCharacter)+1] != 219) && 
			(map[hero->yCharacter][(hero->xCharacter)+1] != 'E') && 
			(map[hero->yCharacter][(hero->xCharacter)+1] != 'B') &&
			(map[hero->yCharacter][(hero->xCharacter)+1] != 'D') && 
			(map[hero->yCharacter][(hero->xCharacter)+1] != '|')))
			hero->xCharacter++;
		hero->steps++;
		break;
	case 's':
		if (((map[(hero->yCharacter) + 1][hero->xCharacter] != 219) && 
			(map[(hero->yCharacter) + 1][hero->xCharacter] != 'E') && 
			(map[(hero->yCharacter) + 1][hero->xCharacter] != 'B') &&
			(map[(hero->yCharacter) + 1][hero->xCharacter] != 'D') && 
			(map[(hero->yCharacter) + 1][hero->xCharacter] != '|')))
			hero->yCharacter++;
		hero->steps++;
		break;
	case '1':
		viewingInv = inv / 100;
		hero[0].inventory = hero[0].inventory % 100; if (hero[0].inventory == 1) hero[0].inventory = 0; inventory(viewingInv);
		break;
	case '2':
		viewingInv = (inv / 10) % 10;
		hero[0].inventory = hero[0].inventory % 10 + hero[0].inventory / 100 * 10; inventory(viewingInv); break;
	case '3':
		viewingInv = inv % 10;
		hero[0].inventory = hero[0].inventory / 10; inventory(viewingInv); break;
	case 'v':
		ViewInventoryOnTheButton(); break;
	}
}
void ViewInventoryOnTheButton()
{
	system("cls");
	printf("Your inventory:\n");
	int viewingInv, inv = hero[0].inventory;
	for (int i = 1; i < 3; i++)
	{
		viewingInv = inv % 10;
		inv = inv / 10;
		if (viewingInv == 1) printf("%d)Apple\n", i);
		if (viewingInv == 2) printf("%d)Healing Potion\n", i);
		if (viewingInv == 3) printf("%d)Iron Sword\n", i);
		if (viewingInv == 4) printf("%d)Steel Sword\n", i);
		if (viewingInv == 5) printf("%d)Iron Armor\n", i);
		if (viewingInv == 6) printf("%d)Steel Armor\n", i);
		if (viewingInv == 0) break;
	}
	_getch();
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
	fwrite(&difficultyWaveCount, sizeof(int), 1, printBinary);
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
	fread(&difficultyWaveCount, sizeof(int), 1, output);
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
		break;
	case 2:
		hero->xCharacter = hero->xCharacter + 1;
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

void wasted() {
	system("cls");

	FILE* wasted;

	if (fopen_s(&wasted, "wasted.txt", "r") != 0) {
		printf("FILE COULDNT OPEN\n");
		exit(1);
	}
	int text[6][55];

	for (int i = 0; i < 6; i++)
		for (int j = 0; j < 55; j++)
			fscanf_s(wasted, "%c", &text[i][j]);

	for (int i = 0; i < 6; i++)
		for (int j = 0; j < 55; j++)
			printf("%c", text[i][j]);
	Sleep(3000);
	exit(1);
}
