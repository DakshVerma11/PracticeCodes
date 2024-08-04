#include <stdio.h>

int main() {
    // Declare variables to store JEE Main score and grade
    int jee, grade;

    // Prompt the user to enter their JEE Main score
    printf("Enter JEE Main score (test):\n");
    scanf("%d", &jee);

    // Prompt the user to enter their grade
    printf("\nEnter your Grade:\n");
    scanf("%d", &grade);

    // Calculate the admission eligibility based on the given condition
    if (2 * jee + grade - 18 > 0) {
        // If the condition is met, printing a congratulatory message
        printf("\nCongratulations, You have secured admission into NIT Delhi\n\n");
    } 	
    else {
        // If the condition is not met, printing a message indicating that admission was not secured
        printf("\nUnfortunately, you haven't secured admission into NIT Delhi\n\n");
    }

    return 0;
}

