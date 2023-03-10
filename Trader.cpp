#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <math.h>
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

void Full()
{
	printf_s("Your inventory is full");
}

void TradingWindow(Character arrayCharacter[1])
{
	int Choice = 0, Sale;
	printf("You have %d gold\n", arrayCharacter[0].gold);
	printf("Welcome to my store!\n1)Buy an item\n2)Sell an item\n3)Dice Game\n4)End the dialog\n");
	do
		scanf_s("%d", &Choice);
	while (Choice < 1 or Choice>3);
	if (Choice == 1)
	{

		printf("Here are my products:1)Apple - 5 gold\n2)Healing Potion - 10 gold\n3)Iron Sword - 30 gold\n4)Steel Sword - 60 gold\n5)Iron Armor - 30 gold\n6)Steel Armor - 60 gold\nChoose a product\n");
		do
			scanf_s("%d", &Choice);
		while (Choice < 1 or Choice>5);


		//List of products
		switch (Choice)
		{
		case 1: printf("Apple - 5 gold\n"); Sale = 5; Trading(arrayCharacter, Sale); break;
			if (arrayCharacter[0].inventory < 100000000) arrayCharacter[0].inventory = arrayCharacter[0].inventory * 10 + 1;
			else Full(); break;
		case 2: printf("Healing Potion - 10 gold\n"); Sale = 10; Trading(arrayCharacter, Sale); break;
			if (arrayCharacter[0].inventory < 100000000) arrayCharacter[0].inventory = arrayCharacter[0].inventory * 10 + 2;
			else Full(); break;
		case 3: printf("Iron Sword - 30 gold\n"); Sale = 30; Trading(arrayCharacter, Sale); //wearon_2
			if (arrayCharacter[0].inventory < 100000000) arrayCharacter[0].inventory = arrayCharacter[0].inventory * 10 + 3;
			else Full(); break; 
		case 4: printf("Steel Sword - 60 gold\n"); Sale = 60; Trading(arrayCharacter, Sale); break; //wearon_3
			if (arrayCharacter[0].inventory < 100000000) arrayCharacter[0].inventory = arrayCharacter[0].inventory * 10 + 4;
			else Full(); break;
		case 5: printf("Iron Armor - 30 gold\n"); Sale = 30; Trading(arrayCharacter, Sale); break; //armor_2
			if (arrayCharacter[0].inventory < 100000000) arrayCharacter[0].inventory = arrayCharacter[0].inventory * 10 + 5;
			else Full(); break;
		case 6: printf("Steel Armor - 60 gold\n"); Sale = 60; Trading(arrayCharacter, Sale); break; //armor_3
			if (arrayCharacter[0].inventory < 100000000) arrayCharacter[0].inventory = arrayCharacter[0].inventory * 10 + 6;
			else Full(); break;
		}
	};






	if (Choice == 2);
	{
		int s,k=0,ks;
		int inv = arrayCharacter[0].inventory;
		int viewingInv;
		printf("SELL\n");
		for (int i = 1; i < 3; i++)
			{
				viewingInv = inv % 10;
				inv = inv / 10;

				if (viewingInv == 1) printf("%d)Apple 5 gold\n", i);
				if (viewingInv == 2) printf("%d)Healing Potion - 10 gold\n", i);
				if (viewingInv == 3) printf("%d)Iron Sword - 30 gold\n", i);
				if (viewingInv == 4) printf("%d)Steel Sword - 60 gold\n", i);
				if (viewingInv == 5) printf("%d)Iron Armor - 30 gold\n", i);
				if (viewingInv == 6) printf("%d)Steel Armor - 60 gold\n", i);
				if (viewingInv == 0) break;
				k++;
			}
			printf("What do you want to sell?\n");
			scanf_s("%d", &s);
			while (s > 0)
			{
				k = s - k;
				ks = pow(10, k);
				inv = arrayCharacter[0].inventory % ks;
				viewingInv = (arrayCharacter[0].inventory / ks) % 10;
				arrayCharacter[0].inventory / (ks * 10) * ks + inv;
				if (viewingInv == 1) arrayCharacter[0].gold = arrayCharacter[0].gold+5;
				if (viewingInv == 2) arrayCharacter[0].gold = arrayCharacter[0].gold + 10;
				if (viewingInv == 3) arrayCharacter[0].gold = arrayCharacter[0].gold + 30;
				if (viewingInv == 4) arrayCharacter[0].gold = arrayCharacter[0].gold + 60;
				if (viewingInv == 5) arrayCharacter[0].gold = arrayCharacter[0].gold + 30;
				if (viewingInv == 6) arrayCharacter[0].gold = arrayCharacter[0].gold + 60;
				
			}
			

	}






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