/*Write a program to display the details of the student whose name is entered by the user. Use the structure defined above to make an array of the students.
Code by - Daksh Verma 
Roll No - 231210036*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Structure to represent Date
struct Date {
    int day, month, year;
};

// Structure to represent Marks
struct Marks {
    float english, maths, physics, chemistry, computers;
};

// Structure to represent Student
struct Student {
    int rollNumber;
    char firstName[50];
    char lastName[50];
    struct Marks marks;
    char gender;
    struct Date dob;
};

// Function to display student details
void displayStudent(struct Student s) {
    printf("Roll Number: %d\n", s.rollNumber);
    printf("Name: %s %s\n", s.firstName, s.lastName);
    printf("Marks: English=%.2f, Maths=%.2f, Physics=%.2f, Chemistry=%.2f, Computers=%.2f\n",
           s.marks.english, s.marks.maths, s.marks.physics, s.marks.chemistry, s.marks.computers);
    printf("Gender: %c\n", s.gender);
    printf("Date of Birth: %d/%d/%d\n", s.dob.day, s.dob.month, s.dob.year);
    printf("\n");
}

// Function to calculate aggregate marks
float calculateAggregate(struct Marks marks) {
    return (marks.english + marks.maths + marks.physics + marks.chemistry + marks.computers) / 5.0;
}

// Function to display students with less than 40% aggregate
void displayBelow40Percent(struct Student students[], int n) {
    printf("Students with less than 40%% aggregate:\n");
    for (int i = 0; i < n; i++) {
        float aggregate = calculateAggregate(students[i].marks);
        if (aggregate < 40.0) {
            displayStudent(students[i]);
        }
    }
}

// Function to calculate class average
float calculateClassAverage(struct Student students[], int n) {
    float totalAggregate = 0;
    for (int i = 0; i < n; i++) {
        totalAggregate += calculateAggregate(students[i].marks);
    }
    return totalAggregate / n;
}

// Function to display student details based on date of birth
void displayStudentsByDOB(struct Student *students, int n) {
    // Sort the students based on Date of Birth in ascending order
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (students[j].dob.year > students[j + 1].dob.year ||
                (students[j].dob.year == students[j + 1].dob.year &&
                 students[j].dob.month > students[j + 1].dob.month) ||
                (students[j].dob.year == students[j + 1].dob.year &&
                 students[j].dob.month == students[j + 1].dob.month &&
                 students[j].dob.day > students[j + 1].dob.day)) {
                // Swap students
                struct Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }

    // Display students in ascending order of Date of Birth
    printf("\nStudent records in ascending order of Date of Birth:\n");
    printf("Roll No\tName\t\t\tDOB\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%s %s\t%d-%d-%d\n", students[i].rollNumber, students[i].firstName, students[i].lastName,
               students[i].dob.day, students[i].dob.month, students[i].dob.year);
    }
}

// Function to delete a student record by last name
void deleteByLastName(struct Student students[], int *n, const char lastName[]) {
    for (int i = 0; i < *n; i++) {
        if (strcmp(students[i].lastName, lastName) == 0) {
            for (int j = i; j < *n - 1; j++) {
                students[j] = students[j + 1];
            }
            (*n)--;
            printf("Record with last name %s deleted successfully.\n", lastName);
            return;
        }
    }
    printf("Record with last name %s not found.\n", lastName);
}

// Function to update student details by roll number
void updateByRollNumber(struct Student students[], int n, int rollNumber) {
    for (int i = 0; i < n; i++) {
        if (students[i].rollNumber == rollNumber) {
            printf("Enter new details for student with Roll Number %d:\n", rollNumber);
            printf("Enter First Name: ");
            scanf("%s", students[i].firstName);
            printf("Enter Last Name: ");
            scanf("%s", students[i].lastName);
            printf("Enter Marks (English Maths Physics Chemistry Computers): ");
            scanf("%f %f %f %f %f", &students[i].marks.english, &students[i].marks.maths,
                  &students[i].marks.physics, &students[i].marks.chemistry, &students[i].marks.computers);
            printf("Enter Gender (M/F): ");
            scanf(" %c", &students[i].gender);
            printf("Enter Date of Birth (Day Month Year): ");
            scanf("%d %d %d", &students[i].dob.day, &students[i].dob.month, &students[i].dob.year);
            printf("Record updated successfully.\n");
            return;
        }
    }
    printf("Record with Roll Number %d not found.\n", rollNumber);
}

int main() {
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);

    // Dynamic memory allocation for an array of students
    struct Student *students = (struct Student *)malloc(n * sizeof(struct Student));

    // Input details for each student
    for (int i = 0; i < n; i++) {
        printf("Enter details for student %d:\n", i + 1);
        printf("Enter Roll Number: ");
        scanf("%d", &students[i].rollNumber);
        printf("Enter First Name: ");
        scanf("%s",students[i].firstName);
        printf("Enter Last Name: ");
        scanf("%s", students[i].lastName);
        printf("Enter Marks (English Maths Physics Chemistry Computers): ");
        scanf("%f %f %f %f %f", &students[i].marks.english, &students[i].marks.maths, &students[i].marks.physics, &students[i].marks.chemistry, &students[i].marks.computers);
        printf("Enter Gender (M/F): ");
        scanf(" %c", &students[i].gender);
        printf("Enter Date of Birth (Day Month Year): ");
        scanf("%d %d %d", &students[i].dob.day, &students[i].dob.month, &students[i].dob.year);
        printf("\n");
    }

    int choice;
    do {
        // Display menu
        printf("\nMenu:\n");
        printf("1. Display students with less than 40%% aggregate\n");
        printf("2. Display class average\n");
        printf("3. Display students by Date of Birth\n");
        printf("4. Delete student record by last name\n");
        printf("5. Update student details by Roll Number\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayBelow40Percent(students, n);
                break;
            case 2:
                printf("Class Average: %.2f\n", calculateClassAverage(students, n));
                break;
            case 3: {
                displayByDOB(students, n);
                break;
            }
            case 4: {
                char lastName[50];
                printf("Enter last name to delete record: ");
                scanf("%s", lastName);
                deleteByLastName(students, &n, lastName);
                break;
            }
            case 5: {
                int rollNumber;
                printf("Enter Roll Number to update details: ");
                scanf("%d", &rollNumber);
                updateByRollNumber(students, n, rollNumber);
                break;
            }
            case 6:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid choice.\n");
        }
    } while (choice != 6);

    // Free the allocated memory
    free(students);

    return 0;
}

