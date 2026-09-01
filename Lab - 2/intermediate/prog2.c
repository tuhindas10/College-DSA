#include<stdio.h>

void spiralOrder(int rows, int cols, int matrix[][cols]) {
    int m = rows;
    int n = cols;

    int tr = 0;
    int tc = 0;
    int er = m-1;
    int ec = n-1;

    while(tr <= er && tc <= ec) {
        //top
        for(int i=tc; i<=ec; i++) {
            printf("%d ",matrix[tr][i]);
        }

        //right
        for(int i=tr+1; i<=er; i++) {
            printf("%d ",matrix[i][ec]);
        }
            
        //bottom
        if(tr == er) break;
        for(int i=ec-1; i>=tc; i--) {
            printf("%d ",matrix[er][i]);
        }

        //left
        if(tc == ec) break;
        for(int i=er-1; i>=tr+1; i--) {
            printf("%d ",matrix[i][tc]);
        }

        tr++; er--;
        tc++; ec--;
    }
}

int main() {
    int rows, cols;
    printf("Enter rows and cols : ");
    scanf("%d %d", &rows, &cols);

    int matrix[rows][cols];
    printf("Enter elements : ");
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("matrix in spiral order : ");
    spiralOrder(rows, cols, matrix);
    printf("\n");
    return 0;
}