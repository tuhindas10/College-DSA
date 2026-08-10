#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

//traverse through linkedlist
void traverse(struct Node* ptr) {
    while(ptr != NULL) {
        printf("element : %d\n", ptr->data);
        ptr = ptr->next;
    }
}

int main() {
    struct Node* head, *second, *third;

    head = (struct Node*) malloc(sizeof(struct Node));
    second = (struct Node*) malloc(sizeof(struct Node));
    third = (struct Node*) malloc(sizeof(struct Node));

    //assign values and linked the nodes
    //link head to second
    head -> data = 7;
    head -> next = second;

    //link second to third
    second -> data = 11;
    second -> next = third;

    //link third to NULL
    third -> data = 44;
    third -> next = NULL;

    traverse(head);

    return 0;

}