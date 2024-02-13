#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define limit 15

//FUNCTIONS, STRUCTURES, AND GLOBAL VARIABLES

int count = 0, nodeCount = 1;

struct stack{
	int numbers[limit];
	int top;
};
typedef struct stack st;

struct node{
	int data;
	struct node *next;
	struct node *prev;
};

void push(st *numStack);
void pop(st *numStack);
void print(st *numStack, int counter);

void linkPush(struct node** head);
void linkPrint(struct node** head);
void linkPop(struct node** head);

// MAIN DRIVER CODE

int main(){
	
// FIRST TEST (with arrays)
	int choice; 
	
	st *numStack= (st*)malloc(sizeof(st));
	if ((numStack->top)!=-1){
		numStack->top = -1;
	}
	
	printf("NUMBER ENTRY STACK LOG: \n\n");
	printf("[1] PUSH\n[2] POP\n[3] PRINT\n[0] EXIT\n\n");
	
do{
	printf("Your Choice: "); scanf("%d", &choice);
	
	while(choice!= 0 && choice!= 1 && choice != 2 && choice != 3){
        printf("Enter a valid choice: "); scanf(" %d", &choice);
    }
	
	switch(choice){
		case 1:
			push(numStack);
			break;
		case 2:
			pop(numStack);
			break;
		case 3: 
			print(numStack, count);
			break;
		}
	}while(choice != 0);
	
	system("cls");
	printf("\nLet's try this again, but with Linked Lists...\n");
	sleep(3);
	system("cls");
	
// SECOND TEST (with Linked Lists)
	int linkedChoice; 
	struct node *head = NULL;
	
	printf("NUMBER ENTRY STACK LOG; VERSION 2.0: \n\n");
	printf("[1] PUSH\n[2] POP\n[3] PRINT\n[0] EXIT\n\n");
	
do{
	printf("Your Choice: "); scanf("%d", &linkedChoice);
	
	while(linkedChoice!= 0 && linkedChoice!= 1 && linkedChoice != 2 && linkedChoice != 3){
        printf("Enter a valid choice: "); scanf(" %d", &linkedChoice);
    }
	
	switch(linkedChoice){
		case 1:
			linkPush(&head);
			break;
		case 2:
			linkPop(&head);
			break;
		case 3: 
			linkPrint(&head);
			break;
		}
	}while(linkedChoice != 0);
	
	system("cls");
	printf("\nLooks like I'm stackin' up...\n");
	
	
	return 0;
}

//FUNCTIONS SEGMENT 

void push(st *numStack){
	int numEntry;
	if (numStack->top == limit -1){
		printf("\nStack is full! Can't add data\n\n");
	}
	else{
		printf("\nEnter number entry %d: ", count+1); scanf("%d", &numEntry);
		numStack->top++;
		numStack->numbers[numStack->top] = numEntry;
		printf("Successfuly added entry!\n\n");
		count++;
	}
}

void pop(st *numStack){
	if (numStack->top == -1){
		printf("\nStack is empty! Nothing to delete\n\n");
	}
	else{
		printf("\nSuccessfully deleted '%d'\n\n", numStack->numbers[numStack->top]);
		numStack->top--;
		count--;
	}
}

void print(st *numStack, int counter){
	int i;
	if (numStack->top == -1){
		printf("\nStack is empty! Nothing to display\n\n");
	}
	else{
		printf("\nStack Entry List: \n\n");
		for (i = counter-1; i > -1; i--){
			printf("Data Entry %d: %d\n", i+1, numStack->numbers[i]);
		}
		printf("\n\nMost Recent Data Entry: %d\n\n", numStack->numbers[numStack->top]);
	}
}

// FUNCTION DECLARATIONS FOR ROUND 2;

void linkPush(struct node** head){
	
	struct node *newNode = (struct node*)malloc(sizeof(struct node));
	
	printf("Enter a number for node %d: ", nodeCount); scanf("%d", &newNode->data);
	
	if (*head == NULL){
		*head = newNode;
		printf("Successfully inserted %d to the head!\n\n", newNode->data);
	}
	else{
		newNode->next = *head;
		*head = newNode;
		printf("Successfully inserted %d to the head!\n\n", newNode->data);
	}
	nodeCount++;
}

void linkPop(struct node** head){
	struct node *deletor;
	if (*head == NULL){
		printf("Stack is already empty\n\n");
	}
	else{
		printf("Successfully deleted: %d!\n\n", (*head)->data);
		deletor = *head;
		*head = deletor->next;
		free(deletor);
	}
	nodeCount--;
}

void linkPrint(struct node** head){
	int printCount = 1;
	struct node *current = *head;
	if (current == NULL){
		printf("Stack is already empty\n\n");
	}
	else{
		while (printCount!= nodeCount){
			printf("Data Entry %d: %d\n", printCount, current->data);
			printCount++;
			current = current->next;
		}
		printf("\nMost Recent Data Entry: %d\n\n", (*head)->data);
	}
}
