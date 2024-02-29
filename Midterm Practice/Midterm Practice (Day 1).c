#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct node{
    char name[100];
    int age;
    char course[100];
    int ID;
    char mobileNum[100];

    struct node *next;
};


void appendNode(struct node **head);
void browseNodes(struct node **head);
void changeNode(struct node **head);
void deleteNode(struct node **head);

int main(){
	struct node *head = NULL;
    char choice;
do{
    system("cls");
    printf("=== STUDENT DASHBOARD === \n");
    printf("\n[A]PPEND\n[B]ROWSE\n[C]HANGE\n[D]ELETE\n[E]XIT");
    printf("\n\nYour choice: "); scanf("%c", &choice);
    
    while(toupper(choice) != 'A' && toupper(choice) != 'B' &&  toupper(choice) != 'C' &&  toupper(choice) != 'D' &&  toupper(choice) != 'E'){
    	printf("Enter a valid input: "); scanf(" %c", &choice);
	}

    switch(toupper(choice)){
        case 'A':
            system("cls");
            appendNode(&head);
            printf("\n\nRedirecting to main menu in 3 seconds...");
            sleep (3);
            break;
        case 'B': 
            system("cls");
            browseNodes(&head);
            printf("\n\nRedirecting to main menu in 7 seconds...");
            sleep (7);
            break;
        case 'C':
            system("cls");
            changeNode(&head);
            printf("\n\nRedirecting to main menu in 3 seconds...");
            sleep (3);
            break;
        case 'D':
            system("cls");
            deleteNode(&head);
            printf("\n\nRedirecting to main menu in 3 seconds...");
            sleep (3);
            break;
    }
}while(toupper(choice) != 'E');

system("cls");
printf("\n=========== EXITED STUDENT DASHBOARD ===========\n");

    return 0;
}




void appendNode(struct node **head){
    struct node *newNode, *temp;
    newNode = (struct node*)malloc(sizeof(struct node));
	newNode->next = NULL;
	
	fflush(stdin);
    printf("Enter Student Name: "); gets(newNode->name);
    printf("Enter Age: "); scanf("%d", &newNode->age);
    fflush(stdin);
    printf("Enter Course: "); gets(newNode->course);
    printf("Enter Student ID No.: "); scanf("%d", &newNode->ID);
    fflush(stdin);
    printf("Enter Mobile Number: "); gets(newNode->mobileNum);

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
    fflush(stdout);
}

void browseNodes(struct node **head){
    struct node *current = *head;

	if (*head == NULL){
		printf("No student records to show\n");
	}
	else{
		printf(" =========== STUDENT INFORMATION DASHBOARD ============= \n\n\n");
    	printf("%-25s %-10s %-25s %-20s %-19s\n", "Student Name", "Age", "Course Undertaken", "Student ID Number", "Mobile Number");

   		 while(current != NULL){
        	printf("%-25s %-10d %-25s %-20d %-19s\n", current->name, current->age, current->course, current->ID, current->mobileNum);
        	current = current->next;
    	}
	}
}


void changeNode(struct node **head){
  int searchNum, foundIt, choice;
  char changeCourse[100], changeNum[100];
  int changeAge;
  struct node *current = *head;
  
  if (*head == NULL){
  	printf("No student records currently in database!\n\n");
  }
  else{
  	 printf("Enter student ID Number: "); scanf("%d", &searchNum);

  while(current != NULL){
    if (current->ID == searchNum){
    	foundIt = 1;
        printf("Student Entry Found! :\n\n");
        printf("%-25s %-10s %-25s %-20s %-19s\n", "Student Name", "Age", "Course Undertaken", "Student ID Number", "Mobile Number");
        	printf("%-25s %-10d %-25s %-20d %-19s\n", current->name, current->age, current->course, current->ID, current->mobileNum);

        printf("\n\nWhat would you like to change?\n\n");
        printf("[1] AGE\n[2] COURSE \n[3] MOBILE NUMBER\n\nYour Choice: "); scanf("%d", &choice);

        switch(choice){
            case 1: 
            	fflush(stdin);
                printf("\nEnter new age: "); scanf("%d", &changeAge);
                printf("\nSuccessfully changed %d to %d", current->age, changeAge);
                current->age = changeAge;
                break;
            case 2: 
             	fflush(stdin);
                printf("\nEnter new course: "); gets(changeCourse);
                printf("\nSuccessfully changed %s to %s", current->course, changeCourse);
                strcpy(current->course, changeCourse);
                break;
            case 3: 
             	fflush(stdin);
                printf("\nEnter new mobile number: "); gets(changeNum);
                printf("\nSuccessfully changed %s to %s", current->mobileNum, changeNum);
                strcpy(current->mobileNum, changeNum);
                break;
        }
        break;
    }
    else{
        current= current->next;
        foundIt = 0;
    }
  }
  if (foundIt == 0){
        printf("\nStudent record not found!\n");
    }
  }
}


void deleteNode(struct node **head){
    int numDeletor, foundIt = 0;
    struct node *deletor = *head;
    
    if (*head == NULL){
    	printf("No student records to be deleted!\n\n");
	}
	else{
		
    printf("Enter student ID no. to search and delete: "); scanf("%d", &numDeletor);

    if (deletor->ID == numDeletor){
        foundIt = 1;
        deletor = *head;
        *head = (*head)->next;
        free(deletor);
        printf("Successfully deleted entry!");
    }
    else{
        struct node *current = *head;
        while (current->next != NULL){
            if (current->next->ID == numDeletor){
                foundIt = 1;
                deletor = current->next;
                current->next = (current->next)->next;
                free(deletor);
                printf("Successfully deleted entry!");
                break;
            }
            else{
                current = current->next;
            }
        }
    }

    fflush(stdout);

    if (foundIt == 0){
        printf("Student Entry not found!");
  		 }
	}
}
