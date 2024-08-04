/* Write a program in C to determine whether a person is eligible to vote . (using if statement)
 *
 * Code by : Daksh Verma
 * Roll No : 231210036*/
#include <stdio.h>

int main() {
    // Prompt the user to enter age
    printf("Enter age: ");
    int age;
    scanf("%d", &age);

    // Check if the age is greater than or equal to 18
    if (age >= 18) {
        // If age is 18 or older, the person is eligible to vote
        printf("Eligible to vote\n");
    } else {
        // If age is less than 18, the person is not eligible to vote
        printf("Not Eligible\n");
    }
    
    return 0;
}
