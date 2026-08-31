#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    int xpow;
    struct Node *next;
};

void printList(struct Node *ptr, int pow) {
    while(ptr->next != NULL) {
        printf("%dx^%d + ", ptr->data, pow);
        ptr = ptr->next;
        pow--;
    }
    printf("%dx^%d", ptr->data, pow);
    printf("\n");
}

struct Node *creatingList(int maxpow) {
    struct Node *head,*temp;
    head = NULL;
    temp = NULL;
    
    for(int i=maxpow; i>=0; i--) {
        struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter the coefficient of degree %d: \n", i);
        scanf("%d", &newNode->data);
        newNode->xpow = i;
        newNode->next = NULL;
        
        if(head == NULL) {
            head = newNode;
            temp = head;
        }else{
            temp->next = newNode;
            temp = newNode;
        }
    }

    return head;
}

struct Node * multiplication(struct Node *ptr1, struct Node *ptr2) {
    struct Node *p1 = ptr1;
    struct Node *p2 = ptr2;

    while(p1->next != NULL) {
        if(p1->xpow == p2->xpow) {
            p1->data = p1->data + p2->data;
            p1 = p1->next;
            p2 = p2->next;
        }else {
            p1 = p1->next;
        }
    }
    p1->data = p1->data + p2->data;
    return ptr1;
}

int main() {
    struct Node *head1, *head2;
    head1 = (struct Node*)malloc(sizeof(struct Node));
    head2 = (struct Node*)malloc(sizeof(struct Node));

    int pow1, pow2;
    printf("Polynomial-1: \n");
    printf("Enter the Maximum power of x: ");
    scanf("%d", &pow1);
    head1 = creatingList(pow1);

    printf("Polynomial-2: \n");
    printf("Enter the Maximum power of x: ");
    scanf("%d", &pow2);
    head2 = creatingList(pow2);

    if(pow1 > pow2) {
        head1 = multiplication(head1, head2);
        printList(head1, pow1);
    }else{
        head2 = multiplication(head2, head1);
        printList(head2, pow2);
    }
    return 0;
}