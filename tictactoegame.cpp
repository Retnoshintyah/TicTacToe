#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

char board[3][3];
const char PLAYER = 'X';
const char COMPUTER = 'O';


void clearBoard()
{
	for(int i=0; i<3; i++)
	{
		for(int j=0; j<3; j++)
		{
			board[i][j] = ' ';
		}
	}
}

void displayBoard()
{
	printf("==============\n");
	printf("| %c | %c | %c |\n", board[0][0], board[0][1], board[0][2]);
	printf("|---|---|---|\n");
	printf("| %c | %c | %c |\n", board[1][0], board[1][1], board[1][2]);
	printf("|---|---|---|\n");
	printf("| %c | %c | %c |\n", board[2][0], board[2][1], board[2][2]);
	printf("==============");
	puts("");
}

int checkFreeSpaces()
{
	int freeSpaces = 9;
	
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			if(board[i][j] != ' '){
				freeSpaces--;
			}
		}
	}
	
	return freeSpaces;
}

void playerMove()
{
	int row;
	int col;
	
	do{
		printf("Enter row 1-3: ");
		scanf("%d", &row);
		row--;
		
		printf("Enter colomn 1-3: ");
		scanf("%d", &col);
		col--;
		
		if(board[row][col] != ' ')
		{
			puts("Oops the board is already filled");
		}
		
		else
		{
			board[row][col] = PLAYER;
			break;
		}
	}while(board[row][col] != ' ');
	
}

void computerMove()
{
	srand(time(0));
	int row;
	int col;
	
	if(checkFreeSpaces() > 0)
	{
		do{
			row = rand()%3;
			col = rand()%3;
		}while(board[row][col] != ' ');
		
		board[row][col] = COMPUTER;
	}
	
	else{
		return;
	}
	
	return;
}

char checkWinner()
{
	//check rows
	for(int i=0; i<3; i++)
	{
		if(board[i][0] == board[i][1] && board[i][0] == board[i][2])
		{
			return board[i][0];
		}
	}
	
	//check coloumn
	for(int i=0; i<3; i++)
	{
		if(board[0][i] == board[1][i] && board[0][i] == board[2][i])
		{
			return board[0][i];
		}
	}
	
	//check diagonal
	if(board[0][0] == board[1][1] && board[0][0] == board[2][2])
	{
		return board[0][0];
	}
	
	if(board[0][2] == board[1][1] && board[0][2] == board[2][0])
	{
		return board[0][2];
	}
	
	return ' ';
}

void displayWinner(char winner)
{
	if(winner == PLAYER)
	{
		puts("YOU WIN");
	}
	else if(winner == COMPUTER)
	{
		puts("YOU LOSE");
	}
	else if(winner == ' ')
	{
		puts("IT'S TIE");
	}
	
}

int main()
{
	char winner = ' ';
	char play = 'Y';
	
	puts("WELCOME TO TIC TAC TOE GAME");
	
	do{
		winner = ' ';
		play = ' ';
		clearBoard();
		
		while(winner == ' ' && checkFreeSpaces() != 0)
		{
			displayBoard();
			
			playerMove();
			winner = checkWinner();
			if(winner != ' ' || checkFreeSpaces == 0){
				break;
			}
			
			
			computerMove();
			winner = checkWinner();
			if(winner != ' ' || checkFreeSpaces == 0){
				break;
			}
		}
	
		displayBoard();
		displayWinner(winner);
		
		printf("\nWanna Play Again? (Y|N) >> "); getchar();
		scanf("%c", &play); 
		play = toupper(play);
		
	} while(play == 'Y');
	
	puts("Thanks For Playing");
	
	return 0;
	
}

