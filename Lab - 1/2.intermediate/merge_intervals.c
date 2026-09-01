#include<stdio.h>

int max(int a, int b) {
    if(a >= b) return a;
    else return b;
}

void printArray(int arr[][2], int rows) {
    for(int i=0; i<rows; i++) {
        if(arr[i][0] == 0 && arr[i][1] == 0 && arr[i+1][0] == 0 && arr[i+1][1] == 0) break;
        printf("[%d, %d] ", arr[i][0], arr[i][1]);
    }
    printf("\n");
}

void sortArray(int rows, int arr[][2]) {
    for(int i=0; i<rows-1; i++) {
        for(int j=0; j<rows-i-1; j++) {
            if(arr[j][0] == arr[j+1][0]) {
                if(arr[j][1] > arr[j+1][1]) {
                    int temp = arr[j+1][1];
                    arr[j+1][1] = arr[j][1];
                    arr[j][1] = temp;
                    continue;
                }

                if(arr[j][0] > arr[j+1][0]) {
                    int temp = arr[j+1][0];
                    arr[j+1][0] = arr[j][0];
                    arr[j][0] = temp;
                }
            }
        }
    }
}

void mergeIntervals(int rows, int arr[][2]) {
    int st = arr[0][0];
    int end = arr[0][1];
    int ans[rows][2];
    int k = 0;
    //assign all values to zero
    for(int i=0; i<rows; i++) {
        ans[i][0] = 0;
        ans[i][1] = 0;
    }

    for(int i=1; i<rows; i++) {
        if(arr[i][0] <= end) {
            end = max(end, arr[i][1]);
        }else {
            ans[k][0] = st;
            ans[k][1] = end;
            st = arr[i][0];
            end = arr[i][1];
            k++;
        }
    }
    ans[k][0] = st;
    ans[k][1] = end;

    printArray(ans, rows);
}

int main() {
    int rows;
    printf("Enter no. of rows : ");
    scanf("%d", &rows);

    int arr[rows][2];
    printf("Enter elements : \n");
    for(int i=0; i<rows; i++) {
        scanf("%d %d", &arr[i][0], &arr[i][1]);
    }

    printf("merged intervals : \n");
    mergeIntervals(rows, arr);

    return 0;
}