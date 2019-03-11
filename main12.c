#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

char square[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
char choices[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
char marks[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};


/*Move of a doubly linked list */

struct Game {
	int gameId;
	char choices[10];
    char marks[10];
	struct Game *next;
	
};




void reset(){
	square[1] = '1';
	square[2] = '2';
	square[3] = '3';
	square[4] = '4';
	square[5] = '5';
	square[6] = '6';
	square[7] = '7';
	square[8] = '8';
	square[9] = '9';
}		

void addGame(struct Game ** first_game, int game_id, char choices[10], char marks[10]){
	struct Game * new_game = (struct Game*) malloc(sizeof(struct Game)); 
	struct Game * last_game = *first_game;
	new_game->gameId = game_id;
	strcpy(new_game->choices,choices);
	printf("choices are %s\n", new_game->choices);
	strcpy(new_game->marks, marks);
	printf("marks are %s\n", new_game->marks); 
	new_game->next = NULL; 
	if(*first_game == NULL){
		*first_game = new_game;
		return; 
	}
	while(last_game->next != NULL){
		last_game = last_game->next; 
	}
	last_game->next = new_game;
	return; 
}
void ReadFromFileToLinkedList(struct Game ** first_game){
	FILE * file = fopen("list.txt", "r");
	char marks[10];
	char choices[10]; 
	int count = 0;
	
	while(fscanf(file, "%s %s", choices, marks) != EOF){
		
		
		addGame(first_game, count,choices, marks); 
		
		count++;
	}
	fclose(file); 
}


		
	
		

void board();
void search(struct Game ** first_game, int game_id){
	
	int found = 0; 
	struct Game *current_game = *first_game;
	while(current_game != NULL){
		if(current_game->gameId == game_id){
			found = 1; 
			for(int i = 1; i < 10; i ++){
				 
				if(current_game->choices[i] == '1' && (current_game->marks[i] == 'O' || current_game->marks[i] == 'X')){
					square[1] = current_game->marks[i]; 
					board(); 
				}
				else if(current_game->choices[i] == '2' && (current_game->marks[i] == 'O' || current_game->marks[i] == 'X')){
					square[2] = current_game->marks[i]; 
					board(); 
				}
				else if(current_game->choices[i] == '3' && (current_game->marks[i] == 'O' || current_game->marks[i] == 'X')){
					square[3] = current_game->marks[i];
					board(); 
				}
				else if(current_game->choices[i] == '4' && (current_game->marks[i] == 'O' || current_game->marks[i] == 'X')){
					square[4] = current_game->marks[i];
					board(); 
				}
				else if(current_game->choices[i] == '5' && (current_game->marks[i] == 'O' || current_game->marks[i] == 'X')){
					square[5] = current_game->marks[i];
					board(); 
				}
				else if(current_game->choices[i] == '6' && (current_game->marks[i] == 'O' || current_game->marks[i] == 'X')){
					square[6] = current_game->marks[i];
					board(); 
				}
				else if(current_game->choices[i] == '7' && (current_game->marks[i] == 'O' || current_game->marks[i] == 'X')){
					square[7] = current_game->marks[i];
					board(); 
				}
				else if(current_game->choices[i] == '8' && (current_game->marks[i] == 'O' || current_game->marks[i] == 'X')){
					square[8] = current_game->marks[i];
					board(); 
				}
				else if(current_game->choices[i] == '9' && (current_game->marks[i] == 'O' || current_game->marks[i] == 'X')){
					square[9] = current_game->marks[i];
					board(); 
				}
			}
			
			 
		}
		current_game = current_game->next; 
	}
				
	if(found == 0){
		printf("Game Id not found"); 
	}
}

void write_array_to_file(char choices[10], char marks[10])
{
    FILE *fp = fopen("list.txt", "a+");
    if (fp != NULL)
    {
		
		fprintf(fp,"%s %s\n",choices, marks); 
        fclose(fp);
    }
}

void replay(char * choices, char * marks){
	for(int i = 1; i <10; i++){
		
		if(choices[i] == '1' && (marks[i] == 'O' || marks[i] == 'X')){
			square[1] = marks[i]; 
			board(); 
		}
		else if(choices[i] == '2' && (marks[i] == 'O' || marks[i] == 'X')){
			square[2] = marks[i]; 
			board(); 
		}
		else if(choices[i] == '3' && (marks[i] == 'O' || marks[i] == 'X')){
			square[3] = marks[i];
			board(); 
		}
		else if(choices[i] == '4' && (marks[i] == 'O' || marks[i] == 'X')){
			square[4] = marks[i];
			board(); 
		}
		else if(choices[i] == '5' && (marks[i] == 'O' || marks[i] == 'X')){
			square[5] = marks[i];
			board(); 
		}
		else if(choices[i] == '6' && (marks[i] == 'O' || marks[i] == 'X')){
			square[6] = marks[i];
			board(); 
		}
		else if(choices[i] == '7' && (marks[i] == 'O' || marks[i] == 'X')){
			square[7] = marks[i];
			board(); 
		}
		else if(choices[i] == '8' && (marks[i] == 'O' || marks[i] == 'X')){
			square[8] = marks[i];
			board(); 
		}
		else if(choices[i] == '9' && (marks[i] == 'O' || marks[i] == 'X')){
			square[9] = marks[i];
			board(); 
		}
					
	}
}	

void reset_choices_and_marks(char * choices, char * marks){
	choices[1] = '1';
	choices[2] = '2';
	choices[3] = '3';
	choices[4] = '4';
	choices[5] = '5';
	choices[6] = '6';
	choices[7] = '7';
	choices[8] = '8';
	choices[9] = '9';
	marks[1] = '1';
	marks[2] = '2';
	marks[3] = '3';
	marks[4] = '4';
	marks[5] = '5';
	marks[6] = '6';
	marks[7] = '7';
	marks[8] = '8';
	marks[9] = '9';
}
	
	
int checkwin();

int main(){ 
	char confirm[20]; 
	while(1){
		int c;
		printf("\n0 - Quit, 1 - Play Game, 2 - Search"); 
		scanf("%d",&c); 
		if(c == 0){
			exit(0);
		}
		else if(c == 1){
			do{
					reset(); 
				
					int player = 1, i, choice;
					char mark; 
					
					int j = 1; 
					reset_choices_and_marks(choices, marks);
					
					
				do{
		
					board();
					player = (player % 2) ? 1 : 2;
					printf("Player %d, enter a number: ", player);
					scanf("%d", &choice);
					mark = (player == 1) ? 'X' : 'O';
		
		
		
					if(choice == 1 && square[1] == '1'){
				
			
						square[1] = mark;
						marks[j] = mark; 
						
						choices[j] = '1'; 
						printf("choice is %d and j is %d", choices[j], j);
						
						j++; 		
			
					}	
			
					else if(choice == 2 && square[2] == '2'){
			
				
						square[2] = mark;
						marks[j] = mark;
						choices[j] = '2';
						printf("choice is %d and j is %d", choices[j], j);
						j++; 
			
			
					}
		
					else if(choice == 3 && square[3] == '3'){
				
				
						square[3] = mark; 
						marks[j] = mark;
						choices[j] = '3';
						printf("choice is %d and j is %d", choices[j], j);
						j++; 
			
					}
		
					else if(choice == 4 && square[4] == '4'){
				
			
						square[4] = mark;
						marks[j] = mark; 
						choices[j] = '4';
						printf("choice is %d and j is %d", choices[j], j);
						j++; 
			
			
					}
		
					else if(choice == 5 && square[5] == '5'){
				
			
						square[5] = mark;
						marks[j] = mark; 
						choices[j] = '5';
						printf("choice is %d and j is %d", choices[j], j);					
						j++; 
			
			
					}
		
					else if(choice == 6 && square[6] == '6'){
			
			
						square[6] = mark;
						marks[j] = mark; 
						choices[j] = '6';
						printf("choice is %d and j is %d", choices[j], j);
						j++; 
			
					}
		
					else if(choice == 7 && square[7] == '7'){
			
			
						square[7] = mark;
						marks[j] = mark; 
						choices[j] = '7';
						printf("choice is %d and j is %d", choices[j], j);
						j++; 
			
			
					}
		
					else if(choice == 8 && square[8] == '8'){
			
						square[8] = mark; 
						marks[j] = mark; 
						choices[j] = '8';
						printf("choice is %d and j is %d", choices[j], j);
						j++; 
			
			
					}
		
					else if(choice == 9 && square[9] == '9'){
			
			
						square[9] = mark; 
						marks[j] = mark; 
						choices[j] = '9'; 
						printf("choice is %d and j is %d", choices[j], j);
						j++; 
			
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
					printf("==>\aPlayer %d win\n ", --player);
					write_array_to_file(choices, marks); 
					reset(); 
					board();
					replay(choices,marks); 
					printf("Play Again?");
					scanf("%s", &confirm); 
				}
				else{
					printf("==>\aGame draw");
					write_array_to_file(choices, marks);	
					reset(); 
					board();
					replay(choices,marks); 
					printf("Play Again?");
					scanf("%s", &confirm); 
				}		
		
				getch();
			}while(strcmp(confirm, "yes") == 0); 
		}
		else if(c == 2){
			reset(); 
			board(); 
			struct Game * game = NULL;
			printf("test 1\n"); 
			ReadFromFileToLinkedList(&game);
			
			printf("test 2\n"); 
			int game_id = 0; 
			printf("\nEnter Game Id: ");
			scanf("%d", &game_id);
			search(&game, game_id); 	
			printf("game_id is %d\n", game_id); 
		}
		
		else{
			printf("False Option");
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