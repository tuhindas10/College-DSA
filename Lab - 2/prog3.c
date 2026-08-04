#include<stdio.h>

int nonZeroEle(int r, int c, int arr[][c]) {
    int count = 0;
    for(int i=0; i<r; i++) {
        for(int j = 0; j<c; j++) {
            if(arr[i][j] != 0) count++;
        }
    }

    return count;
}

void printArray(int r, int c, int arr[][c]) {
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void tuple(int r, int c, int arr[][c]) {
    int count = nonZeroEle(r, c, arr);
    int threeTuple[count][3];

    int row = 0;
    int col = 0;

    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            if(arr[i][j] != 0) {
                threeTuple[row][col] = i;
                col++;
                threeTuple[row][col] = j;
                col++;
                threeTuple[row][col] = arr[i][j];
                col = 0;
                row++;
            }
        }
    }

    printArray(count, 3, threeTuple);
    
}

int main() {
    int r, c;
    printf("Enter size of sparse matrix : ");
    scanf("%d %d", &r, &c);

    int sparse[r][c];
    printf("Enter elements of sparse matrix : ");
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            scanf("%d", &sparse[i][j]);
        }
    }

    printf("Sparse matrix in 3-Tuple format : \n");
    tuple(r, c, sparse);

    return 0;
}