#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


//STRUCTURE AND FUNCTION SETUP


struct node{
   char input;
   struct node *left, *right, *next;
};


struct node *head = NULL;


struct node *createNode (char variables);
void inOrder (struct node *currentNode);
void pushNode(struct node *variable);
struct node *popNode();


// MAIN DRIVER CODE


int main(){
   int length = 1;
   char expression[100], expressionCopy[100];
   fflush(stdin);
   printf("Enter a bunch of variables and operators: ");
   fgets(expression, sizeof(expression), stdin);


   strcpy(expressionCopy, expression);
   char* expressionBit = strtok(expressionCopy, " ");
   char *inputs = (char*)malloc(length*sizeof(char));
   printf("\nStuff in Array: ");
   while (expressionBit != NULL){
       inputs[length-1] = *expressionBit;
       printf(" %c ", inputs[length-1]);length++;
       inputs = realloc(inputs,length * sizeof(char));
       expressionBit = strtok(NULL, " ");
   }


   struct node *x, *y, *z;
   int i;
   for (i = 0; i < length-2; i++) {
         if (inputs[i] == '+' || inputs[i] == '-' || inputs[i] == '*' || inputs[i] == '/' || inputs[i] == '='){
           printf("\nNode being created! Current Value: %c", inputs[i]);
           z = createNode(inputs[i]);
           x = popNode(); y = popNode();
           z->left = y; z->right = x;
           pushNode(z);
         }
         else{  
            z = createNode(inputs[i]);
            pushNode(z);
         }
   }
   printf("\nThe In-Order Traversal of the Expression Tree: ");
   inOrder(z);
   printf("\n");
   free(inputs);
   return 0;
}
//FUNCTION DEFINITION


struct node *createNode (char variables){
   struct node *newNode = (struct node*)malloc(sizeof(struct node));
   newNode->input = variables;
   newNode->next = NULL; newNode->left = NULL; newNode->right = NULL;


   return (newNode);
}


void inOrder (struct node *currentNode){
   if (currentNode != NULL){
       inOrder(currentNode->left);
       printf(" %c ", currentNode->input);
       inOrder(currentNode->right);
   }
}


void pushNode(struct node *variable){
   if (head == NULL){
       head = variable;
   }
   else{
       (variable)->next = head;
       head = variable;
   }
}


struct node *popNode(){
   struct node *popper = head;
   head = (head->next);
   return popper;
}



