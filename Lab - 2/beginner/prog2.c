#include<stdio.h>

int nonZeroElements(int size, int arr[][size]) {
    int count = 0;
    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++) {
            if(arr[i][j] != 0) count++;
        }
    }
    return count;
}

void upperTriangular(int size, int arr[][size]){
    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++) {
            if(i < j) printf("%d ", arr[i][j]);
        }
    }
    printf("\n");
}

void eleAboveDiag(int size, int arr[][size]) {
    for(int i=0; i<size-1; i++) {
        for(int j=0; j<size; j++) {
            if(i == j) {
                printf("%d %d ", arr[i][j+1], arr[i+1][j]);
            }
        }
    }
    printf("\n");
}

int main() {
    int size;
    printf("Enter size : ");
    scanf("%d", &size);
    int matrix[size][size];

    printf("Enter elements : ");
    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("***** MENU *****\n");
    printf("1.Find the no.of nonzero elements \n");
    printf("2.Display upper triangular matrix\n");
    printf("3.Display the elements of just above and below the main diagona\n");
    printf("4.Exit\n");

    while(1) {
        int choice;
        printf("Enter your choice : ");
        scanf("%d", &choice);

        if(choice == 1) {
            int nonZeroes = nonZeroElements(size, matrix);
            printf("%d\n", nonZeroes);
        }else if(choice == 2) {
            upperTriangular(size, matrix);
        }else if(choice == 3) {
            eleAboveDiag(size, matrix);
        }else if(choice == 4) {
            printf("Exit\n");
            break;
        }else {
            printf("Invalid Input !");
        }
    }
    return 0;
}