#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int numArray[10];

struct strNodes{
	char name[100];
	struct strNodes *next;
};
struct strNodes *head = NULL;

int main(){
	
	int low = 0;
	int count = sizeof(numArray)/sizeof(numArray[0]);
	int high = count-1;
	
	printf("Array Version Time!\n\n");
	arraySearch(numArray, low, high, count);
	printf("Spoiler Alert!:\n");
	printf("Linked Lists can't use a Binary Search!'\n\n");
	printf("We'll do linear search for strings instead\n\n");
	listSearch(&head);
	printf("\nLooks like you've got the slight hang of searching algorithms\n");
	return 0;
}

void arraySearch (int numArray[], int low, int high, int count){
	int numEntry, numSearch, found = 0;
	int i, j;
	for (i = 0; i < count; i++){
		printf("Add a number entry: "); scanf("%d", &numEntry);
		numArray[i] = numEntry;
	}
	printf("\nFind Number within Array: "); scanf("%d", &numSearch);
	
	while(low <= high){
		int mid = low + (high - low) / 2;
		printf("Test for Mid Value: %d\n\n", mid);
		
		if (numArray[mid] == numSearch){
			printf("Array Element %d found at index %d", numSearch, mid);
			found = 1;
			break;
		}
		else if (numArray[mid] < numSearch){
			low = mid + 1;
		}
		else{
			high = mid - 1;
		}
	}
	if (found == 0){
		printf("\nElement not found!\n");
	}
	
	printf("\n\nPress any key to continue: "); getche();
	system("cls");
}

void listAdd(struct strNodes** head){
	int x;
	for (x = 0; x < 10; x++){
		struct strNodes *newNode, *temp;
		newNode = (struct strNodes*)malloc(sizeof(struct strNodes));
		newNode->next = NULL;
		
		fflush(stdin);
		printf("Enter a name: "); gets(newNode->name);
		
		if (*head == NULL){
			*head = newNode;
		}
		else{
			temp = *head;
			while (temp->next != NULL){
				temp = temp->next;
			}
			temp->next = newNode;
		}
	}
}

void listSearch(struct strNodes** head){
	listAdd(head);
	int foundListName = 0, nodeNum = 1;
	char listSearcher[100];
	struct strNodes *current = *head;
	
	printf("\nFind name within Linked List: "); gets(listSearcher);
	
	while(current != NULL){
		if (strcmp(toupper(current->name), toupper(listSearcher))==0){
			printf("\n'%s' found in node number: %d", current->name, nodeNum);
			foundListName = 1;
			break;
		}
		else{
			nodeNum++;
			current = current->next;
		}
	}
	
	if (foundListName == 0){
		printf("\nName not found!\n\n");
	}
	
	printf("\n\nPress any key to continue: "); getche();
	system("cls");
}
