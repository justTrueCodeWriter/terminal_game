#pragma once

void EnemyStats(Enemy arrayEnemy[1]);
void BossStats(Boss arrayBoss[1]);
void DungeonEnemyStats(DungeonEnemy arrayDungeonEnemy[1]);
void IncreaseDifficulty(int NumberOfSteps, int &difficultyWaveCount, Enemy arrayEnemy[1], Boss arrayBoss[1], DungeonEnemy arrayDungeonEnemy[1]);
void IncreaseStats(Enemy arrayEnemy[1], Boss arrayBoss[1], DungeonEnemy arrayDungeonEnemy[1]);

char Battle(int IndexEnemy, Character arrayCharacter[1], Enemy arrayEnemy[1], Boss arrayBoss[1], DungeonEnemy arrayDungeonEnemy[1]);
void CharacterHealing(int IndexHealing, Character arrayCharacter[1], Healing arrayHealing[1]);
