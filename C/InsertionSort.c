/*InsertionSort
Code by Daksh Verma - 231210036*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSort(int arr[], int n) {
    int i, j, current;

    for (i = 1; i < n; i++) {
        current = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > current) {
     		arr[j + 1] = arr[j];
      		j--;
    	}

        arr[j + 1] = current;

        // Print the current pass
        printf("Pass %d: ", i);
        for (int k = 0; k < n; k++) {
            printf("%d ", arr[k]);
        }
        printf("\n");
    }
}

int main() {
    int *arr, n;
    printf("Enter the number of integer elements in the array: ");
    scanf("%d", &n);

    // Allocate memory for the array
    arr = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        printf("Enter Element no %d: ", i + 1);
        scanf("%d", arr + i);
    }

    // Record start time
    clock_t start_time = clock();

    // Perform insertion Sort
    insertionSort(arr, n);

    // Record end time
    clock_t end_time = clock();
    double execution_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Execution Time: %lf seconds\n", execution_time);

    // Calculate and print the total memory used
    size_t total_memory = sizeof(int) * (n +1); // Size of the array 
    printf("Total Memory Used: %lu bytes\n", total_memory);

    // Free dynamically allocated memory
    free(arr);

    return 0;
}

