// WAP to perform transpose of a given sparse matrix in 3-tuple format

#include<stdio.h>

int rowsForTuple(int row, int col, int arr[][col]) {
    int count = 0;
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            if(arr[i][j] != 0) count++;
        }
    }

    return count;
}

void printArray(int row, int col, int arr[][col]) {
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void threeTuple(int row, int col, int trans[][col]) {
    int count = rowsForTuple(row, col, trans);
    int threeTuple[count][3];

    int r = 0, c = 0;
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++) {
            if(trans[i][j] == 0) continue;
            else {
                threeTuple[r][c] = i;
                c++;
                threeTuple[r][c] = j;
                c++;
                threeTuple[r][c] = trans[i][j];
                c = 0;
                r++;
            }
        }
    }

    printArray(count, 3, threeTuple);
 
}

int main() {
    int row, col;
    printf("Enter rows and columns : ");
    scanf("%d %d", &row, &col);

    int matrix[row][col];
    int trans[col][row];

    printf("Enter elements : ");
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            scanf("%d", &matrix[i][j]);
            //transpose
            trans[j][i] = matrix[i][j];
        }
    }
    printf("Transpose of given sparse matrix in 3-Tuple format : \n");
    threeTuple(col, row, trans);

    return 0;
}


