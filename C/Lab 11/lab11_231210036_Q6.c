/*Write set of strings each of length 40 into a file “stringc.txt” and display it (use fputs() and fgets() function).
Code by - Daksh Verma 
Roll No - 231210036*/

#include <stdio.h>
#include <string.h>

int main() {
    printf("\nWriting Input\n");
    FILE *file = fopen("Q6.txt", "w");
    //Used Q6.txt instead of filec.txt to better keep track of the files used in the LAB
    if (file == NULL) {
        printf("Error creating file!\n");
        return 1; // Exit the program
    }

    char str[41]; // Maximum length of string (40 characters + null terminator)
    char newLine[41] = "\n"; // New line string

    printf("Enter lines of up to 40 characters each (Press Enter twice to stop):\n");
    while (1) {
        printf("> ");
        fgets(str, 41, stdin); // Read a line of input
        
        // Check if the user entered an empty line to stop input
        if (strcmp(str, newLine) == 0 || strcmp(str, "\n") == 0)
            break;

        // Write the input line to the file
        fputs(str, file);
    }

    fclose(file);

    printf("\nReading Input\n");
    FILE *f = fopen("Q6.txt", "r");
    if (f == NULL) {
        printf("File doesn't exist or cannot be opened!\n");
        return 1; // Exit the program
    }

    char buffer[41]; // Buffer to read lines from the file
    printf("\nText in file -\n");
    while (fgets(buffer, 41, f) != NULL) {
        printf("%s", buffer); // Print the line read from the file
    }
    fclose(f);

    printf("\n");
    return 0;
}

