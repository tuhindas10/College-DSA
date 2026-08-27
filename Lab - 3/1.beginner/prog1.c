#include <stdio.h>

void transpose(int rows, int cols, int nonzero, int a[][3], int b[][3]){
    b[0][0] = cols;
    b[0][1] = rows;
    b[0][2] = nonzero;

    int k = 1;

    for (int j = 0; j < cols; j++)
    {
        for (int i = 1; i <= nonzero; i++)
        {
            if (a[i][1] == j)
            {
                b[k][0] = a[i][1];
                b[k][1] = a[i][0];
                b[k][2] = a[i][2];
                k++;
            }
        }
    }

    printf("\nTranspose of sparse matrix:\n");

    for (int i = 0; i <= nonzero; i++)
    {
        printf("%d %d %d\n", b[i][0], b[i][1], b[i][2]);
    }
}
int main()
{
    int rows, cols, nonzero;

    printf("Enter sparse matrix in 3-tuple format\n");

    // Read rows, columns and number of non-zero elements
    scanf("%d %d %d", &rows, &cols, &nonzero);

    int rowOfmatrix = nonzero + 1;
    int a[rowOfmatrix][3], b[rowOfmatrix][3];
    a[0][0] = rows;
    a[0][1] = cols;
    a[0][2] = nonzero;

    for (int i = 1; i <= nonzero; i++)
    {
        scanf("%d %d %d", &a[i][0], &a[i][1], &a[i][2]);
    }

    transpose(rows, cols, nonzero, a, b);
    return 0;
}