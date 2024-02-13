#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
struct record *head = NULL;

struct record{
	char name[100];
	char movie[100];
	int ticketNum;
	struct node *prev;
};

void addWatcher(struct record** head);
void deleteWatcher(struct record** head);
void displayWatchers(struct record** head);

int main(){
	
	int choice;
	
do{
	printf("Welcome to the cinema\n\n");
	printf("[1] Add Watcher Entry\n[2] Delete Watcher Entry\n[3] Display Watcher Entries\n[4] Exit\n\n");
	printf("Your Choice: "); scanf("%d", &choice);
	switch (choice){
		case 1: 
			system("cls");
			addWatcher(&head);
			break;
		case 2: 
			system("cls");
			deleteWatcher(&head);
			break;
		case 3: 
			system("cls");
			displayWatchers(&head);
			break;
	}
}while (choice != 4);

system("cls");
printf("\nMovie Booking Queue Closed!\n\nHave Fun Watching!\n\n");
	return 0;
}


void addWatcher(struct record** head){
	
	char again;
	
	do{
		struct record *watcher, *temp;
		watcher = (struct record*)malloc(sizeof(struct record));
		watcher->prev = NULL;
	
		fflush(stdin);
		printf("Enter your full name: "); gets(watcher->name);
		printf("Enter name of movie: "); gets(watcher->movie);
		printf("Enter number of tickets: "); scanf("%d", &watcher->ticketNum);
	
		if (*head == NULL){
			*head = watcher;
			printf("\n%d tickets for %s reserved for %s.\nRecord Saved Successfully!\n\n", watcher->ticketNum, watcher->movie, watcher->name);
			}
		else{
			temp = *head;
			while(temp->prev != NULL){
				temp = temp-> prev;
			}
			temp->prev = watcher;
			printf("\n%d tickets for %s reserved for %s.\nRecord Saved Successfully!\n\n", watcher->ticketNum, watcher->movie, watcher->name);
		}
		fflush(stdin);
		printf("Again? [Y/N]: "); scanf("%c", &again);
		while (toupper(again) != 'Y' && toupper(again) != 'N'){
			printf("Enter a valid choice: ");  scanf(" %c", &again);
		}
	} while(toupper(again) == 'Y');
	system("cls");
}

void deleteWatcher(struct record** head){
	struct record *deletor;
	
	if (*head == NULL){
		printf("No movie watcher entries to delete!\n");
	}
	else{
		deletor = *head;
		printf("Watcher Entry: \n");
		printf("\n%d tickets for %s reserved for %s.\nRecord Saved Successfully!\n\n", deletor->ticketNum, deletor->movie, deletor->name);
		(*head) = (*head)->prev;
		free(deletor);
		printf("Record Successfully Deleted!");
	}
	fflush(stdin);
	printf("\nPress any key to return: "); getche();
	system("cls");
}

void displayWatchers(struct record** head){
	
	struct record *current = *head;
	int i;
	
	if (*head == NULL){
        printf("No listed movie watchers");
    }
    else{
    	printf("%-30s %-30s %-30s\n", "Full Name", "Movie Name", "Number of Tickets");
        printf("==============================================================================================\n");
        while(current != NULL){
            printf("%-30s %-30s %-30d\n",current->name, current->movie, current->ticketNum);
            current=current->prev;
        }
    }
    fflush(stdin);
	printf("\nPress any key to return: "); getche();
	system("cls");
}

