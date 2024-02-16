#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int numArray[10];

struct numNodes{
	int num;
	struct numNodes *next;
};
struct numNodes *head = NULL;


void arraySearch(int numArray[]);
void listAdd(struct numNodes** head);
void listSearch(struct numNodes** head);

int main(){
	
	printf("Array Version Time!\n\n");
	arraySearch(numArray);
	printf("\nPress any key to continue: "); getche();
	system("cls");
	printf("Linked List Version Time!\n\n");
	listSearch(&head);
	printf("\nPress any key to continue: "); getche();
	system("cls");
	printf("\nLinear Search Algorithm Practice Successful\n");
	
	return 0; 
}

void arraySearch(int numArray[]){
	int numEntry, numSearch, found = 0;
	int i, j;
	for (i = 0; i < 10; i++){
		printf("Add a number entry: "); scanf("%d", &numEntry);
		numArray[i] = numEntry;
	}
	printf("\nFind Number within Array: "); scanf("%d", &numSearch);
	for (j = 0; j < 10; j++){
		if (numArray[j] == numSearch){
			printf("\nArray Element %d found at index %d!\n", numSearch, j);
			found = 1;
			break;
		}
		else{
			continue;
		}
	}
	if (found == 0){
		printf("\nElement not found!");
	}
}

void listAdd(struct numNodes** head){
	int x;
	for (x = 0; x < 10; x++){
		struct numNodes *newNode, *temp;
		newNode = (struct numNodes*)malloc(sizeof(struct numNodes));
		newNode->next = NULL;
		
		printf("Enter a number entry: "); scanf("%d", &newNode->num);
		
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

void listSearch(struct numNodes** head){
	listAdd(head);
	int listSearcher, foundListNum = 0, nodeNum = 1;
	struct numNodes *current = *head;
	
	printf("Find Number within Linked List: "); scanf("%d", &listSearcher);
	
	while(current != NULL){
		if (current->num == listSearcher){
			printf("\nList Element %d found at Node Number: %d!", current->num, nodeNum);
			foundListNum = 1;
			break;
		}
		else{
			nodeNum++;
			current = current->next;
		}
	}
	if (foundListNum == 0){
		printf("\nElement not found!");
	}
}

