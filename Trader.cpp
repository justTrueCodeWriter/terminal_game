#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include "character_parameters.h"

void Trading(Character arrayCharacter[1], int Sale)
{
	if (arrayCharacter[0].gold >= Sale)
	{
		printf("Thanks for the purchase\n");
		arrayCharacter[0].gold = arrayCharacter[0].gold - Sale;
	}
	else (printf("You don't have enough gold to buy\n"));
}

void TradingWindow(Character arrayCharacter[1])
{
	printf("You have %d gold\n", arrayCharacter[0].gold);
	printf("Welcome to my store! Here are my products:\n");
	printf("1)Healing Potion - 10 gold\n2)Iron Sword - 30 gold\n3)Steel Sword - 60 gold\n4)Iron Armor - 30 gold\n5)Steel Armor - 60 gold\nChoose a product\n");
	int Choice = 0, Sale;
	do
		scanf("%d", Choice);
	while (Choice < 1 or Choice>5);


	//List of products
	switch (Choice)
	{
	case 1: printf("Healing Potion - 10 gold\n"); Sale = 10; Trading(arrayCharacter, Sale); break;
	case 2: printf("Iron Sword - 30 gold\n"); Sale = 30; Trading(arrayCharacter, Sale); break; //wearon_2
	case 3: printf("Steel Sword - 60 gold\n"); Sale = 60; Trading(arrayCharacter, Sale); break; //wearon_3
	case 4: printf("Iron Armor - 30 gold\n"); Sale = 30; Trading(arrayCharacter, Sale); break; //armor_2
	case 5: printf("Steel Armor - 60 gold\n"); Sale = 60; Trading(arrayCharacter, Sale); break; //armor_3
	}
}