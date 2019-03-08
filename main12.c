#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

char square[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

/*Move of a doubly linked list */

struct Game {
	int gameId;
    char marks[10]; 
	
	struct Game *next;
	struct Game *prev; 
};




//add move to game
void addGame(struct Game **game, int gameId, char marks[10]){
	//insert at start of list 
	struct Game* new_game = (struct Game*)malloc(sizeof(struct Game));
	struct Game* last_game = *game; 
	new_game->gameId = gameId;
	 

	strcpy(new_game->marks, marks); 
	new_game->next = NULL; 
	if(*game == NULL){
		new_game->prev = NULL;
		*game = new_game;
		return;
		
	}
	while(last_game->next != NULL){
		last_game = last_game->next; 
	}
	
	last_game->next = new_game;
	new_game->prev = last_game;
	
	return; 
}

void readFromFile(struct Game ** first_game, FILE * f){
	char * line = malloc(sizeof(char));
	struct Game * new_game = (struct Game*)malloc(sizeof(struct Game)); 
	struct Game * last_game = *first_game;
	f = fopen("list.txt", "r"); 
	int count = 0; 
	while(fgets(line, sizeof(line), f)){
		
		new_game->gameId = count; 
		strcpy(line, new_game->marks);
		new_game->next = NULL; 
		if(*first_game == NULL){				
			new_game->prev = NULL; 
			*first_game = new_game; 
			return; 
		}
		while(last_game->next != NULL){
			last_game = last_game->next;
		}
		last_game->next = new_game;
		new_game->prev = last_game; 
		count++;
	}
}
	
	

int checkwin();
void board();



int main(){
	
	

	//FILE * fptr; 
	int games = 0; 
	//empty list
	//struct Move* head = NULL;
	struct Game* game = NULL; 
	char confirm[20]; 
	
	//games++;
	//addGame(&game, games);
	do{
				square[1] = '1';
				square[2] = '2';
				square[3] = '3';
				square[4] = '4';
				square[5] = '5';
				square[6] = '6';
				square[7] = '7';
				square[8] = '8';
				square[9] = '9';
				
				int player = 1, i, choice;
				char mark; 
				char marks[10] = {'0','1', '2', '3', '4', '5', '6', '7', '8', '9'};
		do{
		
			board();
			player = (player % 2) ? 1 : 2;
			printf("Player %d, enter a number: ", player);
			scanf("%d", &choice);
			mark = (player == 1) ? 'X' : 'O';
		
		
		
			if(choice == 1 && square[1] == '1'){
				
			
				square[1] = mark;
				marks[1] = square[1]; 
			
			}
		
			else if(choice == 2 && square[2] == '2'){
			
				
				square[2] = mark;
				marks[2] = square[2]; 
			
			
			}
		
			else if(choice == 3 && square[3] == '3'){
				
				
				square[3] = mark;
				marks[3] = square[3]; 
			
			}
		
			else if(choice == 4 && square[4] == '4'){
				
			
				square[4] = mark;
				marks[4] = square[4]; 
			
			
			}
		
			else if(choice == 5 && square[5] == '5'){
				
			
				square[5] = mark;
				marks[5] = square[5]; 
			
			
			}
		
			else if(choice == 6 && square[6] == '6'){
			
			
				square[6] = mark;
				marks[6] = square[6]; 
			
			}
		
			else if(choice == 7 && square[7] == '7'){
			
			
				square[7] = mark;
				marks[7] = square[7]; 
			
			
			}
		
			else if(choice == 8 && square[8] == '8'){
			
				square[8] = mark; 
				marks[8] = square[8]; 
			
			
			}
		
			else if(choice == 9 && square[9] == '9'){
			
			
				square[9] = mark; 
				marks[9] = square[9]; 
			
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
			printf("==>\aPlayer %d win ", --player);
			FILE * fptr; 
			fptr = fopen("list.txt", "a+");
			printf("test");
			if(fptr == NULL){
				printf("Error\n");
			}
			else{
				fprintf(fptr,"%s\n", square);
			
			}
			fclose(fptr); 
			
			square[0] = '0';
			square[1] = '1';
			square[2] = '2';
			square[3] = '3';
			square[4] = '4';
			square[5] = '5';
			square[6] = '6';
			square[7] = '7';
			square[8] = '8';
			square[9] = '9';
			
			board();
			
			for(int i = 1; i <10; i++){
				
				square[i] = marks[i];
				board(); 
					
				
				
			}
			
			
			
			
			printf("Play Again?");
			scanf("%s", &confirm); 
				
			
		
		}
		else{
			printf("==>\aGame draw");
			FILE * fptr; 
			fptr = fopen("list.txt", "a+");
			if(fptr == NULL){
				printf("Error\n");
			}
			else{
		
			
			
				fprintf(fptr,"%s\n", square);
			
		
			}
	
			
			fclose(fptr); 
			square[0] = '0';
			square[1] = '1';
			square[2] = '2';
			square[3] = '3';
			square[4] = '4';
			square[5] = '5';
			square[6] = '6';
			square[7] = '7';
			square[8] = '8';
			square[9] = '9';
			
			board();
		
			for(int i = 0; i <10; i++){
				
				square[i] = marks[i];
				board(); 
				
			}
			printf("Play Again?");
			scanf("%s", &confirm); 
				
		
		}		
		
		
		
		getch();
	}while(strcmp(confirm, "yes") == 0); 
	FILE * fptr = fptr = fopen("list.txt", "a+");
	readFromFile(&game, fptr); 
			 
	fclose(fptr); 
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