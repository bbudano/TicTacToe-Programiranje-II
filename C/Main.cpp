#define _CRT_SECURE_NO_WARNINGS
#include "MyHeader.h"
#include <stdio.h>
#include <stdlib.h>

char symbol = 'X';
int count;

struct player
{
	char name[20];
	int score = 0;
};

int main(void) {
	
	struct player players[2];
	char newGame;
	count = 0;

	char *board = NULL;
	board = (char*)calloc(9, sizeof(char));

	printf("\n\t\t    Tic  Tac  Toe  v1.0\n");
	printf("Rules:\n-Manage to place three of YOUR symbols in a single row, column or diagonal to win\n");
	printf("-Winner of the previous round plays first on the next round\n\n");
	printf("Enter 'X' player's name:\n");
	scanf("%s", players[0].name);
	printf("Enter 'O' player's name:\n");
	scanf("%s", players[1].name);

	do
	{
		char board[9] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
		displayBoard(board);
		
		if (symbol == 'X')
		{
			printf("%s to play!\n", players[0].name);
		}
		else
		{
			printf("%s to play!\n", players[1].name);
		}
		while (1) {
			printf("Player 'X' : %s\n", players[0].name);
			printf("Player 'O' : %s\n", players[1].name);
			printf("\t\t\t\t%s - wins: %d\n", players[0].name, players[0].score);
			printf("\t\t\t\t%s - wins: %d\n",players[1].name, players[1].score);
			count++;
			input(board);
			displayBoard(board);
			if (winner(board) == 'X')
			{
				players[0].score++;
				printf("%s  TAKES THIS ROUND!\n", players[0].name);
				break;
			}
			else if (winner(board) == 'O')
			{
				players[1].score++;
				printf("%s  TAKES THIS ROUND!\n", players[1].name);
				break;
			}
			else if (winner(board) == '/' && count == 9)
			{
				printf("IT'S A DRAW!\n");
				break;
			}

			toggleSymbol();

			if (symbol == 'X')
			{
				printf("%s to play!\n", players[0].name);
			}
			else
			{
				printf("%s to play!\n", players[1].name);
			}
		}
		count = 0;
		printf("\nNEW GAME?\n\nPress [Y] to start a new game\n\t   OR\nPress [N] to end the game.\n");
		do {
			scanf(" %c", &newGame);
		} while (newGame != 'y' && newGame != 'Y' && newGame != 'n' && newGame != 'N');
	} while (newGame == 'y' || newGame == 'Y');

	if (newGame == 'n' || newGame == 'N') 
	{
		if (players[0].score > players[1].score)
		{
			printf("\t\t%s IS THE WINNER!!! :D\n", players[0].name);
		}
		else if(players[1].score > players[0].score)
		{
			printf("\t\t%s IS THE WINNER!!! :D\n", players[1].name);
		}
		else if (players[0].score == players[1].score)
		{
			printf("\t\tYOU ARE TIED! :)\n");
		}
	}

	return 0;
}