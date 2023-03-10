#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>

#include "character_parameters.h"

void CharacterStats(Character arrayCharacter[1]) {
	for (int i = 0; i < 1; i++) {
		arrayCharacter[i].health = 30;
		arrayCharacter[i].damage = 4;
		arrayCharacter[i].gold = 0;
	}
}

void EnemyStats(Enemy arrayEnemy[1]) {
	for (int i = 0; i < 1; i++) {
		arrayEnemy[i].health = 7;
		arrayEnemy[i].damage = 3;
		arrayEnemy[i].gold = 10;
	}
}

void BossStats(Boss arrayBoss[1]) {
	for (int i = 0; i < 1; i++) {
		arrayBoss[i].health = 70;
		arrayBoss[i].damage = 20;
		arrayBoss[i].gold = 50;
	}
}

void DungeonEnemyStats(DungeonEnemy arrayDungeonEnemy[1]) {
	for (int i = 0; i < 1; i++) {
		arrayDungeonEnemy[i].health = 12;
		arrayDungeonEnemy[i].damage = 6;
		arrayDungeonEnemy[i].gold = 20;
	}
}

void CharacterUpgradeWeapon(Character arrayCharacter[1], Weapon arrayWeapon[1]) {
	int IndexWeapon = 3;
	switch (IndexWeapon) {
	case 1:
		for (int i = 0; i < 1; i++) {
			arrayCharacter[i].damage += arrayWeapon[i].weapon_1;
		}
		printf("Your damage has been increased by %d\n", arrayWeapon->weapon_1); Sleep(500);
		printf("Your current damage is %d\n", arrayCharacter->damage); Sleep(500);
		break;
	case 2:
		for (int i = 0; i < 1; i++) {
			arrayCharacter[i].damage += arrayWeapon[i].weapon_2;
		}
		printf("Your damage has been increased by %d\n", arrayWeapon->weapon_2); Sleep(500);
		printf("Your current damage is %d\n", arrayCharacter->damage); Sleep(500);
		break;
	case 3:
		for (int i = 0; i < 1; i++) {
			arrayCharacter[i].damage += arrayWeapon[i].weapon_3;
		}
		printf("Your damage has been increased by %d\n", arrayWeapon->weapon_3); Sleep(500);
		printf("Your current damage is %d\n", arrayCharacter->damage); Sleep(500);
		break;
	}
}

void CharacterUpgradeArmor(Character arrayCharacter[1], Armor arrayArmor[1]) {
	int IndexArmor = 3;
	switch (IndexArmor) {
	case 1:
		for (int i = 0; i < 1; i++) {
			arrayCharacter[i].health += arrayArmor[i].armor_1;
		}
		printf("Your health has been increased by %d\n", arrayArmor->armor_1); Sleep(500);
		printf("Your current health is %d\n", arrayCharacter->health); Sleep(500);
		break;
	case 2:
		for (int i = 0; i < 1; i++) {
			arrayCharacter[i].health += arrayArmor[i].armor_2;
		}
		printf("Your health has been increased by %d\n", arrayArmor->armor_2); Sleep(500);
		printf("Your current health is %d\n", arrayCharacter->health); Sleep(500);
		break;
	case 3:
		for (int i = 0; i < 1; i++) {
			arrayCharacter[i].health += arrayArmor[i].armor_3;
		}
		printf("Your health has been increased by %d\n", arrayArmor->armor_3); Sleep(500);
		printf("Your current health is %d\n", arrayCharacter->health); Sleep(500);
		break;
	}
}

char BattleWithEnemy(Character arrayCharacter[1], Enemy arrayEnemy[1]) {
	while(arrayCharacter->health > 0 && arrayEnemy->health > 0) {
		arrayEnemy->health = arrayEnemy->health - arrayCharacter->damage;
		printf("You dealt %d damage to an enemy\n", arrayCharacter->damage); Sleep(500);
		printf("Enemy HP %d\n", arrayEnemy->health); Sleep(500);
		if (arrayEnemy->health < 1) {
			arrayCharacter->gold += arrayEnemy->gold;
			printf("You have defeated the enemy\n");
			printf("You received %d gold\n", arrayEnemy->gold);
			return 'E';
		}
		if (arrayCharacter->health < 1) {
			printf("Your character is dead\n");
			return '@';
		}
		arrayCharacter->health = arrayCharacter->health - arrayEnemy->damage;
		printf("You have been damaged by %d\n", arrayEnemy->damage); Sleep(500);
		printf("Your HP is %d\n", arrayCharacter->health); Sleep(500);
		if (arrayEnemy->health < 1) {
			arrayCharacter->gold += arrayEnemy->gold;
			printf("You received %d gold\n", arrayEnemy->gold);
			return 'E';
		}
		if (arrayCharacter->health < 1) {
			printf("Your character is dead\n");
			return '@';
		}
	}

}

char BattleWithBoss(Character arrayCharacter[1], Boss arrayBoss[1]) {
	while (arrayCharacter->health > 0 && arrayBoss->health > 0) {
		arrayBoss->health = arrayBoss->health - arrayCharacter->damage;
		printf("You dealt %d damage to an enemy\n", arrayCharacter->damage); Sleep(500);
		printf("Enemy HP %d\n", arrayBoss->health); Sleep(500);
		if (arrayBoss->health < 1) {
			arrayCharacter->gold += arrayBoss->gold;
			printf("You have defeated the enemy\n");
			printf("You received %d gold\n", arrayBoss->gold);
			return 'B';
		}
		if (arrayCharacter->health < 1) {
			printf("Your character is dead\n");
			return '@';
		}
		arrayCharacter->health = arrayCharacter->health - arrayBoss->damage;
		printf("You have been damaged by %d\n", arrayBoss->damage); Sleep(500);
		printf("Your HP is %d\n", arrayCharacter->health); Sleep(500);
		if (arrayBoss->health < 1) {
			arrayCharacter->gold += arrayBoss->gold;
			printf("You received %d gold\n", arrayBoss->gold);
			return 'B';
		}
		if (arrayCharacter->health < 1) {
			printf("Your character is dead\n");
			return '@';
		}
	}
}

char BattleWithDungeonEnemy(Character arrayCharacter[1], DungeonEnemy arrayDungeonEnemy[1]) {
	while (arrayCharacter->health > 0 && arrayDungeonEnemy->health > 0) {
		arrayDungeonEnemy->health = arrayDungeonEnemy->health - arrayCharacter->damage;
		printf("You dealt %d damage to an enemy\n", arrayCharacter->damage); Sleep(500);
		printf("Enemy HP %d\n", arrayDungeonEnemy->health); Sleep(500);
		if (arrayDungeonEnemy->health < 1) {
			arrayCharacter->gold += arrayDungeonEnemy->gold;
			printf("You have defeated the enemy\n");
			printf("You received %d gold\n", arrayDungeonEnemy->gold);
			return 'D';
		}
		if (arrayCharacter->health < 1) {
			printf("Your character is dead\n");
			return '@';
		}
		arrayCharacter->health = arrayCharacter->health - arrayDungeonEnemy->damage;
		printf("You have been damaged by %d\n", arrayDungeonEnemy->damage); Sleep(500);
		printf("Your HP is %d\n", arrayCharacter->health); Sleep(500);
		if (arrayDungeonEnemy->health < 1) {
			arrayCharacter->gold += arrayDungeonEnemy->gold;
			printf("You received %d gold\n", arrayDungeonEnemy->gold);
			return 'D';
		}
		if (arrayCharacter->health < 1) {
			printf("Your character is dead\n");
			return '@';
		}
	}
}

char Battle(int IndexEnemy, Character arrayCharacter[1], Enemy arrayEnemy[1], Boss arrayBoss[1], DungeonEnemy arrayDungeonEnemy[1]) {
	char death;
	switch (IndexEnemy) {
	case(1):
		death = BattleWithEnemy(arrayCharacter, arrayEnemy);
		return death;

	case (2):
		death = BattleWithBoss(arrayCharacter, arrayBoss);
		return death;
	case (3):
		death = BattleWithDungeonEnemy(arrayCharacter, arrayDungeonEnemy);
		return death;
	}
}

void CharacterHealing(int IndexHealing, Character arrayCharacter[1], Healing arrayHealing[1]) {
	switch (IndexHealing) {
	case 1:
			arrayCharacter->health += arrayHealing->Apple;
			printf("You are healed for %d\n", arrayHealing->Apple); Sleep(500);
			printf("Your health is %d\n", arrayCharacter->health); Sleep(500);
			break;
	case 2:
			arrayCharacter->health += arrayHealing->HealingPotion;
			printf("You are healed for %d\n", arrayHealing->HealingPotion); Sleep(500);
			printf("Your health is %d\n", arrayCharacter->health); Sleep(500);
			break;
	}
}

void IncreaseDifficulty(int NumberOfSteps, int &difficultyWaveCount, Enemy arrayEnemy[1], Boss arrayBoss[1], DungeonEnemy arrayDungeonEnemy[1]) {
	if (NumberOfSteps != 0 && NumberOfSteps % 100 == 0) {
		printf("Difficulty has been increased\n");
		Sleep(3000);
		for (int i = 0; i < 1; i++) {
			arrayEnemy[i].health *= 1.5*difficultyWaveCount;
			arrayEnemy[i].damage *= 1.5*difficultyWaveCount;
			arrayEnemy[i].gold *= 1.5*difficultyWaveCount;
		}
		for (int i = 0; i < 1; i++) {
			arrayBoss[i].health *= 1.5*difficultyWaveCount;
			arrayBoss[i].damage *= 1.5*difficultyWaveCount;
			arrayBoss[i].gold *= 1.5*difficultyWaveCount;
		}
		for (int i = 0; i < 1; i++) {
			arrayDungeonEnemy[i].health *= 1.5*difficultyWaveCount;
			arrayDungeonEnemy[i].damage *= 1.5*difficultyWaveCount;
			arrayDungeonEnemy[i].gold *= 1.5*difficultyWaveCount;
		}
		difficultyWaveCount++;
	}
}

#if 0
int main() {
	Character arrayCharacter[1];
	Enemy arrayEnemy[1];
	Boss arrayBoss[1];
	DungeonEnemy arrayDungeonEnemy[1];
	Healing arrayHealing[1];
	Weapon arrayWeapon[1];
	Armor arrayArmor[1];
	/*system("cls");*/
	/*printf("\a");*/
	CharacterStats(arrayCharacter);
	EnemyStats(arrayEnemy);
	BossStats(arrayBoss);
	DungeonEnemyStats(arrayDungeonEnemy);
	IncreaseDifficulty(arrayEnemy, arrayBoss, arrayDungeonEnemy);
	for (int i = 0; i < 1; i++) {
		printf("%d %d %d  -  Enemy\n", arrayEnemy[i].health, arrayEnemy[i].damage, arrayEnemy[i].gold);
		printf("%d %d %d  -  Boss\n", arrayBoss[i].health, arrayBoss[i].damage, arrayBoss[i].gold);
		printf("%d %d %d  -  DungeonEnemy\n", arrayDungeonEnemy[i].health, arrayDungeonEnemy[i].damage, arrayDungeonEnemy[i].gold);
	}

	/*Weapon1Stats(weapon1);*/
	/*Battle(arrayCharacter, arrayEnemy, arrayBoss, arrayDungeonEnemy);*/

	/*CharacterHealing(arrayCharacter, arrayHealing);*/

	/*CharacterUpgradeWeapon(arrayCharacter, arrayWeapon);*/

	/*CharacterUpgradeArmor(arrayCharacter, arrayArmor);*/
}
#endif