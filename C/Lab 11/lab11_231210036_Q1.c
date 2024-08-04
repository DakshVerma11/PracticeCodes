/*Write a program to read RollNo, Name, Address, Age & marks in physics, C, math in 1st semester of three students in CSE. Store the records into a file std.txt located at a location (PATH fo directory). Display the student details with average marks achieved (use data files record I/O)Write a program to display the details of the student whose name is entered by the user. Use the structure defined above to make an array of the students.
Code by - Daksh Verma 
Roll No - 231210036*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct student {
    char address[50], name[30];
    int roll, age;
    struct marks {
        float math, physics, C;
    } marks;
};

void inputIntoFile(struct student s, FILE *f) {
    fprintf(f, " %d , %s , %s , %d , %f , %f , %f\n", s.roll, s.name, s.address, s.age, s.marks.math, s.marks.physics, s.marks.C);
}

void displayFile() {
    FILE *f;
    struct student s;
    f = fopen("/home/daksh/Desktop/Daksh/Coding/C/Lab 11/Q1.txt", "r");
    if (f == NULL) {
        printf("File doesn't exist or cannot be opened!");
        return;
    }

    char line[256]; // Assuming each line in the file is not longer than 255 characters

    while (fgets(line, sizeof(line), f) != NULL) {
        sscanf(line, "%d , %[^,], %[^,], %d , %f , %f , %f", &s.roll, s.name, s.address, &s.age, &s.marks.math, &s.marks.physics, &s.marks.C);
        printf("\n\nRoll - %d\nName - %s\nAddress - %s\nAge - %d\nMarks\n\tMath - %.2f \n\tPhysics - %.2f\n\tC - %.2f\n\nAverage = %.2f ", s.roll, s.name, s.address, s.age, s.marks.math, s.marks.physics, s.marks.C, (s.marks.physics + s.marks.math + s.marks.C) / 3);
    }
    fclose(f);
}



int main() {
    int choice;
    do {
        printf("\n\nWhat do you want to do?:\n1. Add Student Details\n2. Display Student Details\n3. Exit\n");
        scanf("%d", &choice);
	printf("\nChoice = %d\n\n",choice);
        switch (choice) {
            case 1: {
                struct student s;
                FILE *f;
                int n;
                printf("\nEnter the number of students: ");
                scanf("%d", &n);
                f = fopen("Q1.txt", "a");
                if (f == NULL) {
                    printf("File cannot be opened!");
                    return 1;
                }
                for (; n > 0; n--) {
                    printf("\n\nEnter Name: ");
                    scanf(" %[^\n]", s.name);
                    printf("Enter Address (without \",\"): ");
                    scanf(" %[^\n]", s.address);
                    printf("Enter Roll: ");
                    scanf(" %d", &s.roll);
                    printf("Enter Age: ");
                    scanf(" %d", &s.age);
                    printf("Enter Marks in Math: ");
                    scanf(" %f", &s.marks.math);
                    printf("Enter Marks in Physics: ");
                    scanf(" %f", &s.marks.physics);
                    printf("Enter Marks in C: ");
                    scanf(" %f", &s.marks.C);
                    inputIntoFile(s, f);
                }
                fclose(f);
                break;
            }
            case 2: {
                displayFile();
                break;
            }
            case 3: {
                printf("\nExiting Program\n");
                break;
            }
            default: {
                printf("\nUnexpected Input\n");
                break;
            }
        }
    } while (choice != 3);
    return 0;
}
	
	 
