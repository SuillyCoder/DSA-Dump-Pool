#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct node{
	int number;
	struct node *left, *right;
};

struct queue {
  struct node *data;
  struct queue *next;
};


struct node *newNode (int num);
struct node *insertDaddy(struct node *node, int number);

void breadth(struct node *root);

void preOrder(struct node *root);
void inOrder(struct node *root);
void postOrder(struct node *root);


int main(){
	struct node *root = NULL;
	int i, entries, numberEntry;
	printf("Time to go Tree Hunting! Or...well...tree searching.\n");
	printf("Binary Tree Searching.\n");
	
	printf("\nEnter the number of entries: "); scanf("%d", &entries);
	 for (i = 0; i < entries; i++){
	 	printf("Enter a number: "); scanf("%d", &numberEntry);
	 	root = insertDaddy(root, numberEntry);
	 }
	 printf("\nBreadth First Search: "); breadth(root);
	 printf("\n\nDepth First Search Results: ");
	 printf("\n\tPre-Order:  "); preOrder(root);
	 printf("\n\tIn-Order:   "); inOrder (root);
	 printf("\n\tPost-Order: "); postOrder (root);
	return 0;
}

struct node *newNode (int num){
	struct node *newNode = (struct node*)malloc(sizeof (struct node));
	newNode->number = num;
	newNode->left = NULL; newNode->right = NULL;
	return newNode;
}

struct node *insertDaddy(struct node *node, int number){
	if (node == NULL){
		return newNode(number);
	}
	if (number < node->number){
		node->left = insertDaddy(node->left, number);
	}
	else{
		node->right = insertDaddy(node->right, number);
	}
	return node;
}

void preOrder(struct node *root){
	if (root !=NULL){
		printf(" %d ", root->number);
		preOrder(root->left);
		preOrder(root->right);
	}
}

void inOrder(struct node *root){
	if (root !=NULL){
		inOrder(root->left);
		printf(" %d ", root->number);
		inOrder(root->right);
	}
}

void postOrder(struct node *root){
	if (root !=NULL){
		preOrder(root->left);
		preOrder(root->right);
		printf(" %d ", root->number);
	}
}

// THIS IS GEMINI PRODUCED CODE. PROCEED WITH CAUTION

void enqueue(struct queue **head, struct node *item) {
  struct queue *newNode = malloc(sizeof(struct queue));
  newNode->data = item;
  newNode->next = NULL;
  if (*head == NULL) {
    *head = newNode;
  } else {
    struct queue *temp = *head;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = newNode;
  }
}

struct node *dequeue(struct queue **head) {
  if (*head == NULL) {
    return NULL;
  }
  struct node *item = (*head)->data;
  struct queue *temp = *head;
  *head = (*head)->next;
  free(temp);
  return item;
}

void breadth(struct node *root) {
  if (root == NULL) {
    return;
  }
  struct queue *q = NULL;
  enqueue(&q, root);
  while (q != NULL) {
    struct node *current = dequeue(&q);
    printf(" %d ", current->number);
    if (current->left != NULL) {
      enqueue(&q, current->left);
    }
    if (current->right != NULL) {
      enqueue(&q, current->right);
    }
  }
}

