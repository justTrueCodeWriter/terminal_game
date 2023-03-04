#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>

struct Character {
	int health, damage, gold;
};

struct Enemy {
	int health, damage, gold;
};

void CharacterStats(Character array_1[1]) {
	for (int i = 0; i < 1; i++) {
		array_1[i].health = 30;
		array_1[i].damage = 4;
		array_1[i].gold = 0;
	}
}

void EnemyStats(Enemy array_2[1]) {
	for (int i = 0; i < 1; i++) {
		array_2[i].health = 5;
		array_2[i].damage = 2;
		array_2[i].gold = 10;
	}
}

void Battle(Character array_1[1], Enemy array_2[1]) {
	for (int i = 0; i < 1; i++) {
		array_2[i].health = array_2[i].health - array_1[i].damage;
		printf("You dealt %d damage to an enemy\n", array_1->damage); Sleep(500);
		printf("Enemy HP %d\n", array_2->health); Sleep(500);
		if (array_2[i].health < 1) {
			array_1[i].gold += array_2[i].gold;
			printf("You have defeated the enemy\n");
			printf("You received %d gold\n", array_1[i].gold);
			break;
		}
		if (array_1[i].health < 1) {
			printf("Your character is dead\n");
			break;
		}
		array_1[i].health = array_1[i].health - array_2[i].damage;
		printf("You have been damaged by %d\n", array_2->damage); Sleep(500);
		printf("Your HP is %d\n", array_1->health); Sleep(500);
		if (array_2[i].health < 1) {
			array_1[i].gold += array_2[i].gold;
			printf("You received %d gold\n", array_1[i].gold);
			break;
		}
		if (array_1[i].health < 1) {
			printf("Your character is dead\n");
			break;
		}
	}

}


int main() {
	Character array_1[1];
	Enemy array_2[1];
	system("chcp 1251");
	/*system("cls");*/
	/*printf("\a");*/
	CharacterStats(array_1);
	EnemyStats(array_2);
	Battle(array_1, array_2);

	/*for (int i = 0; i < 1; i++) {
		printf("%d %d %d %d %d", array_1[i].health, array_1[i].damage, array_1[i].shield, array_1[i].gold, array_1[i].totalHP);
	}*/
}