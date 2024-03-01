#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

 // YOUR TASK: 
 // CREATE A PROGRAM THAT'LL ASK FOR ARRAY SIZE AND ARRAY NUMBERS
 // HAVE INPUT CHOICES WHEREIN YOU EITHER DO BUBBLE, SELECTION, OR INSERTION SORT
 // HAVE AN OPTION WHEREIN THEY CAN ALSO CHANGE THE ARRAY SIZE AND NUMBERS IF THEY WANNA
 // PRACTICE FOR SORTING ALGORITHMS AND INPUT VALIDATION


 // FUNCTION SEGMENT
void printArray(int *numArray, int size);
void newData(int *numArray, int size);
void insertSort (int *numArray, int size);
void bubbleSort(int *numArray, int size);
void selectSort(int *numArray, int size);


// MAIN DRIVER CODE
 int main(){

    // INPUT VARIABLES
    int size, numbers, choice;
    char exitor;

    //FOR LOOP VARIABLES
    int e, p;

    printf("Enter the size of the array: \n");
    printf("NOTE: Size cannot be changed: ");
    scanf("%d", &size);
    int *numArray = (int*)malloc(size * sizeof(int));
    printf("\n");
    for (e = 0; e < size; e++){
        printf("Enter a number: "); scanf("%d", &numbers);
        numArray[e] = numbers;
    }

do{
    system("cls");
    printf("\nWhat do you want to do with those numbers?\n\n");
    printf("[1] PRINT OUT\n[2] ENTER NEW DATA\n[3] BUBBLE SORT\n[4] SELECTION SORT\n[5] INSERTION SORT\n[0] EXIT\n");
    printf("\nYour Choice: "); scanf("%d", &choice);

    while (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice!= 5 && choice!= 0){
        printf("Enter valid input: "); scanf(" %d", &choice);
    }

    switch(choice){
        case 1: 
            system("cls");
            printArray(numArray, size);
            printf("\n\nPress any key to continue: "); scanf(" %c", &exitor);
            break;
         case 2: 
            system("cls");
            newData(numArray, size);
            printf("\n\nPress any key to continue: "); scanf(" %c", &exitor);
            break;
         case 3: 
            system("cls");
            bubbleSort(numArray, size);
             printf("\n\nPress any key to continue: "); scanf(" %c", &exitor);
            break;
         case 4: 
            system("cls");
            selectSort(numArray, size);
             printf("\n\nPress any key to continue: "); scanf(" %c", &exitor);
            break;
         case 5: 
            system("cls");
            insertSort(numArray, size);
            printf("\n\nPress any key to continue: "); scanf(" %c", &exitor);
            break;
    }

}while(choice != 0);

    printf("\n\n=======PROPGRAM TERMINATED=======\n\n");

    return 0;
 }

 // FUNCTION DEFINITIONS

 void printArray(int *numArray, int size){
    int i;
    printf("\nList of Entered Numbers: ");
    for (i = 0; i < size; i++){
        printf(" %d ", numArray[i]);
    }
 }

 void newData (int *numArray, int size){
    int newNumber, a;
    for (a = 0; a < size; a++){
        printf("Enter a number: "); scanf("%d", &newNumber);
        numArray[a] = newNumber;
    }
 }

void insertSort (int *numArray, int size){
    printf("\nSELECTION SORT IN PROGRESS....\n\n");
    int temp, i, s, p, f;
    int *insertArray = (int*)malloc(size*sizeof(int));

    for (i = 0; i < size; i++){
        insertArray[i] = numArray[i];
    }

    for (s = 1; s < size; s++){
        for (f = s; f > 0; f--){
            if (insertArray[f-1] > insertArray[f]){
                temp = insertArray[f-1];
                insertArray[f-1] = insertArray[f];
                insertArray[f] = temp;
            }
        }
        printf("Pass Number %d:  ",s);
        for (p = 0; p < size; p++){
            printf(" %d ", insertArray[p]);
        }
        printf("\n");
    }
}

void bubbleSort(int *numArray, int size){
    printf("BUBBLE SORT IN PROGRESS....\n\n");
    int temp, i, r, c, p;
    int *bubbleArray = (int*)malloc(size*sizeof(int));

    for (i = 0; i < size; i++){
        bubbleArray[i] = numArray[i];
    }

    for (r = 0; r < size-1; r++){
        printf("\nPass Number %d: \n\n", r+1);
        for (c = 0; c < size-(r+1); c++){
            if (bubbleArray[c] > bubbleArray[c+1]){
                temp = bubbleArray[c];
                bubbleArray[c] = bubbleArray[c+1];
                bubbleArray[c+1] = temp;
            }
            for (p = 0; p < size; p++){
                printf(" %d ", bubbleArray[p]);
            }
            printf("\n");
        }
    }
}

void selectSort(int *numArray, int size){
    printf("SELECTION SORT IN PROGRESS....\n\n");
    int temp, min;
    int i, b, s, p;
    int *selectArray = (int*)malloc(size*sizeof(int));

    for (i = 0; i < size; i++){
        selectArray[i] = numArray[i];
    }

    for (b = 0; b < size-1; b++){
        int index = b;
        min = selectArray[b];
        for (s = b; s < size; s++){
            if (selectArray[s] < min){
                min = selectArray[s];
                index = s;
            }
        }
        
        temp = selectArray[b];
        selectArray[b] = min;
        selectArray[index] = temp;
        printf("Pass Number %d:  ",b+1);
        for (p = 0; p < size; p++){
                printf(" %d ", selectArray[p]);
            }
            printf("\n");
    }
}