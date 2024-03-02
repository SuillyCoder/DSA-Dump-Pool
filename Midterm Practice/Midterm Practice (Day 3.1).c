#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// THE TASK:
//Create a program that integrates binary search trees
// Ask it to let the user enter a specific amount of data: 
// Then ask the user to endlessly enter data until such time, they can then browse the data. 

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

// MAIN DRIVER CODE

int main(){
    int nodeCount, DFchoice, number, i;
    char choice, exitor;
    printf("Enter the amount of numbers you want to insert: "); scanf("%d", &nodeCount);

    for (i = 0; i < nodeCount; i++){
        printf("Enter a number: "); scanf("%d", &number);
        root = insertNode(root, number);
    }

do{
	system("cls");
    printf("\nNodes inserted! How do you want to find them??\n\n");
    printf("[B]readth First Search\n[D]epth First Search\n[T]erminate Program\n\nYour Choice: "); 
    scanf(" %c", &choice);

    while (toupper(choice) != 'D' && toupper(choice) != 'B' && toupper(choice) != 'T'){
        printf("Enter a valid choice"); scanf(" %c", &choice);
    }
    if (toupper(choice) == 'B'){
    	system("cls");
        breadthFirst(root);
        printf("\n\nPress any key to continue: "); scanf(" %c", &exitor);
    }
    else if (toupper(choice) == 'D'){
        printf("\nWhich Depth-First method do you want to search them in?");
        printf("\n\n[1] Pre Order\n[2] In Order\n[3] Post Order");
        printf("\n\nYour Choice: "); scanf("%d", &DFchoice);

        switch(DFchoice){
            case 1: 
            	system("cls");
                printf("\nPre Order DFS Results: ");
                preOrder(root);
                printf("\n\nPress any key to continue: "); scanf(" %c", &exitor);
                break;
            case 2: 
            	system("cls");
                printf("\nIn Order DFS Results: ");
                inOrder(root);
                 printf("\n\nPress any key to continue: "); scanf(" %c", &exitor);
                break;
            case 3:     
				system("cls");   
                printf("\nPost Order DFS Results: ");
                postOrder(root);
                printf("\n\nPress any key to continue: "); scanf(" %c", &exitor);
                break;
            
        }
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
