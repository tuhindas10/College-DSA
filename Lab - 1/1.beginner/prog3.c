#include <stdio.h>

struct Employee
{
    int emp_id;
    char name[50];
    char designation[50];
    float basic_salary;
    float hra_percent;
    float da_percent;
};

int main()
{
    struct Employee emp[100];
    int n, i;
    float hra, da, gross_salary;

    printf("Enter no. of employees: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("\nEnter employee %d information:\n", i + 1);

        printf("Enter Employee ID: ");
        scanf("%d", &emp[i].emp_id);

        printf("Enter Name: ");
        scanf(" %[^\n]", emp[i].name);

        printf("Enter Designation: ");
        scanf(" %[^\n]", emp[i].designation);

        printf("Enter Basic Salary: ");
        scanf("%f", &emp[i].basic_salary);

        printf("Enter HRA %%: ");
        scanf("%f", &emp[i].hra_percent);

        printf("Enter DA %%: ");
        scanf("%f", &emp[i].da_percent);
    }

    printf("\n\nEmployee Information:\n");

    for (i = 0; i < n; i++)
    {
        hra = (emp[i].basic_salary * emp[i].hra_percent) / 100;
        da = (emp[i].basic_salary * emp[i].da_percent) / 100;
        gross_salary = emp[i].basic_salary + hra + da;

        printf("\nEmployee %d\n", i + 1);
        printf("Employee ID: %d\n", emp[i].emp_id);
        printf("Name: %s\n", emp[i].name);
        printf("Designation: %s\n", emp[i].designation);
        printf("Basic Salary: %.2f\n", emp[i].basic_salary);
        printf("HRA %%: %.2f%%\n", emp[i].hra_percent);
        printf("DA %%: %.2f%%\n", emp[i].da_percent);
        printf("Gross Salary: %.2f\n", gross_salary);
    }

    return 0;
}