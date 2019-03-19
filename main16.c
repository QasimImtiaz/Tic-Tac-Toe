#include <stdio.h>
#include <conio.h>
#include <stdlib.h> 
#include <limits.h>
#include <string.h>

char square[10] = { 'o', '1', '2', '3', '4', '5', '6', '7', '8', '9' };

int checkwin();
void board();

// A structure to represent a stack 
struct Stack 
{ 
    int top; 
    unsigned capacity; 
    char* array; 
}; 

struct Game {
	int gameId; 
	char choices[9];
	char marks[9];
	struct Game * next; 
};

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

void search(struct Game ** first_game, int game_id){
	
	int found = 0; 
	struct Game *current_game = *first_game;
	while(current_game != NULL){
		if(current_game->gameId == game_id){
			found = 1; 
			for(int i = 0; i < 9; i ++){
				 
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
	
// function to create a stack of given capacity. It initializes size of 
// stack as 0 
struct Stack* createStack(unsigned capacity) 
{ 
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack)); 
    stack->capacity = capacity; 
    stack->top = -1; 
    stack->array = (char*) malloc(stack->capacity * sizeof(char)); 
    return stack; 
} 
  
// Stack is full when top is equal to the last index 
int isFull(struct Stack* stack) 
{   return stack->top == stack->capacity - 1; } 
  
// Stack is empty when top is equal to -1 
int isEmpty(struct Stack* stack) 
{   return stack->top == -1;  } 
  
// Function to add an item to stack.  It increases top by 1 
void push(struct Stack* stack, char item) 
{ 
    if (isFull(stack)) 
        return; 
    stack->array[++stack->top] = item; 
    printf("%c pushed to stack\n", item); 
} 
  
// Function to remove an item from stack.  It decreases top by 1 
int pop(struct Stack* stack) 
{
    return stack->array[stack->top--]; 
} 

void destroy(struct Stack * moves){
	int i = moves->top; 
	while(i >= 0){
		moves->array[i] = pop(moves);
		i--;
	}
}
	
	

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

void replay(struct Stack * choicesStack, struct Stack * marksStack){
	char * choices = choicesStack->array; 
	char * marks = marksStack->array; 
	for(int i = 0; i <=choicesStack->top; i++){
		
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

void write_arrays_to_file(struct Stack * choices, struct Stack * marks)
{
    FILE *fp = fopen("list.txt", "a+");
    if (fp != NULL)
    {
		for(int i = 0; i <= choices->top; i++){
			fprintf(fp,"%c",choices->array[i]);
		}
		fprintf(fp, " "); 
		for(int i = 0; i <= marks->top; i++){
			fprintf(fp, "%c", marks->array[i]);
		}
		fprintf(fp, "\n"); 
		
		
        fclose(fp);
    }
}

void undo(struct Stack * undoMarks, struct Stack * undoChoices, struct Stack * redoMarks, struct Stack * redoChoices){
	char mark = pop(undoMarks);
	char choice = pop(undoChoices); 
	push(redoMarks, mark);
	push(redoChoices, choice);
	
	if(choice == '1'){
		square[1] = '1';
	}
	else if(choice == '2'){
		square[2] = '2';
	}
	else if(choice == '3'){
		square[3] = '3';
	}	
	else if(choice == '4'){
		square[4] = '4';
	}
	else if(choice == '5'){
		square[5] = '5';
	}
	else if(choice == '6'){		
		square[6] = '6';
	}
	else if(choice == '7'){
		square[7] = '7'; 
	}
	else if(choice == '8'){
		square[8] = '8';
	}
	else if(choice == '9'){ 
		square[9] = '9';
	}
}

void redo(struct Stack * undoMarks, struct Stack * undoChoices, struct Stack * redoMarks, struct Stack * redoChoices){
	char mark = pop(redoMarks);
	char choice = pop(redoChoices); 
	push(undoMarks, mark);
	push(undoChoices, choice);
	if(choice == '1'){
		square[1] = mark; 
	}
	else if(choice == '2'){
		square[2] = mark; 
	}
	else if(choice == '3'){
		square[3] = mark; 
	}	
	else if(choice == '4'){
		square[4] = mark; 
	}
	else if(choice == '5'){
		square[5] = mark; 
	}
	else if(choice == '6'){		
		square[6] = mark; 
	}
	else if(choice == '7'){
		square[7] = mark; 
	}
	else if(choice == '8'){
		square[8] = mark; 
	}
	else if(choice == '9'){ 
		square[9] = mark; 
	}
}

int isMovesLeft(){
	for(int i = 1; i < 10; i++){
		if(square[i] == '1' || square[i] == '2' || square[i] == '3' || square[i] == '4' || square[i] == '5' || square[i] == '6' || square[i] == '7' || square[i] == '8' || square[i] == '9'){
			
			return 1; 
		}
	}
	return 0;  
}

int evaluate(char square[10]){
	
	if(square[1] == square[2] && square[2] == square[3]){
		if(square[1] == 'O'){
			return +10; 
		}
		else if(square[1] == 'X'){
			return -10; 
		}
	}
	else if(square[4] == square[5] && square[5] == square[6]){
		if(square[4] == 'O'){
			return +10; 
		}
		else if(square[4] == 'X'){
			return -10;
		}
	}
	else if(square[7] == square[8] && square[8] == square[9]){
		if(square[7] == 'O'){
			return +10; 
		}
		else if(square[7] == 'X'){
			return -10;
		}
	}
	else if(square[1] == square[4] && square[4] == square[7]){
		if(square[1] == 'O'){
			return +10;
		}
		else if(square[1] == 'X'){
			return -10;
		}
	}
	else if(square[2] == square[5] && square[5] == square[8]){
		if(square[2] == 'O'){
			return +10; 
		}
		else if(square[2] == 'X'){
			return -10; 
		}
	}
	else if(square[3] == square[6] && square[6] == square[9]){
		if(square[3] == 'O'){
			return +10;
		}
		else if(square[3] == 'X'){
			return -10;
		}
	}
	else if(square[1] == square[5] && square[5] == square[9]){
		if(square[1] == 'O'){
			return +10;
		}
		else if(square[1] == 'X'){
			return -10;
		}
	}
	else if(square[7] == square[5] && square[5] == square[3]){
		if(square[7] == 'O'){
			return +10;
		}
		else if(square[7] == 'X'){
			return -10;
		}
	}
	
	return 0; 
	
}
				

int minimax(char square[10], int depth, int isMax){
	int score = evaluate(square);
	if(score == 10){
		return score;
	}
	if(score == -10){
		return score; 
	}
	if(isMovesLeft(square) == 0){
		 
		return 0;
	}
	if(isMax){
		int best = -1000;
		for(int i = 1; i < 10; i++){
			if(square[i] == '1' || square[i] == '2' || square[i] == '3' || square[i] == '4' || square[i] == '5' || square[i] == '6' || square[i] == '7' || square[i] == '8' || square[i] == '9'){
				char previous = square[i]; 
				square[i] = 'O';
				best = max(best, minimax(square, depth+1, !isMax));
				square[i] = previous; 
				//square[i] = '_';
			}
			 
		
		}
		return best;
	}		
	else{
		int best = 1000; 
		for(int i = 1; i < 10; i++){
			if(square[i] == '1' || square[i] == '2' || square[i] == '3' || square[i] == '4' || square[i] == '5' || square[i] == '6' || square[i] == '7' || square[i] == '8' || square[i] == '9'){
				char previous = square[i]; 
				square[i] = 'X';
				best = min(best, minimax(square, depth + 1, !isMax));
				square[i] = previous; 
			}
		}
		return best; 
	}
	 
}

int findBestMove(char * square){
	int bestVal = -1000;
	int bestMove;   
	 
	for(int i = 1; i < 10; i++){
		if(square[i] == '1' || square[i] == '2' || square[i] == '3' || square[i] == '4' || square[i] == '5' || square[i] == '6' || square[i] == '7' || square[i] == '8' || square[i] == '9'){
			char previous = square[i]; 
			square[i] = 'O';
			
			int moveVal = minimax(square, 0, 0);
			 
			square[i] = previous; 
			if(moveVal > bestVal){
				bestVal = moveVal;
				bestMove = i; 
			}
		}
	}
	return bestMove;
}



	

int main()
{
	while(1){
		int c;
		printf("\n0 - Quit, 1 - Multiplayer Game, 2 - Play With Computer, 3 - Games Replays: ");
		scanf("%d", &c);
		if(c == 0){
			exit(0);
		}
		else if(c == 1){
			char confirm[20]; 
			do{
				reset();
		
				int player = 1, i, choice;

				char mark;
				struct Stack * undoChoices = createStack(9);
				struct Stack * undoMarks = createStack(9); 
				struct Stack * redoChoices = createStack(9);
				struct Stack * redoMarks = createStack(9); 
	
    
        
				do {
					board();
					player = (player % 2) ? 1 : 2;

					printf("Player %d, enter a number:  ", player);
					scanf("%d", &choice);

					mark = (player == 1) ? 'X' : 'O';

					if(choice == 1 && square[1] == '1'){
						square[1] = mark;
						destroy(redoChoices); 
						destroy(redoMarks); 
						
						push(undoChoices, '1');
						push(undoMarks, mark); 
					}
	        
					else if(choice == 2 && square[2] == '2'){
						square[2] = mark;
						destroy(redoChoices); 
						destroy(redoMarks); 
						push(undoChoices, '2');
						push(undoMarks, mark); 
					}
            
					else if(choice == 3 && square[3] == '3'){
						square[3] = mark;
						destroy(redoChoices); 
						destroy(redoMarks); 
						push(undoChoices, '3');
						push(undoMarks, mark); 
					}
            
					else if(choice == 4 && square[4] == '4'){
						square[4] = mark;
						destroy(redoChoices); 
						destroy(redoMarks); 
						push(undoChoices, '4');
						push(undoMarks, mark);
					}
            
					else if(choice == 5 && square[5] == '5'){
						square[5] = mark;
						destroy(redoChoices); 
						destroy(redoMarks); 
						push(undoChoices, '5');
						push(undoMarks, mark);
					}
			
            
					else if(choice == 6 && square[6] == '6'){
						square[6] = mark;
						destroy(redoChoices); 
						destroy(redoMarks); 
						push(undoChoices, '6');
						push(undoMarks, mark);
					}
			
            
					else if(choice == 7 && square[7] == '7'){
						square[7] = mark;
						destroy(redoChoices); 
						destroy(redoMarks); 
						push(undoChoices, '7');
						push(undoMarks, mark);
					}
			
            
					else if(choice == 8 && square[8] == '8'){
						square[8] = mark;
						destroy(redoChoices); 
						destroy(redoMarks); 
						push(undoChoices, '8');
						push(undoMarks, mark);
					}
			
            
					else if(choice == 9 && square[9] == '9'){
						square[9] = mark;
						destroy(redoChoices); 
						destroy(redoMarks); 
						push(undoChoices, '9');
						push(undoMarks, mark); 
					}
					
					else if(choice == 10){
						if(!(isEmpty(undoMarks)) && !(isEmpty(undoChoices)) && !(isFull(redoMarks)) && !(isFull(redoMarks))){
							player--;
							undo(undoMarks, undoChoices, redoMarks, redoChoices);
							board(); 
						}
						else{
							player--; 
							printf("Sorry you can't undo right now!");
							getch();
						}
					}
					else if(choice == 11){
						if(!(isEmpty(redoMarks)) && !(isEmpty(redoChoices)) && !(isFull(undoMarks)) && !(isFull(undoChoices))){
							player--;
							redo(undoMarks, undoChoices, redoMarks, redoChoices);
							board();
						}
						else{
							player--;
							printf("Sorry you can't redo right now!");
							getch();
						}
					}
					else
					{
						printf("Invalid move ");
						player--;
						getch();
					}
					i = checkwin();

					player++;
				}while (i == -1);
    
				board();
    
				if (i == 1){
					printf("==>\aPlayer %d win ", --player);
					for(int i = 0; i <= undoChoices->top; i++){
						printf("%c", undoChoices->array[i]);
					}
					printf("\n");
					for(int i = 0; i <= undoMarks->top;  i++){
						printf("%c", undoMarks->array[i]);
					}
					write_arrays_to_file(undoChoices, undoMarks); 
					getch();
					reset(); 
					replay(undoChoices, undoMarks); 
					printf("\nPlay Again?");
					scanf("%s", &confirm); 
			
		
				}
				else{
					printf("==>\aGame draw");
					for(int i = 0; i <= undoChoices->top; i++){
						printf("%c", undoChoices->array[i]);
					}
					printf("\n");
					for(int i = 0; i <= undoMarks->top; i++){
						printf("%c", undoMarks->array[i]);
					}
					write_arrays_to_file(undoChoices, undoMarks); 
					getch();
					reset(); 
					replay(undoChoices, undoMarks); 
			
					printf("\nPlay Again?");
					scanf("%s", &confirm); 
				}
				getch();
			}while(strcmp(confirm, "yes") == 0);
		}
		else if(c == 3){
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
		else if(c == 2){
			char confirm[20]; 
			do{
				reset();
		
				int player = 1, i, choice;
				

				char mark;
				struct Stack * undoChoices = createStack(9);
				struct Stack * undoMarks = createStack(9); 
				struct Stack * redoChoices = createStack(9);
				struct Stack * redoMarks = createStack(9); 
				char previousMove;  
    
        
				do {
					board();
					 
					player = (player % 2) ? 1 : 2;
					mark = (player == 1) ? 'X' : 'O';
                    if(player == 1){
						printf("Player %d, enter a number:  ", player);
						scanf("%d", &choice);
					}
					else{
						choice = findBestMove(square); 
					}

					
					
					if(choice == 1 && square[1] == '1'){
						square[1] = mark;
						destroy(redoChoices); 
						destroy(redoMarks); 
						
						push(undoChoices, '1');
						push(undoMarks, mark); 
						previousMove = mark; 
						
					}
	        
					else if(choice == 2 && square[2] == '2'){
						square[2] = mark;
						destroy(redoChoices); 
						destroy(redoMarks); 
						push(undoChoices, '2');
						push(undoMarks, mark); 
						previousMove = mark; 
					}
            
					else if(choice == 3 && square[3] == '3'){
						square[3] = mark;
						destroy(redoChoices); 
						destroy(redoMarks); 
						push(undoChoices, '3');
						push(undoMarks, mark); 
						previousMove = mark; 
					}
            
					else if(choice == 4 && square[4] == '4'){
						square[4] = mark;
						destroy(redoChoices); 
						destroy(redoMarks); 
						push(undoChoices, '4');
						push(undoMarks, mark);
						previousMove = mark; 
					}
            
					else if(choice == 5 && square[5] == '5'){
						square[5] = mark;
						destroy(redoChoices); 
						destroy(redoMarks); 
						push(undoChoices, '5');
						push(undoMarks, mark);
						previousMove = mark; 
					}
			
            
					else if(choice == 6 && square[6] == '6'){
						square[6] = mark;
						destroy(redoChoices); 
						destroy(redoMarks); 
						push(undoChoices, '6');
						push(undoMarks, mark);
						previousMove = mark; 
					}
			
            
					else if(choice == 7 && square[7] == '7'){
						square[7] = mark;
						destroy(redoChoices); 
						destroy(redoMarks); 
						push(undoChoices, '7');
						push(undoMarks, mark);
						previousMove = mark; 
					}
			
            
					else if(choice == 8 && square[8] == '8'){
						square[8] = mark;
						destroy(redoChoices); 
						destroy(redoMarks); 
						push(undoChoices, '8');
						push(undoMarks, mark);
						previousMove = mark; 
					}
			
            
					else if(choice == 9 && square[9] == '9'){
						square[9] = mark;
						destroy(redoChoices); 
						destroy(redoMarks); 
						push(undoChoices, '9');
						push(undoMarks, mark); 
						previousMove = mark; 
					}
					
					else if(choice == 10){
						if(!(isEmpty(undoMarks)) && !(isEmpty(undoChoices)) && !(isFull(redoMarks)) && !(isFull(redoMarks))){
							player--;
							undo(undoMarks, undoChoices, redoMarks, redoChoices);
							board(); 
						}
						else{
							player--; 
								
							printf("Sorry you can't undo right now!");
							getch();
						}
					}
					else if(choice == 11){
						if(!(isEmpty(redoMarks)) && !(isEmpty(redoChoices)) && !(isFull(undoMarks)) && !(isFull(undoChoices))){
							player--;
							redo(undoMarks, undoChoices, redoMarks, redoChoices);
							board();
						}
						else{
							player--;
							printf("Sorry you can't redo right now!");
							getch();
						}
					}
					else{
						
					
						printf("Invalid move ");
						player--;
						getch();
					}	
					i = checkwin();
                    player++; 
				
						//player = 2; 
					
				}while (i == -1);
    
				board();
    
				if (i == 1){
					printf("==>\aPlayer %d win ", --player);
					for(int i = 0; i <= undoChoices->top; i++){
						printf("%c", undoChoices->array[i]);
					}
					printf("\n");
					for(int i = 0; i <= undoMarks->top;  i++){
						printf("%c", undoMarks->array[i]);
					}
					write_arrays_to_file(undoChoices, undoMarks); 
					getch();
					reset(); 
					replay(undoChoices, undoMarks); 
					printf("\nPlay Again?");
					scanf("%s", &confirm); 
			
		
				}
				else{
					printf("==>\aGame draw");
					for(int i = 0; i <= undoChoices->top; i++){
						printf("%c", undoChoices->array[i]);
					}
					printf("\n");
					for(int i = 0; i <= undoMarks->top; i++){
						printf("%c", undoMarks->array[i]);
					}
					write_arrays_to_file(undoChoices, undoMarks); 
					getch();
					reset(); 
					replay(undoChoices, undoMarks); 
			
					printf("\nPlay Again?");
					scanf("%s", &confirm); 
				}
				getch();
			}while(strcmp(confirm, "yes") == 0);
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

int checkwin()
{
    if (square[1] == square[2] && square[2] == square[3])
        return 1;
        
    else if (square[4] == square[5] && square[5] == square[6])
        return 1;
        
    else if (square[7] == square[8] && square[8] == square[9])
        return 1;
        
    else if (square[1] == square[4] && square[4] == square[7])
        return 1;
        
    else if (square[2] == square[5] && square[5] == square[8])
        return 1;
        
    else if (square[3] == square[6] && square[6] == square[9])
        return 1;
        
    else if (square[1] == square[5] && square[5] == square[9])
        return 1;
        
    else if (square[3] == square[5] && square[5] == square[7])
        return 1;
        
    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' &&
        square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7] 
        != '7' && square[8] != '8' && square[9] != '9')

        return 0;
    else
        return  - 1;
}


/*******************************************************************
FUNCTION TO DRAW BOARD OF TIC TAC TOE WITH PLAYERS MARK
 ********************************************************************/


void board()
{
    system("cls");
    printf("\n\n\tTic Tac Toe\n\n");

    printf("Player 1 (X)  -  Player 2 (O)\n\n\n");


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

/*******************************************************************
END OF PROJECT
 ********************************************************************/