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

struct Apple {
	int heal;
};

struct HealingPotion {
	int heal;
};

struct Healing {
	int Apple /*healing*/ = 10;
	int HealingPotion /*healing*/ = 25;
};

struct Weapon {
	int weapon_1 /*damage*/ = 5;
	int weapon_2 /*damage*/ = 12;
	int weapon_3 /*damage*/ = 25;
};

struct Armor {
	int armor_1 /*health*/ = 15;
	int armor_2 /*health*/ = 28;
	int armor_3 /*health*/ = 45;
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
	int IndexEnemy=3;
	switch (IndexEnemy) {
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

void CharacterHealing(Character arrayCharacter[1], Healing arrayHealing[1]) {
	int IndexHealing = 1;
	switch (IndexHealing) {
	case 1:
		for (int i = 0; i < 1; i++) {
			arrayCharacter[i].health += arrayHealing[i].Apple;
			printf("You are healed for %d\n", arrayHealing->Apple); Sleep(500);
			printf("Your health is %d\n", arrayCharacter->health); Sleep(500);
		}
		break;
	case 2:
		for (int i = 0; i < 1; i++) {
			arrayCharacter[i].health += arrayHealing[i].HealingPotion;
			printf("You are healed for %d\n", arrayHealing->HealingPotion); Sleep(500);
			printf("Your health is %d\n", arrayCharacter->health); Sleep(500);
		}
		break;
	}
}

void IncreaseDifficulty(Enemy arrayEnemy[1], Boss arrayBoss[1], DungeonEnemy arrayDungeonEnemy[1]) {
	int NumberOfSteps = 100;
	if (NumberOfSteps == 100) {
		for (int i = 0; i < 1; i++) {
			arrayEnemy[i].health *= 2;
			arrayEnemy[i].damage *= 2;
			arrayEnemy[i].gold *= 2;
		}
		for (int i = 0; i < 1; i++) {
			arrayBoss[i].health *= 2;
			arrayBoss[i].damage *= 2;
			arrayBoss[i].gold *= 2;
		}
		for (int i = 0; i < 1; i++) {
			arrayDungeonEnemy[i].health *= 2;
			arrayDungeonEnemy[i].damage *= 2;
			arrayDungeonEnemy[i].gold *= 2;
		}
	}
}

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
	//Вывод характеристик мобов после увеличения сложности
	for (int i = 0; i < 1; i++) {
		printf("%d %d %d\n", arrayEnemy[i].health, arrayEnemy[i].damage, arrayEnemy[i].gold);
		printf("%d %d %d\n", arrayBoss[i].health, arrayBoss[i].damage, arrayBoss[i].gold);
		printf("%d %d %d\n", arrayDungeonEnemy[i].health, arrayDungeonEnemy[i].damage, arrayDungeonEnemy[i].gold);
	}

	/*Weapon1Stats(weapon1);*/
	/*Battle(arrayCharacter, arrayEnemy, arrayBoss, arrayDungeonEnemy);*/

	/*CharacterHealing(arrayCharacter, arrayHealing);*/

	/*CharacterUpgradeWeapon(arrayCharacter, arrayWeapon);*/

	/*CharacterUpgradeArmor(arrayCharacter, arrayArmor);*/
}