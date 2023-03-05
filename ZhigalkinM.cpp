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

struct Weapon {
	int damage;
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

void AppleStats(Apple arrayApple[1]) {
	for (int i = 0; i < 1; i++) {
		arrayApple[i].heal = 10;
	}
}

void HealingPotionStats(HealingPotion arrayHealingPotion[1]) {
	for (int i = 0; i < 1; i++) {
		arrayHealingPotion[i].heal = 25;
	}
}

void Weapon1Stats(Weapon weapon1[1]) {
	for (int i = 0; i < 1; i++) {
		weapon1[i].damage = 5;
	}
}

void CharacterUpgradeWeapon(Character arrayCharacter[1], Weapon weapon1[1]) {
	int IndexWeapon = 1;
	switch (IndexWeapon) {
	case 1:
		for (int i = 0; i < 1; i++) {
			arrayCharacter[i].damage += weapon1[i].damage;
		}
		printf("Your damage has been increased by %d\n", weapon1->damage); Sleep(500);
		printf("Your current damage is %d\n", arrayCharacter->damage); Sleep(500);
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

void Healing(Character arrayCharacter[1], Apple arrayApple[1], HealingPotion arrayHealingPotion[1]) {
	int IndexHealing = 1;
	switch (IndexHealing) {
	case 1:
		for (int i = 0; i < 1; i++) {
			arrayCharacter[i].health += arrayApple[i].heal;
			printf("You are healed for %d\n", arrayApple->heal); Sleep(500);
			printf("Your health is %d\n", arrayCharacter->health); Sleep(500);
		}
		break;
	case 2:
		for (int i = 0; i < 1; i++) {
			arrayCharacter[i].health += arrayHealingPotion[i].heal;
			printf("You are healed for %d\n", arrayHealingPotion->heal); Sleep(500);
			printf("Your health is %d\n", arrayCharacter->health); Sleep(500);
		}
		break;
	}
}

int main() {
	Character arrayCharacter[1];
	Enemy arrayEnemy[1];
	Boss arrayBoss[1];
	DungeonEnemy arrayDungeonEnemy[1];
	Apple arrayApple[1];
	HealingPotion arrayHealingPotion[1];
	Weapon weapon1[1];
	/*system("cls");*/
	/*printf("\a");*/
	CharacterStats(arrayCharacter);
	EnemyStats(arrayEnemy);
	BossStats(arrayBoss);
	DungeonEnemyStats(arrayDungeonEnemy);
	AppleStats(arrayApple);
	HealingPotionStats(arrayHealingPotion);
	Weapon1Stats(weapon1);
	/*Battle(arrayCharacter, arrayEnemy, arrayBoss, arrayDungeonEnemy);*/

	/*Healing(arrayCharacter, arrayApple, arrayHealingPotion);*/

	CharacterUpgradeWeapon(arrayCharacter, weapon1);

	/*for (int i = 0; i < 1; i++) {
		printf("%d %d %d %d %d", array_1[i].health, array_1[i].damage, array_1[i].shield, array_1[i].gold, array_1[i].totalHP);
	}*/
}