#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

bool prime(int num) {
    if(num < 2) {
        return false;
    }
    for(int i=2; i<num; i++) {
        if(num % i == 0) {
            return false;
        }
    }

    return true;
}

int sumOfPrimeNumbers(int n) {
    int *arr, sum = 0;
    arr = (int*) malloc(n * sizeof(int));
    for(int i=0; i<n; i++) {
        scanf("%d", (arr+i));
        if(prime(*(arr+i))) {
            sum += *(arr+i);
        }
    }
    free(arr);
    arr = NULL;
    return sum;
}

int main() {
    int n;
    printf("Enter size of array : ");
    scanf("%d", &n);
    int s = sumOfPrimeNumbers(n);
    printf("Sum = %d\n", s);

    return 0;
}