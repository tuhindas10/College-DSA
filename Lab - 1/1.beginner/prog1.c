#include<stdio.h>

void compareNumbers(int *a, int *b) {
    if(*a > *b) {
        printf("%d is smaller than %d\n", *b, *a);
    }else if(*a == *b) {
        printf("Both numbers are same\n");
    }else {
        printf("%d is smaller than %d\n", *a, *b);
    }
}

int main() {
    int x, y;
    printf("Enter two Numbers : ");
    scanf("%d %d", &x, &y);
    compareNumbers(&x, &y);
    return 0;
}