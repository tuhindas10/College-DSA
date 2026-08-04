//first missing positive
#include<stdio.h>
#include<stdlib.h>

int main() {
    int elements, xor1 = 0, xor2 = 0, missing;
    printf("Enter number of elements : ");
    scanf("%d", &elements);

    int *arr = (int *) malloc((elements-1) * sizeof(int *));

    printf("Enter elements from 1 to %d except one number: ", elements);
    for(int i=0; i<elements-1; i++) {
        scanf("%d", (arr+i));
        xor1 = xor1 ^ (i+1);
        xor2 = xor2 ^ (*(arr+i));
    }

    xor1 ^= elements;
    missing = xor1 ^ xor2;
    printf("The missing element is: %d\n", missing);

    free(arr);
    return 0;
}