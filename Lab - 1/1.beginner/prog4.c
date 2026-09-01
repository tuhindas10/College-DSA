#include<stdio.h>

void sumComplex(int a, int b, int c, int d) {
    int real = a + c;
    int img = b + d;
    printf("%d + %di\n", real, img);
}

void mulComplex(int *a, int *b, int *c, int *d){
    int real = ((*a) * (*c)) - ((*b) * (*d));
    int img = ((*a) * (*d)) + ((*b) * (*c));
    printf("%d + %di\n", real, img);
}

struct Complex {
    int real;
    int img;
};

int main() {
    struct Complex c1;
    struct Complex c2;

    printf("Enter first real : ");
    scanf("%d", &c1.real);
    printf("Enter first img : ");
    scanf("%d", &c1.img);

    printf("Enter second real : ");
    scanf("%d", &c2.real);
    printf("Enter second img : ");
    scanf("%d", &c2.img);

    printf("*** MENU ***\n");
    printf("1. sum\n");
    printf("2. multiplication\n");
    printf("3. Exit\n");

    while(1) {
        int n;
        printf("Enter your choice : ");
        scanf("%d", &n);

        if(n == 1) {
            sumComplex(c1.real, c1.img, c2.real, c2.img);
        }else if(n == 2) {
            mulComplex(&c1.real, &c1.img, &c2.real, &c2.img);
        }else if(n == 3) {
            printf("Exit!\n");
            break;
        }else {
            printf("Not valid");
        }
    }
    return 0;
}