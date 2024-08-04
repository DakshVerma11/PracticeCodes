/*Write a program to display the largest of five number using ternary operator.
 * Code by : Daksh Verma
 * Roll No : 231210036*/
 
#include <stdio.h>

int main() {
    int i, n, max = 0;
    
    // Loop to input numbers and find the maximum
    for (i = 1; i <= 5; i++) {
        printf("\nEnter Number: ");
        scanf("%d", &n);
        
        // Compare and update the maximum number
        if (n > max) {
            max = n;
        }
    }
    
    // Print the maximum number
    printf("\n\nThe maximum of the following numbers is %d", max);
    return 0;
}

