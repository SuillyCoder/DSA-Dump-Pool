#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct node{
	int numberEntry;
	struct node *left;
	struct node *right;
};

struct queue {
  struct node *data;
  struct queue *next;
};

void createRoot(struct node **root);
void leftNode(struct node *root);
void rightNode(struct node *root);

void breadth(struct node *root);

void preOrder(struct node *root);
void inOrder(struct node *root);
void postOrder(struct node *root);

int main(){
	struct node *root = NULL;
	
	printf("We love the earth; we love TREES!\n\n");
	
	createRoot(&root);
	leftNode(root);
	rightNode(root);
	leftNode(root->left);
	rightNode(root->left);
	leftNode(root->right);
	rightNode(root->right);
	printf("\nBreadth First Search Results: ");
	breadth(root);
	printf("\n\nDepth First Search Results: ");
	printf("\n\tPre-Order Results:  "); preOrder(root);
	printf("\n\tIn-Order Results:   "); inOrder(root);
	printf("\n\tPost-Order Results: "); postOrder(root);
	
	return 0;
}

void createRoot(struct node **root){
	if (*root != NULL) {
    	printf("Root already exists!\n");
    	return;
  	}

	struct node *newNode = (struct node*)malloc(sizeof(struct node));
	newNode->right = NULL; newNode->left = NULL;
	printf("Enter a number: "); scanf("%d", &newNode->numberEntry);
	
	*root = newNode;
	
	printf("Successfully Implemented %d as the root!\n\n", newNode->numberEntry);
}

void leftNode(struct node *root){
	if (root->left != NULL) {
		printf("Left child already exists!\n");
    	return;
 	 }
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->right = NULL; newNode->left = NULL;
	printf("Enter a number: "); scanf("%d", &newNode->numberEntry);
	
	root->left = newNode;
	
	printf("Successfully Implemented %d as a left child!\n\n", newNode->numberEntry);
}

void rightNode(struct node *root){
	if (root->right != NULL){
		printf("Right child already exists!");
		return;
	}
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->right = NULL; newNode->left = NULL;
	printf("Enter a number: "); scanf("%d", &newNode->numberEntry);
	
	root->right = newNode;
	
	printf("Successfully Implemented %d as a right child!\n\n", newNode->numberEntry);
}

void inOrder(struct node *root){
	if (root == NULL){
		return;
	}
	inOrder(root->left);
	printf(" %d ", root->numberEntry);
	inOrder(root->right);
}

void preOrder(struct node *root){
	if (root == NULL){
		return;
	}
	printf(" %d ", root->numberEntry);
	preOrder(root->left);
	preOrder(root->right);
}

void postOrder(struct node *root){
	if (root == NULL){
		return;
	}
	postOrder(root->left);
	postOrder(root->right);
	printf(" %d ", root->numberEntry);
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
    printf(" %d ", current->numberEntry);
    if (current->left != NULL) {
      enqueue(&q, current->left);
    }
    if (current->right != NULL) {
      enqueue(&q, current->right);
    }
  }
}

