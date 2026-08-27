#include <stdio.h>

void readPolynomial(int p[], int degree)
{
    int i;

    printf("Enter coefficients from x^0 to x^%d:\n", degree);

    for (i = 0; i <= degree; i++)
    {
        printf("Coefficient of x^%d: ", i);
        scanf("%d", &p[i]);
    }
}

void addPolynomial(int p1[], int p2[], int sum[], int degree)
{
    for (int i = 0; i <= degree; i++)
    {
        sum[i] = p1[i] + p2[i];
    }
}

void displayPolynomial(int p[], int degree)
{
    for (int i = degree; i >= 0; i--)
    {
        if (p[i] != 0)
        {
            if (i != degree && p[i] > 0)
                printf(" + ");

            if (i == 0)
                printf("%d", p[i]);
            else if (i == 1)
                printf("%dx", p[i]);
            else
                printf("%dx^%d", p[i], i);
        }
    }

    printf("\n");
}

int main()
{
    int p1[20], p2[20], sum[20];
    int degree;

    printf("Enter the degree of the polynomial: ");
    scanf("%d", &degree);

    printf("\nEnter first polynomial:\n");
    readPolynomial(p1, degree);

    printf("\nEnter second polynomial:\n");
    readPolynomial(p2, degree);

    addPolynomial(p1, p2, sum, degree);

    printf("\nFirst Polynomial: ");
    displayPolynomial(p1, degree);

    printf("Second Polynomial: ");
    displayPolynomial(p2, degree);

    printf("Sum of Polynomials: ");
    displayPolynomial(sum, degree);

    return 0;
}