#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>

struct Move{
	int moveId;
	int position; 
	char mark; 
	struct Move * next; 
	struct Move * prev; 
};
char square[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};




void addMove(struct Move ** headRef, int moveId, int position, char mark){
	struct Move* newest = (struct Move*) malloc(sizeof(struct Move));
	newest->moveId = moveId;
	newest->position = position;
	newest->mark = mark;
	newest->next = (*headRef); 
	newest->prev = NULL; 
	if((*headRef) != NULL){
		(*headRef)->prev = newest;
	}
    (*headRef) = newest;
}


	



void printMoves(struct Game * currGame){
	struct Move * currMove = currGame->move; 
	struct Move * last; 
	printf("positions travered in backward directions:\n");
	while(currMove != NULL){
		printf("Player %c position at %d\n",currMove->mark, currMove->position);
		last = currMove;
		currMove = currMove->next;
	}	
	printf("\npositions travered in forward directions:\n");
	while(last != NULL){
		printf("Player %c position at %d\n",last->mark, last->position);
		last = last->prev; 
	}
}



bool search(struct Game* game, int game_id){
	if(game == NULL){
		return false; 
	}
	if(game->gameId == game_id){
		return true;
	}
	return search(game->next, game_id);
}

void CleanUp(Move * firstMove){
	Move * freeMove = firstMove 
	Move * move = NULL;
	while(move != NULL){
		move = freeMove->next; 
		free(freeMove);
		freeMove = move; 
	}
}
			
void WriteListToFile(Move * firstMove, char * fileName){
		FILE *pFile; 
		pFile = fopen(filename, "wb");
		if(pFile != NULL){
			Move *currentMove = firstMove;
			Move *next = NULL;
			Move *prev = NULL; 
			
			while(currentMove != NULL){
				next = firstMove->next; 
				prev = currentMove->prev; 
				currentMove->next = NULL; 
				currentMove->prev = NULL; 
				fseek(pFile, 0, SEEK_END); 
				fwrite(currentMove, sizeof(Move), 1, pFile); 
				printf("Writing: %d to file\n", currentMove->moveId);
				currentMove->next = next;
				currentMove->prev = prev; 
				
				next = NULL;
				prev = NULL; 
				
				currentMove = currentMove->next; 
				
			}
			fclose(pFile); 
			pFile = NULL; 
			
		}
		else{
			printf("FILE OPEN ERROR");
			
		
}

Move * ReadNextFromFile(Move * firstMove, FILE * pFile){
	
}

Move * ReadListIn(Move * firstMove, char * fileName){
	FILE *pFile;
	pFile(fileName, "rb");
	if(pFile != NULL){
		CleanUp(firstMove);
		firstMove = NULL; 
		
		fseek(pFile, 0, SEEK_END);
		long fileSize = ftell(pFile);
		rewind(pFile);
		
		int numEntries = (int)(fileSize / sizeof(Move)));
		printf("number of entries: %d\n", numEntries);
		int loop = 0;
		for(loop = 0; loop < numEntries; ++loop){
			fseek(pFile, (sizeof(Move) * loop), SEEK_SET);
			firstMove = ReadNextFromFile(firstMove, pFile);
			
		}
		
	}
	else{
		printf("FILE OPEN ERROR FOR READ");
	}
int checkwin();
void board();

int main(){
	
	
	struct Game * game = NULL; 
	int games = 0;
	int option = 0; 
	int quit = 1;
	while(quit != 0){
		printf("0 - Quit, 1 - Play Game, 2 - Search\n");
		scanf("%d",&option); 
		if(option == 1){
			char confirm[20]; 
	
			do{
		
		
				int player = 1, i, choice;
				char mark;
				int moves = 0;
		 
		
				struct Move* move = NULL; 
				square[1] = '1';
				square[2] = '2';
				square[3] = '3';
				square[4] = '4';
				square[5] = '5';
				square[6] = '6';
				square[7] = '7';
				square[8] = '8';
				square[9] = '9';
		
				//games++;
				//addGame(&game, games);
				do{
					board();
					player = (player % 2) ? 1 : 2;
					printf("Player %d, enter a number: ", player);
					scanf("%d", &choice);
					mark = (player == 1) ? 'X' : 'O';
					//addGame(&game, games);
		
					if(choice == 1 && square[1] == '1'){
						addMove(&move, moves,choice, mark);
						square[1] = mark;
			
						moves++;
					}
		
					else if(choice == 2 && square[2] == '2'){
						addMove(&move, moves,choice, mark);
						square[2] = mark;
			
						moves++;
					}
		
					else if(choice == 3 && square[3] == '3'){
						addMove(&move, moves,choice, mark);
						square[3] = mark;
			
						moves++;
					}
		
					else if(choice == 4 && square[4] == '4'){
						addMove(&move, moves,choice, mark);
						square[4] = mark;
			
						moves++;
					}
		
					else if(choice == 5 && square[5] == '5'){
						addMove(&move, moves,choice, mark);
						square[5] = mark;
			
						moves++;
					}
		
					else if(choice == 6 && square[6] == '6'){
						addMove(&move, moves,choice, mark);
						square[6] = mark;
			
						moves++;
					}
		
					else if(choice == 7 && square[7] == '7'){
						addMove(&move, moves,choice, mark);
						square[7] = mark;
				
						moves++;
					}
		
					else if(choice == 8 && square[8] == '8'){
						addMove(&move, moves,choice, mark);
						square[8] = mark; 
				
						moves++;
					}
		
					else if(choice == 9 && square[9] == '9'){
						addMove(&move, moves,choice, mark);
						square[9] = mark; 
			
						moves++;
					}
		
					else{
						printf("Invalid move ");
						player--;
						getch();
					}
					i = checkwin(); 
					player++;
				}while(i == -1);
	
				board(); 
				if(i == 1){
					printf("==>\aPlayer %d win\n", --player);
		
					addGame(&game,move, games);
					printGames(game);
					games++;
					printf("Success");
					printf("Play Again?");
					scanf("%s", &confirm); 
				
				//board(); 
		
				}
				else{
					printf("==>\aGame draw\n");
			
					addGame(&game,move, games);
					printGames(game);
					games++;
					printf("Success");
			
					//board();
					printf("Play Again?");
					scanf("%s", &confirm); 
				
				
		
		
		
				}
			 
				getch();
		
		
			}
			while(strcmp(confirm, "yes") == 0); 
		}else if(option == 2){
			int key = 0; 
			printf("Enter Game Id: ");
			scanf("%d", &key);
			printf("\n");
			if(search(game, key) == true){
				printMoves(game);
			}
			else{
				printf("\nGame Id Invalid");
			}
		}
				
		
		
		else if(option == 0){
			quit = 0; 
			exit(0); 
		}
		else {
			printf("Invalid Input!");
		}
	}
		
	
	return 0;
}

/*********************************************
FUNCTION TO RETURN GAME STATUS
1 FOR GAME IS OVER WITH RESULT
-1 FOR GAME IS IN PROGRESS
O GAME IS OVER AND NO RESULT
 **********************************************/

int checkwin(){
	if(square[1] == square[2] && square[2] == square[3])
		return 1;
	else if(square[4] == square[5] && square[5] == square[6]){
		return 1;
	}
	else if(square[7] == square[8] && square[8] == square[9]){
		return 1;
	}
	else if(square[1] == square[4] && square[4] == square[7]){
		return 1; 
	}
	else if(square[2] == square[5] && square[5] == square[8]){
		return 1;
	}
	else if(square[3] == square[6] && square[6] == square[9]){
		return 1;
	}
	else if(square[1] == square[5] && square[5] == square[9]){
		return 1;
	}
	else if(square[3] == square[5] && square[5] == square[7]){
		return 1;
	}
	else if(square[1] != '1' && square[2] != '2' && square[3] != '3' && square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7] != '7' && square[8] != '8' && square[9] != '9'){
		return 0;
	}
	else{ 
		return -1; 
	}
}

/*******************************************************************
FUNCTION TO DRAW BOARD OF TIC TAC TOE WITH PLAYERS MARK
 ********************************************************************/
void board(){
	system("cls");
	printf("\n\n\tTic Tac Toe\n\n");
	printf("Player 1 (X) - Player 2 (O)\n\n\n");
	 printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", square[1], square[2], square[3]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", square[4], square[5], square[6]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", square[7], square[8], square[9]);

    printf("     |     |     \n\n");
}