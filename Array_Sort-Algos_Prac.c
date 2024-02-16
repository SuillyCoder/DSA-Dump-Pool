#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>

int bubbleArray[10];
int selectArray[10];

void bubbleSort(int bubbleArray[]);
void selectSort(int insertArray[]);

int main(){
	
	printf("Time to sort out this mess...");
	sleep(3); system("cls");
	printf("Exhibit A: Bubble Sort\n\n");
	bubbleSort(bubbleArray);
	printf("Exhibit B: Selection Sort\n\n");
	selectSort(selectArray);
	
	return 0;
}

void bubbleSort(int bubbleArray[]){
	int numEntry, run, temp, i, s, p;
	
	for (i = 0; i < 10; i++){
		printf("Enter a number: "); scanf("%d", &numEntry);
		bubbleArray[i] = numEntry;
	}
	
	printf("\nSorting in Progress. Please wait a moment...\n");
	sleep(3);
	
	for (run = 0; run < 9; run++){
		for (s = 0; s < 9-run; s++){
		if (bubbleArray[s] > bubbleArray[s+1]){
				temp = bubbleArray[s];
				bubbleArray[s] = bubbleArray[s+1];
				bubbleArray[s+1] = temp;
			}
		else{
			continue;
			}
		}
	}

	printf("Bubble Sorted Array: ");
	for (p = 0; p < 10; p++){
		printf("  %d  ", bubbleArray[p]);
	}
	
	fflush(stdin);
	printf("\n\nPress any key to continue: "); getche();
	system("cls");
}

void selectSort(int selectArray[]){
	int numEntryTwo, step, min, index, tempTwo, e, f, d;
	
	for (e = 0; e < 10; e++){
		printf("Enter a number: "); scanf("%d", &numEntryTwo);
		selectArray[e] = numEntryTwo;
	}
	
	printf("\nSorting in Progress. Please wait a moment...\n");
	sleep(3);
	
	for (step = 0; step < 9; step++){
		min = selectArray[step];
		printf("\nCurrent Min Value: %d", min);
		for (f = step; f < 10; f++){
			if (min > selectArray[f]){
				min = selectArray[f];
				index = f;
			}
			else{
				continue;
			}
		}
	}
	
	printf("\nSelection Sorted Array: ");
	for (d = 0; d < 10; d++){
		printf("  %d  ", selectArray[d]);
	}
	
	printf("\n\nPress any key to continue: "); getche();
	system("cls");
}
