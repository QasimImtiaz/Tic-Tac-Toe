#include <stdio.h>
#include <string.h>

//Game of a doubly linked list called games
struct Game {
	char game[3][3];
	int gameId; 
	struct Game* next; 
	struct Game* prev; 
};

struct Game *split(struct Game *head);

//Function to merge two Games
struct Game *merge(struct Game *first, struct Game *second)
{
	//if first Games is empty
	if(!first){
		return second; 
	}
	
	//if second game is empty 
	if(!second){
		return first;
	}
	
	//Pick smaller value 
	if(first->gameId < second->gameId){
		first->next = merge(first->next, second);
		first->next->prev = first;
		first->prev = NULL;
		return first;
	}
	else
	{
		second->next = merge(first, second->next);
		second->next->prev = second;
		second->prev = NULL;
		return second;
	}
}

//Function to do merge sort
struct Game *mergeSort(struct Game *head){
	if(!head || !head->next)
		return head; 
	struct Game *second = split(head);
	
	//recurv for left and right halves
	head = mergeSort(head);
	second = mergeSort(second);
	
	//Merge two sorted halves
	return merge(head, second);
}

//A utility function to insert a new game start of doubly linked list
void insert(struct Game **head, int gameId, char game[3][3]){
	struct Game *temp = (struct Game *)malloc(sizeof(struct Game));
	temp->gameId = gameId; 
	temp->game[3][3] = game[3][3]; 
	temp->next = temp->prev = NULL;
	if(!(*head))
		(*head) = temp;
	else
	{
		temp->next = *head;
		(*head)->prev = temp;
		(*head) = temp;
	}
}

//A utility function to print a doubly linked list in 
//both forward and background directions 
void print(struct Game *head){
	struct Game *temp = head;
	printf("Forward Traversal using next pointer\n");
	while(head)
	{
		printf("%d \n", head->gameId);
		temp = head;
		head = head->next;
	}
	printf("\nBackward Traversal using prev pointer\n");
	while(temp)
	{
		printf("%d ", temp->gameId);
		temp = temp->prev;
	}
}

//Utility function to swap two integers
void swap(int *A, int *B){
	int temp = *A;
	*A = *B;
	*B = temp;
}

//Split a doubly linked list into 2 DLLs of half sizes
struct Game *split(struct Game *head)
{
	struct Game *fast = head, *slow = head;
	while(fast->next && fast->next->next)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	struct Game *temp = slow->next;
	slow->next = NULL;
	return temp;
}



	

void drawBoard(char board[][3])
{
    int rows, columns;
    for ( rows = 0 ; rows < 3 ; rows++ )
        {
            for ( columns = 0 ; columns < 3 ; columns++ )
            {
                if(board[rows][columns]){
                    printf( "|%c", board[rows][columns] );
                }else{
                    printf("| ");                         
                }
            }
            printf("|\n");
        }
}


int main()
{
    int quit = 0; 
    int choice = 1;
	struct Game *head = NULL; 
	while(quit != 1){
		printf("0 - Quit, 1 - Play, 2 - Search: ");
		scanf("%d", &choice); 
		switch(choice)
		{
			case 0:
				quit = 1; 
				break;
			case 1: 
	
                char game[3][3]={{0}};
				int row,column;
				char player = 'O';
				
				int gameNumber = 0;
				int totalEntry = 0;
				
	
	            
				while(totalEntry<=9){
					printf("%c to play\n", player);
         
					printf("Enter row number: ");
					scanf("%d",&row);        
					getchar();
					printf("Enter Column number: ");
					scanf("%d",&column);
					getchar();
					if(game[row][column] == 'X'){
						printf("Enter row number: ");
						scanf("%d", &row);
						getchar();
						printf("Enter column number: ");
						scanf("%d", &column);
						getchar();
					}
					else if(game[row][column] == 'O'){
						printf("Enter row number: ");
						scanf("%d", &row);
						getchar();
						printf("Enter column number: ");
						scanf("%d", &column);
						getchar();
					}
					else{
						game[row][column] = player;
						drawBoard(game);
			 
						if(game[0][column] == player && game[1][column] == player && game[2][column] == player){
							printf("%c Wins!", player);
				 
							break;
				
				
						}
						else if(game[row][0] == player && game[row][1] == player && game[row][2] == player){
							printf("%c Wins!", player);
				
							
							break;
						}
						else if(game[0][0] == player && game[1][1] == player && game[2][2] == player){
							printf("%c Wins!", player);
				
							
							break; 
						}
						else if(game[2][0] == player && game[1][1] == player && game[0][2] == player){
							printf("%c Wins!", player);
			
							
							break; 
					
						}
						
						
				
			 
						if(player == 'X'){
							player = 'O';
						}
						else {
							player = 'X';
						}
					}
				}
				insert(&head, gameNumber, game);
				
				
				break;
			case 2:
				head = mergeSort(head);
				printf("\n\nGames after sorting\n");
				print(head);
				break;
			default:
				printf("Choice other than 1, 2, 3");
				break; 
		}
		
	}
				
		
		
		
		
			
		 
	
           
	
	return 0; 
}