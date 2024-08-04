/* Write a function to swap the value of two variables and it should illustrates the use of call by value and call be reference 
 * Code by - Daksh Verma
 * Roll No - 231210036  */

#include <stdio.h>

void swapcbv(int x, int y) {
    int temp = y;
    y = x;
    x = temp;
    printf("\nFirst num\t - %d\nSecond num\t - %d", x, y);
}

void swapcbf(int *x, int *y) {
    int temp = *y;
    *y = *x;
    *x = temp;
    printf("\nFirst num\t - %d\nSecond num\t - %d", *x, *y);
}

int main() {
    int a, b;
    FILE *file;
     // Open the text file for reading
	file = fopen("input_Q2.txt", "r");
     // Read the decimal from the file
    	fscanf(file, "%d %d", &a,&b);
    // Close the file after reading
    	fclose(file);
    
    printf("\nStarting Value\n  A = %d and B = %d\n\n", a, b);
    
    // Call by Value
    printf("Call by Value");
    swapcbv(a, b);
    printf("\n  A = %d and B = %d\n\n", a, b);

    // Call by Reference
    printf("Call by Reference");
    swapcbf(&a, &b);
    printf("\n  A = %d and B = %d\n\n", a, b);

    return 0;
}

