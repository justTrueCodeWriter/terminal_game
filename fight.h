#pragma once

void EnemyStats(Enemy arrayEnemy[1]);
void BossStats(Boss arrayBoss[1]);
void DungeonEnemyStats(DungeonEnemy arrayDungeonEnemy[1]);
void IncreaseDifficulty(int NumberOfSteps, Enemy arrayEnemy[1], Boss arrayBoss[1], DungeonEnemy arrayDungeonEnemy[1]);

void Battle(int IndexEnemy, Character arrayCharacter[1], Enemy arrayEnemy[1], Boss arrayBoss[1], DungeonEnemy arrayDungeonEnemy[1]);
