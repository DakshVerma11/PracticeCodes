/* BUBBLE SORT
Coded by : Daksh Verma  - 231210036
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int arr[], int n) {
    int temp, swapped; 
    for (int i = 0; i < n-1; i++) {
        swapped = 0; // initialize swapped to 0 for each pass

        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;

                swapped = 1; // set swapped to 1 if a swap is made
            }
        }

        // Print the current pass
        printf("Pass %d: ", i+1);
        for (int k = 0; k < n; k++) {
            printf("%d ", arr[k]);
        }
        printf("\n");

        // If no swaps were made, the array is already sorted
        if (!swapped) {
            break;
        }
    }
}

int main() {
    int *arr, n;
    printf("Enter the number of integer elements in the array: ");
    scanf("%d", &n);
    // Allocate memory for the array
    arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        printf("Enter Element no %d: ", i+1);
        scanf("%d", arr+i);
    }
    // Record start time
    clock_t start_time = clock();
    // Perform Bubble Sort
    bubbleSort(arr, n);
    // Record end time
    clock_t end_time = clock();
    double execution_time = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Execution Time: %lf seconds\n", execution_time);
    // Calculate and print the total memory used
    size_t total_memory = sizeof(int) * (n+1); // Size of the array + temp
    printf("Total Memory Used: %lu bytes\n", total_memory);
    // Free dynamically allocated memory
    free(arr);

    return 0;
}


