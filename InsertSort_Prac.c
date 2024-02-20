#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int numberList[10];

struct insertList{
	char student[100];
	int ID; 
	struct insertList *next;
	struct insertList *prev;
};

struct insertList *head = NULL;

void arrayAdd(int numberList[]);
void arraySort(int numberList[]);
void arrayPrint(int numberList[]);

void listAdd(struct insertList **head);
void listSort(struct insertList **head);
void listPrint(struct insertList **head);

int main(){
	printf("Array Insertion Sort\n\n");
	arrayAdd(numberList);
	arraySort(numberList);
	arrayPrint(numberList);
	printf("\nPress Any Key to Continue"); getche();
	system("cls");
	printf("Linked List Insertion Sort\n\n");
	listAdd(&head);
	listSort(&head);
	listPrint(&head);
	printf("\nPress Any Key to Continue"); getche();
	system("cls");
	printf("\nInsertion Sorting Test: Complete\n");
}

// ARRAY VERSION

void arrayAdd(int numberList[]){
	int i, numberEntry;
	for (i = 0; i<10; i++){
		printf("Enter a number: "); scanf(" %d", &numberEntry);
		numberList[i] = numberEntry;
	}
}
void arraySort(int numberList[]){
	int run, temp;
	
	for (run = 1; run < 10; run++){
		int x = run;
		while(x > 0 && numberList[x-1] > numberList[x]){
			temp = numberList[x-1];
			numberList[x-1] = numberList[x];
			numberList[x] = temp;
			x--;
		}
	}
}

void arrayPrint(int numberList[]){
	printf("Sorted Array List: ");
	int p;
	for (p = 0; p<10; p++){
		printf(" %d ", numberList[p]);
	}
}

// LINKED LIST VERSION


void listAdd(struct insertList **head){
	struct insertList *newNode, *temp;
	int a; 
	for (a = 0; a < 10; a++){
		newNode = (struct insertList*)malloc(sizeof(struct insertList));
		newNode->next = NULL;
		fflush(stdin);
		printf("Enter student name: "); gets(newNode->student);
		printf("Enter ID number: "); scanf("%d", &newNode->ID);
		printf("\n");
		
		if (*head == NULL){
			*head = newNode;
			newNode->prev = NULL;
		}
		else{
			temp = *head;
			while(temp->next != NULL){
				temp = temp->next;
			}
			temp->next = newNode;
			newNode->prev = temp;
		}
	}
}

void listSort(struct insertList **head) {
    struct insertList *sorted = NULL;
    struct insertList *current = *head;

    while (current != NULL) {
        struct insertList *next = current->next;

        if (sorted == NULL || sorted->ID > current->ID) {
            // Insert at the beginning of the sorted list
            current->next = sorted;
            current->prev = NULL;
            if (sorted != NULL) {
                sorted->prev = current;
            }
            sorted = current;
        } else {
            // Traverse the sorted list to find the correct position
            struct insertList *temp = sorted;
            while (temp->next != NULL && temp->next->ID < current->ID) {
                temp = temp->next;
            }
            // Insert current between temp and temp->next
            current->next = temp->next;
            current->prev = temp;
            if (temp->next != NULL) {
                temp->next->prev = current;
            }
            temp->next = current;
        }

        current = next;
    }

    *head = sorted; // Update the head to point to the sorted list
}

void listPrint(struct insertList **head){
	struct insertList *current = *head;
	printf("%-25s %-25s\n", "Student Name", "Student ID Number");
    printf("==========================================\n");
	while(current!=NULL){
		printf("%-25s %-25d\n", current->student, current->ID);
		current = current->next;
	}
}

