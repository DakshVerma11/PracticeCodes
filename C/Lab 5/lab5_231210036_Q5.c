/* Write a program in C that accepts a number from 1 to 10. Display whether a number is even or odd using a switch case construct
 *
 * Code by : Daksh Verma
 * Roll No : 231210036*/
 
#include <stdio.h>

int main() {
    int num;
    
    // Prompt user for input
    printf("Enter number from 1 to 10: ");
    scanf("%d", &num);

    // Check if the number is odd or even using a switch statement
    switch (num) {
        // Cases for odd numbers
        case 1:
        case 3:
        case 5:
        case 7:
        case 9:
            printf("Odd\n");
            break;
        // Cases for even numbers
        case 2:
        case 4:
        case 6:
        case 8:
        case 10:
            printf("Even\n");
            break;
        // Default case for numbers out of range
        default:
            printf("Number out of range");
    }
    
    return 0;
}

