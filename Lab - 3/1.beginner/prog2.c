#include <stdio.h>

void readMatrix(int a[20][3])
{
    printf("Enter rows, columns and number of non-zero elements: ");
    scanf("%d %d %d", &a[0][0], &a[0][1], &a[0][2]);

    printf("Enter row, column and element:\n");

    for (int i = 1; i <= a[0][2]; i++)
    {
        scanf("%d %d %d",&a[i][0], &a[i][1], &a[i][2]);
    }
}

void displayMatrix(int a[40][3])
{

    for (int i = 0; i <= a[0][2]; i++)
    {
        printf("%d %d %d\n", a[i][0],a[i][1],a[i][2]);
    }
}

void addMatrix(int a[20][3], int b[20][3], int c[40][3])
{
    int i = 1, j = 1, k = 1;

    // Check dimensions
    if (a[0][0] != b[0][0] || a[0][1] != b[0][1])
    {
        c[0][2] = -1;
        return;
    }

    c[0][0] = a[0][0];
    c[0][1] = a[0][1];

    while (i <= a[0][2] && j <= b[0][2])
    {
        // Same row and column
        if (a[i][0] == b[j][0] &&
            a[i][1] == b[j][1])
        {
            c[k][0] = a[i][0];
            c[k][1] = a[i][1];
            c[k][2] = a[i][2] + b[j][2];

            if (c[k][2] != 0)
                k++;

            i++;
            j++;
        }

        // Element of A comes first
        else if (a[i][0] < b[j][0] ||
                (a[i][0] == b[j][0] &&
                 a[i][1] < b[j][1]))
        {
            c[k][0] = a[i][0];
            c[k][1] = a[i][1];
            c[k][2] = a[i][2];

            k++;
            i++;
        }

        // Element of B comes first
        else
        {
            c[k][0] = b[j][0];
            c[k][1] = b[j][1];
            c[k][2] = b[j][2];

            k++;
            j++;
        }
    }

    // Copy remaining elements of A
    while (i <= a[0][2])
    {
        c[k][0] = a[i][0];
        c[k][1] = a[i][1];
        c[k][2] = a[i][2];

        k++;
        i++;
    }

    // Copy remaining elements of B
    while (j <= b[0][2])
    {
        c[k][0] = b[j][0];
        c[k][1] = b[j][1];
        c[k][2] = b[j][2];

        k++;
        j++;
    }

    c[0][2] = k - 1;
}

int main()
{
    int a[20][3], b[20][3], c[40][3];

    printf("Enter first sparse matrix:\n");
    readMatrix(a);

    printf("\nEnter second sparse matrix:\n");
    readMatrix(b);

    addMatrix(a, b, c);

    if (c[0][2] == -1)
    {
        printf("\nAddition is not possible.");
    }
    else
    {
        printf("\nAddition of sparse matrices:\n");
        displayMatrix(c);
    }

    return 0;
}