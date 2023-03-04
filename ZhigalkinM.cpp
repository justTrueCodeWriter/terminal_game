#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>

struct Character {
	int health, damage, gold;
};

struct Enemy {
	int health, damage, gold;
};

struct Boss {
	int health, damage, gold;
};

struct DungeonEnemy {
	int health, damage, gold;
};

void CharacterStats(Character arrayCharacter[1]) {
	for (int i = 0; i < 1; i++) {
		arrayCharacter[i].health = 30;
		arrayCharacter[i].damage = 4;
		arrayCharacter[i].gold = 0;
	}
}

void EnemyStats(Enemy arrayEnemy[1]) {
	for (int i = 0; i < 1; i++) {
		arrayEnemy[i].health = 5;
		arrayEnemy[i].damage = 2;
		arrayEnemy[i].gold = 10;
	}
}

void BossStats(Boss arrayBoss[1]) {
	for (int i = 0; i < 1; i++) {
		arrayBoss[i].health = 30;
		arrayBoss[i].damage = 10;
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

void BattleWithEnemy(Character arrayCharacter[1], Enemy arrayEnemy[1]) {
		for (int i = 0; i < 1; i++) {
			arrayEnemy[i].health = arrayEnemy[i].health - arrayCharacter[i].damage;
			printf("You dealt %d damage to an enemy\n", arrayCharacter->damage); Sleep(500);
			printf("Enemy HP %d\n", arrayEnemy->health); Sleep(500);
			if (arrayEnemy[i].health < 1) {
				arrayCharacter[i].gold += arrayEnemy[i].gold;
				printf("You have defeated the enemy\n");
				printf("You received %d gold\n", arrayCharacter[i].gold);
				break;
			}
			if (arrayCharacter[i].health < 1) {
				printf("Your character is dead\n");
				break;
			}
			arrayCharacter[i].health = arrayCharacter[i].health - arrayEnemy[i].damage;
			printf("You have been damaged by %d\n", arrayEnemy->damage); Sleep(500);
			printf("Your HP is %d\n", arrayCharacter->health); Sleep(500);
			if (arrayEnemy[i].health < 1) {
				arrayCharacter[i].gold += arrayEnemy[i].gold;
				printf("You received %d gold\n", arrayCharacter[i].gold);
				break;
			}
			if (arrayCharacter[i].health < 1) {
				printf("Your character is dead\n");
				break;
			}
		}

}

void BattleWithBoss(Character arrayCharacter[1], Boss arrayBoss[1]) {
	for (int i = 0; i < 1; i++) {
		arrayBoss[i].health = arrayBoss[i].health - arrayCharacter[i].damage;
		printf("You dealt %d damage to an enemy\n", arrayCharacter->damage); Sleep(500);
		printf("Enemy HP %d\n", arrayBoss->health); Sleep(500);
		if (arrayBoss[i].health < 1) {
			arrayCharacter[i].gold += arrayBoss[i].gold;
			printf("You have defeated the enemy\n");
			printf("You received %d gold\n", arrayCharacter[i].gold);
			break;
		}
		if (arrayCharacter[i].health < 1) {
			printf("Your character is dead\n");
			break;
		}
		arrayCharacter[i].health = arrayCharacter[i].health - arrayBoss[i].damage;
		printf("You have been damaged by %d\n", arrayBoss->damage); Sleep(500);
		printf("Your HP is %d\n", arrayCharacter->health); Sleep(500);
		if (arrayBoss[i].health < 1) {
			arrayCharacter[i].gold += arrayBoss[i].gold;
			printf("You received %d gold\n", arrayCharacter[i].gold);
			break;
		}
		if (arrayCharacter[i].health < 1) {
			printf("Your character is dead\n");
			break;
		}
	}
}

void BattleWithDungeonEnemy(Character arrayCharacter[1], DungeonEnemy arrayDungeonEnemy[1]) {
	for (int i = 0; i < 1; i++) {
		arrayDungeonEnemy[i].health = arrayDungeonEnemy[i].health - arrayCharacter[i].damage;
		printf("You dealt %d damage to an enemy\n", arrayCharacter->damage); Sleep(500);
		printf("Enemy HP %d\n", arrayDungeonEnemy->health); Sleep(500);
		if (arrayDungeonEnemy[i].health < 1) {
			arrayCharacter[i].gold += arrayDungeonEnemy[i].gold;
			printf("You have defeated the enemy\n");
			printf("You received %d gold\n", arrayCharacter[i].gold);
			break;
		}
		if (arrayCharacter[i].health < 1) {
			printf("Your character is dead\n");
			break;
		}
		arrayCharacter[i].health = arrayCharacter[i].health - arrayDungeonEnemy[i].damage;
		printf("You have been damaged by %d\n", arrayDungeonEnemy->damage); Sleep(500);
		printf("Your HP is %d\n", arrayCharacter->health); Sleep(500);
		if (arrayDungeonEnemy[i].health < 1) {
			arrayCharacter[i].gold += arrayDungeonEnemy[i].gold;
			printf("You received %d gold\n", arrayCharacter[i].gold);
			break;
		}
		if (arrayCharacter[i].health < 1) {
			printf("Your character is dead\n");
			break;
		}
	}
}

void Battle(Character arrayCharacter[1], Enemy arrayEnemy[1], Boss arrayBoss[1], DungeonEnemy arrayDungeonEnemy[1]) {
	int switcher=3;
	switch (switcher) {
	case(1):
		BattleWithEnemy(arrayCharacter, arrayEnemy);
		break;

	case (2):
		BattleWithBoss(arrayCharacter, arrayBoss);
		break;
	case (3):
		BattleWithDungeonEnemy(arrayCharacter, arrayDungeonEnemy);
		break;
	}
}


int main() {
	Character arrayCharacter[1];
	Enemy arrayEnemy[1];
	Boss arrayBoss[1];
	DungeonEnemy arrayDungeonEnemy[1];
	/*system("cls");*/
	/*printf("\a");*/
	CharacterStats(arrayCharacter);
	EnemyStats(arrayEnemy);
	BossStats(arrayBoss);
	DungeonEnemyStats(arrayDungeonEnemy);
	Battle(arrayCharacter, arrayEnemy, arrayBoss, arrayDungeonEnemy);

	/*for (int i = 0; i < 1; i++) {
		printf("%d %d %d %d %d", array_1[i].health, array_1[i].damage, array_1[i].shield, array_1[i].gold, array_1[i].totalHP);
	}*/
}