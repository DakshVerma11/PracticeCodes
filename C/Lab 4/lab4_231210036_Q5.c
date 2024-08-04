#include <stdio.h>

int main() {
    // Declare variables to store student information
    int roll, sub1, sub2, sub3, sub4, sub5;
    long int phone;
    char name[20];

    // Prompt the user to enter their name
    printf("Enter your name:\n");

    // Read the name from the user, %[^\n]s is used to read a whole line including spaces
    scanf("%[^\n]s", name);

    // Prompt the user to enter their Roll No
    printf("Enter your Roll No:\n");

    // Read the Roll No from the user
    scanf("%d", &roll);

    // Prompt the user to enter their Phone No
    printf("Enter your Phone No\n");

    // Read the Phone No from the user
    scanf("%ld", &phone);

    // Prompt the user to enter their marks in five subjects
    printf("Enter your Marks in Subject 1\n");
    scanf("%d", &sub1);

    printf("Enter your Marks in Subject 2\n");
    scanf("%d", &sub2);

    printf("Enter your Marks in Subject 3\n");
    scanf("%d", &sub3);

    printf("Enter your Marks in Subject 4\n");
    scanf("%d", &sub4);

    printf("Enter your Marks in Subject 5\n");
    scanf("%d", &sub5);

    // Calculate the percentage by averaging the marks in subjects
    float percentage = (sub1 + sub2 + sub3 + sub4 + sub5) * 10.0 / 5.0;

    // Display the student's information, including name, Roll No, Phone No, and percentage
    printf("\n\nName: %s , Roll No.: %d , Phone No.: %ld , Percentage: %.2f%\n\n", name, roll, phone, percentage);

    return 0;
}

