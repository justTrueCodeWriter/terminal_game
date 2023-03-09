#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
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
	int Choice = 0, Sale;
	printf("You have %d gold\n", arrayCharacter[0].gold);
	printf("Welcome to my store!\n1)Buy an item\n2)Sell an item\n3)Dice Game\n4)End the dialog\n");
	do
		scanf_s("%d", Choice);
	while (Choice < 1 or Choice>3);
	if (Choice == 1)
	{

		printf("Here are my products:1)Healing Potion - 10 gold\n2)Iron Sword - 30 gold\n3)Steel Sword - 60 gold\n4)Iron Armor - 30 gold\n5)Steel Armor - 60 gold\nChoose a product\n");
		do
			scanf_s("%d", Choice);
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
	};
	if (Choice == 2);//SELL
	if (Choice == 3)
	{
		printf("Well, buddy, let's play. I think you know the rules. We roll the dice, the one with the most wins\n");
		Sleep(2);
		int TraderDice = rand() % 6 + 1, CharacterDice = rand() % 6 + 1;
		printf("You%d\n Trader%d\n", CharacterDice,TraderDice);
		if (TraderDice > CharacterDice) { printf("I won. Ahahaha\n"); }
		if (CharacterDice > TraderDice) { printf("You won...\n"); }
		if (CharacterDice == TraderDice) { printf("A draw, interesting\n"); }
	}
}