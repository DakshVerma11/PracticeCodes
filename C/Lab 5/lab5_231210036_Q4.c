
/* Write C program to calculate tax, given the following conditions: (use nested if-else statement)
 *
 * Code by : Daksh Verma
 * Roll No : 231210036*/
 
#include <stdio.h>

int main() {
    int inc, tax;
    
    // Prompt user for income
    printf("Enter income: ");
    scanf("%d", &inc);
    
    // Calculate tax based on income brackets
    if (inc > 250000) {
        if (inc < 500000)
            tax = 0.05 * inc;
        else if (inc < 1000000)
            tax = 12500 + 0.2 * (inc - 500000);
        else
            tax = 112500 + 0.3 * (inc - 1000000);
    } else {
        tax = 0;
    }
    
    // Print calculated tax
    printf("%d\n", tax);

    return 0;
}
