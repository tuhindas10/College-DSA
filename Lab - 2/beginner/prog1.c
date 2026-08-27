#include<stdio.h>

void traverse(int arr[], int size) {
    for(int i=0; i<size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertion(int arr[], int size) {
    int num, pos;
    printf("Enter number and position: ");
    scanf("%d %d", &num, &pos);

    for(int i=size-1; i>=pos-1; i--) {
        arr[i+1] = arr[i];
    }
    arr[pos-1] = num;

    printf("done!\n");
    //size++
}

void deletion(int arr[], int size){
    int pos;
    printf("Enter position : ");
    scanf("%d", &pos);
    for(int i=pos; i<size; i++) {
        arr[i-1] = arr[i];
    }

    printf("done!\n");
    //size--
}

int linearSearch(int arr[], int size) {
    int num;
    printf("Enter number : ");
    scanf("%d", &num);

    for(int i=0; i<size; i++) {
        if(arr[i] == num){
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[100];
    int size;
    printf("Enter number of elements : ");
    scanf("%d", &size);

    printf("Enter elements : ");
    for(int i=0; i<size; i++) {
        scanf("%d", &arr[i]);
    }

    while(1) {
        int choice;
        printf("Enter choice : ");
        scanf("%d", &choice);

        if(choice == 1){
            insertion(arr, size);
            size++;
        }else if(choice == 2) {
            deletion(arr, size);
            size--;
        }else if(choice == 3) {
            int idx = linearSearch(arr, size);
            printf("%d", idx);
        }
        else if(choice == 4) {
            traverse(arr, size);
        }else if(choice == 5) {
            printf("Exit!\n");
            break;
        }else {
            printf("Invalid Input ! \n");
        }
    }

    return 0;
}