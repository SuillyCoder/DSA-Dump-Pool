#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


// THE TASK:
//Create a program that integrates binary search trees
// Ask it to let the user enter a specific amount of data:
// Then ask the user to endlessly enter data until such time, they can then browse the data.


//ADDITIONAL BONUS TASKS:


//Let the user input data by choice. Let the choose how many data they ought to input.
//Allow for the user to delete numbers via searching.
//Let the deletion, addition, and browsing have separate functions.


struct node{
   int number;
   struct node *left, *right;
};


struct queue{
   struct node *data;
   struct queue *next;
};




//FUNCTION DECLARATION SEGMENT


struct node *root = NULL;
struct queue *head = NULL;


struct node *createNode(int num);
struct node *insertNode(struct node *node, int number);
void breadthFirst(struct node *root);
void preOrder (struct node *root);
void inOrder (struct node *root);
void postOrder (struct node *root);




void addNumbers();
struct node *deleteNumbers(struct node *root, int deletor);
void searchMenu();


int nodeCount, DFchoice, number, deletor, i;
char choice, browseChoice, keepSearching, exitor;


// MAIN DRIVER CODE


int main(){
do{
	system("cls");
   printf("BINARY SEARCH TREE PRACTICE\n\nWhat would you want to do?\n\n");
   printf("[A]dd Numbers\n[D]elete Data\n[S]earch Data\n[T]erminate Program\n\n");
   printf("Your Choice: "); scanf(" %c", &choice);


   while (toupper(choice)!= 'A' && toupper(choice)!= 'D' && toupper(choice)!='S' && toupper(choice)!='T'){
       printf("Enter a valid choice: "); scanf(" %c", &choice);
   }


   switch(toupper(choice)){
       case 'A':
       		system("cls");
           addNumbers();
           printf("\n\nPress any key to continue: "); scanf(" %c", &exitor);
           break;
       case 'D':
       		system("cls");
           printf("Enter the number to delete: "); scanf("%d", &deletor);
           deleteNumbers(root, deletor);
           printf("\nRecord Deleted Successfully!");
           printf("\n\nPress any key to continue: "); scanf(" %c", &exitor);
           break;
       case 'S':
           do{
           	   system("cls");
               searchMenu();
               printf("\nSearch through tree again?? [Y/N]: "); scanf(" %c", &keepSearching);
               while (toupper(keepSearching) != 'Y' && toupper(keepSearching) != 'N'){
                   printf("Enter a valid choice: "); scanf(" %c", &keepSearching);
               }
           }while(toupper(keepSearching) != 'N');
           break;
   }
}while(toupper(choice) != 'T');

  	system("cls");
   printf("\n\n======== PROGRAM TERMINATED =======\n\n");
   return 0;
}


// FUNCTION DEFINITION SEGMENT


struct node *createNode(int num){
   struct node *newNode = (struct node*)malloc(sizeof(struct node));
   newNode->number =num;
   newNode->left = NULL, newNode->right = NULL;
   return newNode;
}


struct node *insertNode(struct node *node, int number){
   if (node==NULL){
       return createNode(number);
   }
   else if (number < node->number){
       node->left = insertNode(node->left, number);
   }
   else{
       node->right = insertNode(node->right, number);
   }
   return node;
}


void preOrder (struct node *root){
   if (root != NULL){
       printf(" %d ", root->number);
       preOrder(root->left);
       preOrder(root->right);
   }
}


void inOrder (struct node *root){
   if (root != NULL){
       inOrder(root->left);
       printf(" %d ", root->number);
       inOrder(root->right);
   }
}


void postOrder (struct node *root){
   if (root != NULL){
       postOrder(root->left);
       postOrder(root->right);
       printf(" %d ", root->number);
   }
}


// INDIVIDUAL CHOICE FUNCTIONS


void addNumbers(){
   printf("Enter the amount of numbers you want to insert: "); scanf("%d", &nodeCount);


   for (i = 0; i < nodeCount; i++){
       printf("Enter a number: "); scanf("%d", &number);
       root = insertNode(root, number);
   }
}


struct node *deleteNumbers(struct node *root, int deletor){
  if (root == NULL){
   printf("\nNothing to delete!\n\n");
   return root;
  }


   // Finding the roots


   if (root->number > deletor){
       (root->left) = deleteNumbers(root->left, deletor);
       return root;
   }
   else if (root->number < deletor){
       (root->right) = deleteNumbers(root->right, deletor);
       return root;
   }


   // CASE 2 DELETION (Delete Node with 1 Child)


   if (root->left == NULL){
       struct node *temp = root->right;
       free(root);
       return temp;
   }
   else if (root->right == NULL){
       struct node *temp = root->left;
       free(root);
       return temp;
   }


   // CASE 3 DELETION (Delete Node with 2 Children)


   else{
       struct node *higherUp = root;


       struct node *lowerRank = root->right;
       while(lowerRank->left != NULL){
           higherUp = lowerRank;
           lowerRank = lowerRank->left;
       }


       if (higherUp != root){
           higherUp->left = lowerRank->right;
       }
       else{
           higherUp->right = lowerRank->right;
       }


       root->number = lowerRank->number;
       free(lowerRank);
       return root;
   }
}
void searchMenu(){


   printf("Which type of search would you like to perform?\n\n");
   printf("[B]readth First Search\n[D]epth First Search\n\nYour Choice: ");
   scanf(" %c", &browseChoice);


   while (toupper(browseChoice) != 'D' && toupper(browseChoice) != 'B' && toupper(browseChoice) != 'T'){
       printf("Enter a valid choice: "); scanf(" %c", &browseChoice);
   }
   if (toupper(browseChoice) == 'B'){
       breadthFirst(root);
   }
   else if (toupper(browseChoice) == 'D'){
       printf("\nWhich Depth-First method do you want to search them in?");
       printf("\n\n[1] Pre Order\n[2] In Order\n[3] Post Order");
       printf("\n\nYour Choice: "); scanf("%d", &DFchoice);


       switch(DFchoice){
           case 1:
               printf("\nPre Order DFS Results: ");
               preOrder(root);
               break;
           case 2:
               printf("\nIn Order DFS Results: ");
               inOrder(root);
               break;
           case 3:       
               printf("\nPost Order DFS Results: ");
               postOrder(root);
               break;
          
       }
   }
}
// BFS CODE


void enQueue(struct queue **head, struct node *number){
   struct queue *newNode, *temp;
   newNode = (struct queue*)malloc(sizeof(struct queue));
   newNode->data = number; newNode->next = NULL;


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
struct node *deQueue(struct queue **head){
   if (*head == NULL){
       return NULL;
   }
   else{
       struct node *item = (*head)->data;
       struct queue *temp = *head;
       (*head) = (*head)->next;
       free(temp);
       return item;
   }
}


void breadthFirst(struct node *root){
   printf("\nBreadth First Search Results: ");
   if (root == NULL){
       return;
   }
   else{
       struct queue *q = NULL;
       enQueue(&q, root);
       while (q != NULL){
           struct node *current = deQueue(&q);
           printf(" %d ", current->number);
           if (current->left != NULL){
               enQueue(&q, current->left);
           }
           if (current->right != NULL){
               enQueue(&q, current->right);
           }
       }
   }
}


