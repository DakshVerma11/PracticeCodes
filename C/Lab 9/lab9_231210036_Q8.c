/* Write a program to enter a text. Then enter a pattern and count the number of times the patterns is repeated in the text.
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

short unsigned int linearcount=0;
// Function for linear search in an array
int linearSearch(int array[], int length, int value,int *linearcount) {
    for (int i = 0; i < length; i++) {
    	*linearcount+=1;
        if (array[i] == value) {
            return i;
        }
    }
    return -1;
}

short unsigned int binarycount=0;
// Function to perform binary search on a sorted array
int binarySearch(int array[], int length, int value,int *binarycount) {
    int left = 0, right = length - 1,mid;
    
    while (left <= right) {
        mid = left + (right - left) / 2;
        *binarycount+=1;
        if (array[mid] == value) {
            return mid;
        }
        if (array[mid] < value) {
            left = mid + 1;
        } 

        else {
            right = mid - 1;
        }
    }
    return -1;
}


int main() {
    int length, array[100], value;

    // User input for the number of subjects
    printf("Enter the number of subjects: ");
    scanf("%d", &length);

    // User input for marks of each subject
    printf("\nEnter marks of:\n");
    for (int i = 0; i < length; i++) {
        printf("\tSubject %d : ", i + 1);
        scanf("%d", array + i);
    }

    // Sort the array using bubble sort
    bubblesort(array, length);
    printf("Printing Sorted Array\n");
    printarr(array, length);

    // User input for value to search
    printf("\nEnter value to search for: ");
    scanf("%d", &value);

    // Perform linear search and binary search
    int linearcount=0,binarycount=0;
    printf("\nLinear Search\n\tIndex - %d\n\t", linearSearch(array, length, value, &linearcount));
    printf("No of Operations - %hu\n",linearcount);
    printf("Binary Search\n\tIndex - %d\n\t", binarySearch(array, length, value, &binarycount));
    printf("No of Operations - %hu\n",binarycount);
    return 0;
}

