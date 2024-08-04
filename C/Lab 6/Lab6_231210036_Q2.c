/*Write a C program to display first 10 number in its natural and reverse order. (using for )
 * Code by : Daksh Verma
 * Roll No : 231210036*/
 
#include <stdio.h>

int main() {
    int i;
    
    // Print numbers in natural order from 1 to 10
    printf("Natural Order: ");
    for (i = 1; i <= 10; i++) {
        printf("%d ", i);
    }
    
    // Print numbers in reverse order from 10 to 1
    printf("\nReverse Order: ");
    for (i = 10; i >= 1; i--) {
        printf("%d ", i);
    }
    
    printf("\n");
    
    return 0;
}

