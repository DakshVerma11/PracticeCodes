/*Write a program to input two integer numbers and display the sum of even numbers
between these two input numbers.
 * Code by : Daksh Verma
 * Roll No : 231210036*/
 
#include <stdio.h>

int main() {
    int i, n1, n2, sum = 0;
    
    // Prompt user to enter two numbers
    printf("Enter the two numbers:\n");
    scanf("%d %d", &n1, &n2);

    // Loop through the range and calculate the sum of even numbers
    for (i = n1; i <= n2; i++) {
        if (i % 2 == 0) {
            sum += i;
        }
    }
    
    // Print the sum of even numbers in the given range
    printf("Sum of all even numbers between %d and %d is %d\n", n1, n2, sum);
    return 0;
}

