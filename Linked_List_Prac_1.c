#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


struct node{
    int number;
    struct node *next;
    struct node *prev;
};

void addAndPrint(struct node** head, int count);
void indexCounter (struct node** head);
void deletor (struct node** head, int deleteCount);
void doubleItUp(struct node** doubleHead, int doubleCount);

int main(){

	struct node *head = NULL, *doubleHead = NULL;
	int nodeCount;
    printf("Enter the number of nodes: "); scanf("%d", &nodeCount);
    addAndPrint(&head, nodeCount);
    indexCounter (&head);
    deletor(&head, nodeCount);
    doubleItUp(&head, nodeCount);
    
}

void addAndPrint(struct node** head, int count) {
    int p, q, c = 1;
    struct node *newNode, *temporary, *hopper;

    for (p = 0; p < count; p++) {
    	newNode = (struct node*)malloc(sizeof(struct node));
    	newNode->next = NULL;
    	
        printf("Enter number entry %d: ", c);
        scanf("%d", &newNode->number);
        c++;

        if (*head == NULL) {
            *head = newNode;
        } else {
            temporary = *head;
            while (temporary->next != NULL) {
                temporary = temporary->next;
            }
            temporary->next = newNode;
        }
    }
	printf("\nNumber List: ");
    hopper = *head;
    while (hopper != NULL) {
        printf(" %d ", hopper->number);
        hopper = hopper->next;
    }
}

void indexCounter (struct node** head){
	
	struct node *index = *head;
	int position = 0;
	printf("\n\nThe indices of the data are the ff.\n\n");
	while(index != NULL){
		printf("Index of %d: %d\n", index->number, position);
		index = index -> next;
		position++;
	}
	printf("\n");
}

void deletor (struct node** head, int deleteCount){
	struct node *deleted = NULL;
	while(*head != NULL && deleteCount > 0){
		deleted = *head;
		printf("Data Entry: %d", deleted->number);
		printf("\tDELETED!\n\n");
		*head = (*head)->next;
		free(deleted);
		deleteCount--;
	}
	if (*head == NULL){
		printf("\nEverything is DELETED!\n\n");
	}
}

void doubleItUp(struct node** doubleHead, int doubleCount){
	struct node *newDouble, *dummy;
	int d, e = 1;
	for (d = 0; d < doubleCount; d++){
		newDouble = (struct node*)malloc(sizeof(struct node));
		newDouble->next = NULL;
		printf("Enter a number for Double LL Node No. %d: ", e); scanf("%d", &newDouble->number);
		
		if (*doubleHead == NULL){
			newDouble->prev = NULL;
			*doubleHead = newDouble;
		}
		else{
			dummy = *doubleHead;
			while(dummy->next != NULL){
				dummy = dummy->next;
			}
			dummy->next = newDouble;
			newDouble -> prev = dummy;
		}
		e++;
	}
	
	printf("\n\nDOUBLE LINKED LIST DATA DISPLAY: \n\n");
	
	int w = 0, n = 1;
	dummy = *doubleHead;
	while(dummy != NULL && w < doubleCount){
		printf("Data Entry Node %d: %d\n",n, dummy->number);
		if (dummy->prev == NULL){
			printf("Previous Entry Node: NULL\n");
		}
		else{
			printf("Previous Entry Node: %d\n", (dummy->prev)->number);
		}
		if (dummy->next == NULL){
			printf("Succeeding Entry Node: NULL\n=================================\n\n");
		}
		else{
			printf("Succeeding Entry Node: %d\n=================================\n\n", (dummy->next)->number);
		}
		dummy = dummy->next;
		n++; w++;
	}
}
