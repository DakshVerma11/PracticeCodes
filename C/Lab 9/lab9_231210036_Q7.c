/* Take the marks of your last semester subjects as an input. Determine the maximum and minimum scores using
 * Code by - Daksh Verma
 * Roll No - 231210036*/

#include <stdio.h>

// Function to perform bubble sort on an array
void bubblesort(int *array, int n) {
    int i, j, temp;
    // Outer loop for number of passes
    for (j = 0; j < n; j++) {
        // Inner loop for comparison and swapping
        for (i = 0; i < n - j - 1; i++) {
            // Swap if the current element is greater than the next element
            if (array[i] > array[i + 1]) {
                temp = array[i + 1];
                array[i + 1] = array[i];
                array[i] = temp;
            }
        }
    }
}

// Function to print elements of an array
void printarr(int *array, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d\t", array[i]);
    }
}

int main() {
    int n, array[100];

    // User input for the number of subjects
    printf("Enter the number of subjects: ");
    scanf("%d", &n);

    // User input for marks of each subject
    printf("\nEnter marks of:\n");
    for (int i = 0; i < n; i++) {
        printf("\tSubject %d : ", i + 1);
        scanf("%d", array + i);
    }

    // Sort the array using bubble sort
    bubblesort(array, n);

    // Print the sorted array
    printf("Printing Sorted Array:\n");
    printarr(array, n);
    printf("\n\n");

    return 0;
}

