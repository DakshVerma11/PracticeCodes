/*Write a C program to store the data of ‘n’ employees where n is given by the user (Use dynamic memory allocation).
Code by - Daksh Verma 
Roll No - 231210036*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for Date
struct Date {
    int day, month, year;
};

// Structure for Employee
struct Employee {
    int empCode;
    char empName[50];
    float salary;
    char department[30];
    struct Date joiningDate;
};

// Function to display employee information and find max and min salary
void displayEmployeeInfo(struct Employee *employees, int n) {
    float maxSalary = employees[0].salary, minSalary = employees[0].salary;
    int maxIndex = 0, minIndex = 0;

    printf("\nEmployee Information:\n");

    for (int i = 0; i < n; i++) {
        printf("\nEmployee Code: %d\n", employees[i].empCode);
        printf("Employee Name: %s\n", employees[i].empName);
        printf("Salary: %.2f\n", employees[i].salary);
        printf("Department: %s\n", employees[i].department);
        printf("Date of Joining: %02d/%02d/%04d\n", employees[i].joiningDate.day, employees[i].joiningDate.month, employees[i].joiningDate.year);

        // Find max and min salary
        if (employees[i].salary > maxSalary) {
            maxSalary = employees[i].salary;
            maxIndex = i;
        }
        if (employees[i].salary < minSalary) {
            minSalary = employees[i].salary;
            minIndex = i;
        }
    }

    // Display max and min salary
    printf("\nEmployee with Maximum Salary:\n");
    printf("Employee Code: %d\n", employees[maxIndex].empCode);
    printf("Employee Name: %s\n", employees[maxIndex].empName);
    printf("Salary: %.2f\n", employees[maxIndex].salary);

    printf("\nEmployee with Minimum Salary:\n");
    printf("Employee Code: %d\n", employees[minIndex].empCode);
    printf("Employee Name: %s\n", employees[minIndex].empName);
    printf("Salary: %.2f\n", employees[minIndex].salary);
}

// Function to compare employees based on salary for qsort
int compareBySalary(const void *a, const void *b) {
    return ((struct Employee *)a)->salary - ((struct Employee *)b)->salary;
}

// Function to display employee records in ascending order of salary
void displayBySalary(struct Employee *employees, int n) {
    qsort(employees, n, sizeof(struct Employee), compareBySalary);

    printf("\nEmployee Records Sorted by Salary:\n");
    for (int i = 0; i < n; i++) {
        printf("\nEmployee Code: %d\n", employees[i].empCode);
        printf("Employee Name: %s\n", employees[i].empName);
        printf("Salary: %.2f\n", employees[i].salary);
        printf("Department: %s\n", employees[i].department);
        printf("Date of Joining: %02d/%02d/%04d\n", employees[i].joiningDate.day, employees[i].joiningDate.month, employees[i].joiningDate.year);
    }
}

// Function to compare employees based on joining date for qsort
int compareByDate(const void *a, const void *b) {
    return ((struct Employee *)a)->joiningDate.year - ((struct Employee *)b)->joiningDate.year;
}

// Function to display employee records in ascending order of joining date
void displayByDate(struct Employee *employees, int n) {
    qsort(employees, n, sizeof(struct Employee), compareByDate);

    printf("\nEmployee Records Sorted by Joining Date:\n");
    for (int i = 0; i < n; i++) {
        printf("\nEmployee Code: %d\n", employees[i].empCode);
        printf("Employee Name: %s\n", employees[i].empName);
        printf("Salary: %.2f\n", employees[i].salary);
        printf("Department: %s\n", employees[i].department);
        printf("Date of Joining: %02d/%02d/%04d\n", employees[i].joiningDate.day, employees[i].joiningDate.month, employees[i].joiningDate.year);
    }
}

// Function to display employee records department-wise
void displayByDepartment(struct Employee *employees, int n) {
    // Assuming department names 
    const char *departments[] = {"IT", "HR", "Finance", "Marketing", "Operations"};

    printf("\nEmployee Records Department-wise:\n");

    for (int i = 0; i < sizeof(departments) / sizeof(departments[0]); i++) {
        printf("\nDepartment: %s\n", departments[i]);
        // Display employees in the current department
    for (int j = 0; j < n; j++) {
        if (strcmp(employees[j].department, departments[i]) == 0) {
            printf("\nEmployee Code: %d\n", employees[j].empCode);
            printf("Employee Name: %s\n", employees[j].empName);
            printf("Salary: %.2f\n", employees[j].salary);
            printf("Date of Joining: %02d/%02d/%04d\n", employees[j].joiningDate.day, employees[j].joiningDate.month, employees[j].joiningDate.year);
        }
    }
  }
}

int main() {
int n;
// User input for the number of employees
printf("Enter the number of employees: ");
scanf("%d", &n);

// Dynamically allocate memory for 'n' employees
struct Employee *employees = (struct Employee *)malloc(n * sizeof(struct Employee));

// User input for employee details
for (int i = 0; i < n; i++) {
    printf("\nEnter details for Employee %d:\n", i + 1);
    printf("Employee Code: ");
    scanf("%d", &employees[i].empCode);

    printf("Employee Name: ");
    scanf("%s", employees[i].empName);

    printf("Salary: ");
    scanf("%f", &employees[i].salary);

    printf("Department: ");
    scanf("%s", employees[i].department);

    printf("Date of Joining (dd mm yyyy): ");
    scanf("%d %d %d", &employees[i].joiningDate.day, &employees[i].joiningDate.month, &employees[i].joiningDate.year);
}

int choice;

// Menu
do {
    printf("\nMenu:\n");
    printf("1. Display employee information with max and min salary\n");
    printf("2. Display employee records in ascending order according to salary\n");
    printf("3. Display employee records in ascending order according to date of joining\n");
    printf("4. Display department-wise employee records\n");
    printf("0. Exit\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            displayEmployeeInfo(employees, n);
            break;
        case 2:
            displayBySalary(employees, n);
            break;
        case 3:
            displayByDate(employees, n);
            break;
        case 4:
            displayByDepartment(employees, n);
            break;
        case 0:
            break;
        default:
            printf("Invalid choice. Please enter a valid option.\n");
    }

} while (choice != 0);

// Free dynamically allocated memory
free(employees);

return 0;
}
