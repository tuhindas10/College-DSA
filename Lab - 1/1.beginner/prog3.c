#include<stdio.h>
#include<string.h>

struct employee {
    int empID;
    char name[100];
    char designation[100];
    float basic_salary;
    int hra;
    int da;
    float gross_salary;
};

int main() {
    struct employee emp[100]; 
    int n;
    printf("Enter no. of employees : ");
    scanf("%d", &n);

    //store employee information

    for(int i=0; i<n; i++) {
        printf("Enter employee %d information : \n", i+1);

        //employee id
        printf("Enter employee ID : ");
        scanf(" %d", &emp[i].empID);

        //name
        printf("Enter name : ");
        scanf(" %[^\n]", emp[i].name);

        //designation
        printf("Enter Designation : ");
        scanf(" %[^\n]", emp[i].designation);

        //salary
        printf("Enter salary : ");
        scanf("%f", &emp[i].basic_salary);

        //HRA
        printf("Enter hra : ");
        scanf("%d", &emp[i].hra);

        //DA
        printf("Enter da : ");
        scanf("%d", &emp[i].da);

        emp[i].gross_salary = emp[i].basic_salary + emp[i].hra + emp[i].da;
    }

    //return employee information
    printf("Employee Information : \n");
    for(int i=0; i<n; i++) {
        printf("Information of %d employee : \n", i+1);
        printf("emp-id : %d\n", emp[i].empID);
        printf("Name : %s\n", emp[i].name);
        printf("Designation : %s\n", emp[i].designation);
        printf("Basic Salary : %f\n", emp[i].basic_salary);
        printf("HRA : %d %%\n", emp[i].hra);
        printf("DA : %d %%\n", emp[i].da);
        printf("Gross Salary : %f\n", emp[i].gross_salary);
    }
    return 0;
}