#include<stdio.h>

void compareNumbers(int *a, int *b) {
    if(*a > *b) {
        printf("%d is smaller than %d\n", *b, *a);
    }else {
        printf("%d is smaller than %d\n", *a, *b);
    }
}

int main() {
    int x = 90;
    int y = 80;
    compareNumbers(&x, &y);
    return 0;
}