/* Write a program to print Hello NITD!! using pointers.
 * Code by - Daksh Verma
 * Roll No - 231210036*/


#include <stdio.h>

char ascii[128]; // Array to store ASCII characters

// Function to fill the ASCII array
void fillASCII() {
    for (int k = 1, indexk = 0; k < 129; k++) {
        ascii[indexk++] = k;
    }
}

int main() {
    fillASCII(); // Fill the ASCII array

    // Print specific characters using array indexing
    printf("%c", *(ascii + 64 + 7));
    printf("%c", *(ascii + 96 + 4));
    printf("%c", *(ascii + 96 + 11));
    printf("%c", *(ascii + 96 + 11));
    printf("%c", *(ascii + 96 + 14));
    printf("%c", *(ascii + 31));
    printf("%c", *(ascii + 64 + 13));
    printf("%c", *(ascii + 64 + 8));
    printf("%c", *(ascii + 64 + 19));
    printf("%c", *(ascii + 64 + 3));
    printf("%c", *(ascii + 32));
    printf("%c", *(ascii + 32));
    printf("%c", *(ascii + 9));

    return 0;
}

