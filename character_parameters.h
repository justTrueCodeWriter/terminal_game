#pragma once

struct Character {
	int health, damage, gold;
	int xCharacter = 120/2, yCharacter = 40/2;
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
