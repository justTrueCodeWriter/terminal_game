#pragma once

#define SCREEN_WIDTH 104
#define SCREEN_HEIGHT 43

struct Character {
	int health = 100, damage = 5, gold = 0, steps = 0, inventory = 0;
	int xCharacter = SCREEN_WIDTH/4, yCharacter = SCREEN_HEIGHT/4;
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

struct Treasure {
	int gold = 350;
};