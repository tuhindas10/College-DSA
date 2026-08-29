#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node{
    int data;
    struct Node *next;
};

//print Linked List
void printList(struct Node *ptr) {
    while(ptr->next != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("%d -> ", ptr->data);
    printf("NULL\n");
}

//creating the node
struct Node *createList(int n) {
    struct Node *head, *temp;
    head = NULL;
    temp = NULL;

    for(int i=0; i<n; i++) {
        //creating node
        struct Node * newNode;
        newNode = (struct Node*)malloc(sizeof(struct Node));

        //assign value to node
        printf("Enter data for node %d: ", i+1);
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        //connecting nodes
        if(head == NULL) {
            head = newNode;
            temp = head;
        }else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    return head;
}

//insertion of node
struct Node *insertNode(struct Node *head) {
    struct Node *newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter data : ");
    scanf("%d", &newNode->data);

    printf("1.At beginning\n");
    printf("2.At end\n");
    printf("3.In between\n");

    int flag = 0;
    while(!flag) {
        int choice;
        printf("Enter position of Node : ");
        scanf("%d", &choice);
        struct Node *temp = head;

        switch(choice) {
            case 1:
                newNode->next = head;
                head = newNode;
                flag = 1;
                break;
            case 2:
                temp = head;
                while(temp->next != NULL) {
                    temp = temp->next;
                }
                temp->next = newNode;
                newNode->next = NULL;
                flag = 1;
                break;
            case 3:
                int position;
                printf("Enter position : ");
                scanf("%d", &position);
                
                for(int i=1; i<position-1; i++) {
                    temp = temp->next;
                }
                newNode->next = temp->next;
                temp->next = newNode;
                flag = 1;
                break;
            default:
                printf("Invalid Input !\n");
        }
    }
    printList(head);
    return head;
}

//deletion of node
    struct Node *deleteNode(struct Node *head) {

    printf("1.from beginning\n");
    printf("2.from end\n");
    printf("3.In between\n");

    int flag = 0;
    while(!flag) {
        int choice;
        printf("Enter position of Node : ");
        scanf("%d", &choice);
        struct Node *ptr, *temp;
        switch(choice) {
            case 1:
                temp = head;
                head = head->next;
                free(temp);
                flag = 1;
                break;
            case 2:
                ptr = head;
                temp = head->next;
                while(temp->next != NULL) {
                    ptr = ptr->next;
                    temp = temp->next;
                }
                ptr->next = NULL;
                free(temp);
                flag = 1;
                break;
            case 3:
                ptr = head;
                temp = head->next;
                int position;
                printf("Enter position : ");
                scanf("%d", &position);

                for(int i=1; i<position-1; i++) {
                    ptr = ptr->next;
                    temp = temp->next;
                }
                ptr->next = temp->next;
                temp->next = NULL;
                free(temp);
                flag = 1;
                break;
            default :
                printf("Invalid Input !\n");
        
        }
    }
    printList(head);
    return head;
}

int search(struct Node *head, int target) {
    struct Node *temp;
    int position = 0;
    temp = head;
    while(temp->next != NULL) {
        if(temp->data == target) return position+1;
        temp = temp->next;
        position++;
    }
    return -1;
}

//count number of nodes
int countNodes(struct Node *head) {
    struct Node *ptr = head;
    int count = 0;
    while(ptr->next != NULL) {
        ptr = ptr->next;
        count++;
    }
    count++;
    return count;
}

//free nodes
void freeNodes(struct Node *ptr) {
    struct Node *temp = ptr;
    if(temp->next == NULL) {
        free(temp);
        return;
    }else{
        ptr = ptr->next;
        free(temp);
        temp = ptr;
    }
}

int main() {
    int n;
    printf("Enter number of nodes : ");
    scanf("%d", &n);

    //creating the linkedlist
    struct Node *head = createList(n);

    printf("******* MENU *******\n");
    printf("1.Insert a node at specific position \n");
    printf("2.Deletion of an element from specific position\n");
    printf("3.Count nodes\n");
    printf("4.Traverse the linked list \n");
    printf("5.Search an element\n");
    printf("6.Exit\n");

    while(true) {
        int choice;
        printf("Enter your choice : ");
        scanf("%d", &choice);
        if(choice == 1) {
            head = insertNode(head);
        }else if(choice == 2) {
            head = deleteNode(head);
        }else if(choice == 3){
            int count = countNodes(head);
            printf("Number of nodes : %d\n", count);
        }else if(choice == 4){
            printList(head);
        }else if(choice == 5){ //LAB -> 2
            int target, pos;
            printf("Enter number : ");
            scanf("%d", &target);
            pos = search(head, target);
            printf("%d is at position %d\n", target, pos);
        }else if(choice == 6){
            printf("Exit !\n");
            break;
        }else {
            printf("Invalid Input !");
        }
    }

    //free up memory
    freeNodes(head);
    return 0; 
}