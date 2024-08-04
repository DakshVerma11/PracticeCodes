/* Write a program to find the sum of all the elements of an array using pointers.
 * Code by - Daksh Verma
 * Roll No - 231210036*/

#include <stdio.h>
#include <stdlib.h> // Include stdlib.h for malloc function

int main() {
    int i, n, sum = 0, *array;

    printf("Enter the number of elements in the integer array: ");
    scanf("%d", &n);

    array = (int *)malloc(n * sizeof(int)); // Allocate memory for the array using malloc

    printf("\nEnter elements of the list:\n");

    for (i = 0; i < n; i++) {
        scanf("%d", array + i);
    }

    for (i = 0; i < n; i++) {
        sum += *(array + i);
    }

    printf("\nSum of the %d elements is %d\n\n", n, sum);

    free(array); // Free dynamically allocated memory to prevent memory leaks

    return 0;
}

