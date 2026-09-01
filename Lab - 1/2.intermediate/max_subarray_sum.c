//max Subarray Sum
#include<stdio.h>

//Kadanes Algorithm
int maxSum(int arr[], int n) {
    int sum = 0;
    for(int i=0; i<n; i++) {
        if(sum < 0) sum = 0;
        sum += arr[i];
    }

    return sum;
}

int main() {
    int arr[] = {2,-4,3,-2,4,1};
    int n = sizeof(arr) / sizeof(int);

    int maxSubSum = maxSum(arr, n);
    printf("max subarray sum = %d\n", maxSubSum);
    return 0; 
}