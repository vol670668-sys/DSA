#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure definition
struct EMPLOYEE {
    char Emp_name[50];
    int Emp_id;
    char Dept_name[50];
    float Salary;
};

// Function prototypes
void readEmployees(struct EMPLOYEE *e, int n);
void displayEmployees(struct EMPLOYEE *e, int n);
float totalSalaryByDept(struct EMPLOYEE *e, int n, char dept[]);

int main() {
    struct EMPLOYEE *emp;
    int n, i;
    char dept[50];

    printf("Enter number of employees: ");
    scanf("%d", &n);

    // Dynamic allocation for n employees
    emp = (struct EMPLOYEE *)malloc(n * sizeof(struct EMPLOYEE));
    if (emp == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Read and display employee details
    readEmployees(emp, n);
    displayEmployees(emp, n);

    // Salary computation for a department
    printf("\nEnter department name to calculate total salary: ");
    scanf("%s", dept);

    float total = totalSalaryByDept(emp, n, dept);
    printf("Total salary of employees in %s department = %.2f\n", dept, total);

    free(emp); // Free allocated memory
    return 0;
}

// Function to read employee data
void readEmployees(struct EMPLOYEE *e, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("\nEnter details for Employee %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", (e + i)->Emp_name);
        printf("ID: ");
        scanf("%d", &(e + i)->Emp_id);
        printf("Department: ");
        scanf("%s", (e + i)->Dept_name);
        printf("Salary: ");
        scanf("%f", &(e + i)->Salary);
    }
}

// Function to display employee data
void displayEmployees(struct EMPLOYEE *e, int n) {
    int i;
    printf("\n%-15s %-10s %-15s %-10s\n", "Name", "ID", "Department", "Salary");
    printf("------------------------------------------------------\n");
    for (i = 0; i < n; i++) {
        printf("%-15s %-10d %-15s %-10.2f\n",
               (e + i)->Emp_name,
               (e + i)->Emp_id,
               (e + i)->Dept_name,
               (e + i)->Salary);
    }
}

// Function to calculate total salary by department
float totalSalaryByDept(struct EMPLOYEE *e, int n, char dept[]) {
    float sum = 0.0;
    int i;
    for (i = 0; i < n; i++) {
        if (strcmp((e + i)->Dept_name, dept) == 0) {
            sum += (e + i)->Salary;
        }
    }
    return sum;
}