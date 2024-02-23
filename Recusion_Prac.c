#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

int factorial(int num);
int fibonacci(int i);
int sum(int i);

void addData(int *numArray[], int size);
void sortData(int *numArray[], int size);
void printData(int *numArray[], int size);

int run = 1;

int main(){
	int number, fibbNum, i, size;
	char choice;
	
do{
	system("cls");
		
	printf("\nIn order to understand recursion, one must understand recursion\n");
	
	printf("\nEnter a number: "); scanf("%d", &number);
	
	printf("\nWhat do you want to do with that number?\n\n");
	printf("[A] Sum\n[B] Factorial\n[C] Fibonnaci\n[D] All of the Above\n[E] Quit Program\n\n"); 
	printf("Enter your choice: "); scanf(" %c", &choice);

	while(toupper(choice) != 'A' && toupper(choice) != 'B' &&toupper(choice) != 'C' && toupper(choice) != 'D'  && toupper(choice) != 'E'){
		printf("Enter a valid choice: "); scanf(" %c", &choice);
	}
	
	switch(toupper(choice)){
		case 'A':
			printf("The sum of all numbers preceeding %d is: %d\n", number, sum(number));
			printf("\n\nPress any letter to continue or press 'E' to quit "); scanf(" %c", &choice);
			break;
		case 'B': 
			printf("The factorial of %d is: %d\n", number, factorial(number));
			printf("\n\nPress any letter to continue or press 'E' to quit "); scanf(" %c", &choice);
			break;
		case 'C': 
			printf("Fibbonaci Sequence: ");
				for (i = 0; i < number; i++){
			printf(" %d ", fibonacci(i));
			}
			printf("\n\nPress any letter to continue or press 'E' to quit "); scanf(" %c", &choice);
			break;
		case 'D':
			printf("The sum of all numbers preceeding %d is: %d\n", number, sum(number));
			printf("The factorial of %d is: %d\n", number, factorial(number));
			printf("Fibbonaci Sequence: ");
				for (i = 0; i < number; i++){
			printf(" %d ", fibonacci(i));
			}
			printf("\n");
			printf("\n\nPress any letter to continue or press 'E' to quit "); scanf(" %c", &choice);
			break;
	}
	
}while(toupper(choice)!= 'E');

	system("cls");
	char justGoBack;
	printf("\n======= RECURSION TEST 1: SUCCESSFUL =======\n");
	printf("\n         Time for the next test.... \n\n");
	sleep(2);
	system("cls");
	
	printf("Enter size for array: "); scanf("%d", &size);
	printf("\n");
	int numArray = (int*)malloc(size * sizeof(int));
	addData(numArray, size);
	printf("\nSorting in progress. Pleast wait...\n\n"); sleep(3);
	sortData(numArray, size);
	printData(numArray, size);
	fflush(stdin);
	printf("\n\nPress any letter to continue: "); scanf(" %c", &justGoBack);
	system("cls");
	printf("\n======= RECURSION TEST 2: SUCCESSFUL =======\n");
	printf("\n        Recursion Exercise: COMPLETE.... \n\n");
	
	return 0;
}

// RECURSION TEST SECTOR 1

int factorial (int num){
	if (num != 1){
		return num * factorial(num-1);
	}
	else{
		return num;
	}
}

int fibonacci(int i){
	if (i <= 1){
		return i;
	}
	else{
		return(fibonacci(i-1) + fibonacci(i-2));
	}
}

int sum (int num){
	if (num != 1){
		return num + sum(num-1);
	}
	else{
		return num;
	}
}

// RECURSION TEST SECTOR 2

void addData(int *numArray[], int size){
	int a, number;
	for (a = 0; a < size; a++){
		printf("Add a number: "); scanf("%d", &number);
		numArray[a] = number;
	}
}

void printData(int *numArray[], int size){
	int p;
	printf("\nSorted Set: ");
	for (p = 0; p < size; p++){
		printf(" %d ", numArray[p]);
	}
}

void sortData(int *numArray[], int size){
	int s, d, temp;
	if (size == 1){
		return;
	}
	int swapCount = 0;
	
	for (s = 0; s < size-1; s++){
		if (numArray[s] > numArray[s+1]){
			temp = numArray[s+1];
			numArray[s+1] = numArray[s];
			numArray[s] = temp;
			swapCount++;
		}
	}
	
	printf("Run Number %d: ", run);
	run++;
	for (d = 0; d < size; d++){
		printf(" %d ", numArray[d]);
	}
	printf("\n");
	
	if (swapCount == 0){
		return;
	}
	
	sortData(numArray, size);
}
