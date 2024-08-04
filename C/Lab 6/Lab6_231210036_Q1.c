/*Write a program to print the following pattern n times, where n is entered by the user.
(using while loop statement)
 * Code by : Daksh Verma
 * Roll No : 231210036*/
 
 
#include <stdio.h>

int main() {
    int i=1, N;
    
    // Prompt user to enter a number
    printf("Enter the number N: ");
    scanf("%d", &N);
    
    // Loop to print the message N times
    while (i <= N) {
        printf("Welcome to NIT Delhi!!\n");
        i++;
    }
    
    return 0;
}

