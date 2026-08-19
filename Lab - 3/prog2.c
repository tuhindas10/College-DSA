//WAP to perform addition of two given sparse matrix in 3–tuple format

#include<stdio.h>

void printArray(int row, int arr[][3]) {
    for(int i=0; i<row; i++) {
        for(int j=0; j<3; j++) {
            if(arr[i][2] == 0) return;
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void addSparseMatrix(int row, int a[][3], int b[][3], int res[][3]) {
    int r = 0;

    for(int i=0; i<row; i++) {
        if(a[i][0] == b[i][0] && a[i][1] == b[i][1]) {
            res[r][0] = a[i][0];
            res[r][1] = a[i][1];
            res[r][2] = a[i][2] + b[i][2];
            r++;
        }else if(a[i][0] == b[i][0]) {
            if(a[i][1] < b[i][1]) {
                res[r][0] = a[i][0];
                res[r][1] = a[i][1];
                res[r][2] = a[i][2];
                r++;

                res[r][0] = b[i][0];
                res[r][1] = b[i][1];
                res[r][2] = b[i][2];
                r++;
            }else {
                res[r][0] = b[i][0];
                res[r][1] = b[i][1];
                res[r][2] = b[i][2];
                r++;

                res[r][0] = a[i][0];
                res[r][1] = a[i][1];
                res[r][2] = a[i][2];
                r++;
            }
        }else if(a[i][1] == b[i][1]) {
            if(a[i][0] < b[i][0]) {
                res[r][0] = a[i][0];
                res[r][1] = a[i][1];
                res[r][2] = a[i][2];
                r++;

                res[r][0] = b[i][0];
                res[r][1] = b[i][1];
                res[r][2] = b[i][2];
                r++;
            }else {
                res[r][0] = b[i][0];
                res[r][1] = b[i][1];
                res[r][2] = b[i][2];
                r++;

                res[r][0] = a[i][0];
                res[r][1] = a[i][1];
                res[r][2] = a[i][2];
                r++;
            }
        }
    }
}

int main() {
    int row;
    printf("Enter number of values : ");
    scanf("%d", &row);

    int a[row][3];
    int b[row][3];
    int resRow = 2*row;
    int res[resRow][3];
    //assign all entry to zero of res
    for(int i=0; i<resRow; i++) {
        for(int j=0; j<3; j++) {
            res[i][j] = 0;
        }
    }

    printf("Enter sparse matrix-1 in 3-tuple format : ");
    for(int i=0; i<row; i++) {
        for(int j=0; j<3; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter sparse matrix-2 in 3-tuple format : ");
    for(int i=0; i<row; i++) {
        for(int j=0; j<3; j++) {
            scanf("%d", &b[i][j]);
        }
    }

    addSparseMatrix(row, a, b, res);
    printf("Resultant Matrix in 3-tuple format : \n");
    printArray(resRow, res);

    return 0;
}