#include<stdio.h>

void printArray(int n, int arr[][n]) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    } 
    printf("\n");
}

void rotateImage(int n, int arr[][n]) {
    int ans[n][n];
    //transpose
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            ans[i][j] = arr[j][i];
        }
    }

    //reverse each rows
    for(int i=0; i<n; i++) {
        for(int j=0; j<n/2; j++) {
            int temp = ans[i][n-j-1];
            ans[i][n-j-1] = ans[i][j];
            ans[i][j] = temp;
        }
    }

    //print the array
    printArray(n, ans);
}

int main() {
    int n;
    printf("Enter size of array : ");
    scanf("%d", &n);
    int arr[n][n];

    printf("Enter elements : ");
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    printf("Rotate Image : \n");
    rotateImage(n, arr);
    return 0;
}