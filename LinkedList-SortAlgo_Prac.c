#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct entry{
	int prioNum;
	char name[100];
	struct entry *next;
};

struct candidate{
	int points;
	char name[100];
	struct candidate *next;
};

void AaddData(struct entry **start);
void AsortData (struct entry **start);
void DaddData(struct candidate **head);
void DsortData (struct candidate **head);

int main(){
	
	struct entry *start = NULL;
	struct candidate *head = NULL;
	printf("Linked List Bubble Sorting (ASCENDING)\n\n");
	AaddData(&start);
	AsortData (&start);
	printf("\n\nPress Any Key to Continue"); getche();
	system("cls");
	printf("Linked List Bubble Sorting (DESCENDING)\n\n");
	DaddData(&head);
	DsortData (&head);
	printf("\n\nPress Any Key to Continue"); getche();
	system("cls");
	printf("\n\nLooks like you got it sorted out.\n\n");
	
	return 0;
}

// ASCENDING ORDER

void AaddData(struct entry **start){
	struct entry *newNode, *temp, *test;
	int i;
	
	for (i = 0; i < 10; i++){
		newNode = (struct entry*)malloc(sizeof(struct entry));
		newNode->next = NULL;
	
		fflush(stdin);
		printf("Enter name: "); gets(newNode->name);
		printf("Enter Priority Number: "); scanf("%d", &newNode->prioNum);
		printf("\n");
	
		if (*start == NULL){
			*start = newNode;
		}
		else{
			temp = *start;
			while(temp->next != NULL){
				temp = temp->next;
			}
			temp->next = newNode;
		}
	}
	
}

void AsortData (struct entry **start){
	
	printf("======= PRIORITY LIST ========\n");
	
	struct entry *current, *temp, *printed;
	int step, swapped;
	
	for (step = 0; step < 9; step++){
		current = *start;
		swapped = 0;
		while (current->next != NULL){
			struct entry *next = current->next;
			if (current->prioNum > next->prioNum){
				temp = next->next;
				next->next = current;
				current->next = temp;
				
				if (current == *start){
				*start = next;
			}else{
				struct entry *prev = *start;
				while(prev->next != current){
					prev = prev->next;
				}
				prev->next = next;
			}
			swapped = 1;
			}
			current = next;
		}
		if (!swapped){
			break;
		}
	}
	
	printed = *start;
	while (printed != NULL){
		printf("Name: %s\t", printed->name);
		printf("Priority ID: %d\n", printed->prioNum);
		printed = printed->next;
	}
}

// DESCENDING ORDER

void DaddData(struct candidate **head){
	struct candidate *newNode, *temp, *test;
	int i;
	
	for (i = 0; i < 10; i++){
		newNode = (struct candidate*)malloc(sizeof(struct candidate));
		newNode->next = NULL;
	
		fflush(stdin);
		printf("Enter name: "); gets(newNode->name);
		printf("Enter no. of Points Garnered: "); scanf("%d", &newNode->points);
		printf("\n");
	
		if (*head == NULL){
			*head = newNode;
		}
		else{
			temp = *head;
			while(temp->next != NULL){
				temp = temp->next;
			}
			temp->next = newNode;
		}
	}
	
}

void DsortData (struct candidate **head){
	
	printf("======= POINT RANKINGS ========\n");
	
	struct candidate *current, *temp, *printed;
	int step, swapped;
	
	for (step = 0; step < 9; step++){
		current = *head;
		swapped = 0;
		while (current->next != NULL){
			struct candidate *next = current->next;
			if (current->points < next->points){
				temp = next->next;
				next->next = current;
				current->next = temp;
				
				if (current == *head){
				*head = next;
			}else{
				struct candidate *prev = *head;
				while(prev->next != current){
					prev = prev->next;
				}
				prev->next = next;
			}
			swapped = 1;
			}
			current = next;
		}
		if (!swapped){
			break;
		}
	}
	
	printed = *head;
	while (printed != NULL){
		printf("Name: %s\t", printed->name);
		printf("Priority ID: %d\n", printed->points);
		printed = printed->next;
	}
}

