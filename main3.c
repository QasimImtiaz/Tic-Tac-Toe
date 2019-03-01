#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

char square[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
/*Move of a doubly linked list */

struct Game {
	int gameId;
	struct Move *move;
	struct Game *next;
};
struct Move {
	int moveId;
	char square; 
	char mark; 
	int choice; 
	struct Move* next; //Pointer to next move in DLL
	struct Move* prev;
	
};

//Allocate memory
void *chkMalloc(size_t sz){
	void *mem = malloc(sz);
	
	//Just fail immediately on error
	if(mem == NULL){
		printf("Out of memory! Existing.\n");
		exit(1);
	}
	
	//worked
	return mem;
}

//add move to game
void addGame(struct Game **game, int gameId){
	//insert at start of list 
	struct Game* new_game = (struct Game*)malloc(sizeof(struct Game));
	new_game->gameId = gameId;
	new_game->next = *game;
	*game = new_game;
}
int checkwin();
void board();
void printGames(struct Game *game){
	int player = 1, i; 
	while(game != NULL){
		printf("game number %d has:\n", game->gameId); 
		
		struct Move *currentMove = game->move;
		struct Move * last;
		
		while(currentMove != NULL){
			last = currentMove;
			currentMove = currentMove->next; 
		    
			
			
		}
		while(last != NULL){
			
			printf(" position for %d is %c\n", last->choice, last->mark);
			
			last = last->prev;
	
		}
	
		game = game->next;
	}
}

void printList(struct Move* move){
	struct Move* last;
	printf("\nGamn Numbers \n");
	while(move != NULL){
		//printf( "%d ", move->moveId);
		last = move;
		move = move->next;
	}
	while(last != NULL){
		printf(" %d ", last->moveId);
		last = last->prev;
	}
	
	
}





/* Given a reference (pointer to pointer) to the head of a list 
	and and an int, inserts a new node on the front of the list. */

void push(struct Game * game, int move_id, char square, char mark, int choice ){
	/*1. allocate move */
	struct Move* new_move = (struct Move*)malloc(sizeof(struct Move));
	
	/* 2. put in the data */
	new_move->moveId = move_id;
	
	/* 3. put in the square */
	new_move->square = square;
	new_move->mark = mark;
	new_move->choice = choice; 
	
	/* 4. Make next of new move as head and previous as NULL */
	new_move->next = game->move;
	new_move->prev = NULL;
	
	/* 5. change prev of head move to the new move */
	if(game->move != NULL)
		game->move->prev = new_move;
	 
	game->move = new_move; 
}




	
	
	
	


int main(){
	FILE *outfile; 
	FILE *infile;
	
	int player = 1, i, choice;
	char mark;
	int moves = 0;
	int games = 0; 
	//empty list
	//struct Move* head = NULL;
	struct Game* game = NULL; 
	addGame(&game, games); 
    games++; 
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
			push(game, moves, square[1], mark, choice);
			square[1] = mark;
			
			moves++;
		}
		
		else if(choice == 2 && square[2] == '2'){
			push(game, moves, square[2], mark, choice);
			square[2] = mark;
			
			moves++;
		}
		
		else if(choice == 3 && square[3] == '3'){
			push(game, moves, square[3], mark, choice);
			square[3] = mark;
			
			moves++;
		}
		
		else if(choice == 4 && square[4] == '4'){
			push(game, moves, square[4], mark, choice);
			square[4] = mark;
			
			moves++;
		}
		
		else if(choice == 5 && square[5] == '5'){
			push(game, moves, square[5], mark, choice);
			square[5] = mark;
			
			moves++;
		}
		
		else if(choice == 6 && square[6] == '6'){
			push(game, moves, square[6], mark, choice);
			square[6] = mark;
			
			moves++;
		}
		
		else if(choice == 7 && square[7] == '7'){
			push(game, moves, square[7], mark, choice);
			square[7] = mark;
			
			moves++;
		}
		
		else if(choice == 8 && square[8] == '8'){
			push(game, moves, square[8], mark, choice);
			square[8] = mark; 
			
			moves++;
		}
		
		else if(choice == 9 && square[9] == '9'){
			push(game, moves, square[9], mark, choice);
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
		printf("==>\aPlayer %d win ", --player);
		printGames(game);
		
		
	}
	else{
		printf("==>\aGame draw");
		printGames(game);
		
		
		
	}
	getch();
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

			