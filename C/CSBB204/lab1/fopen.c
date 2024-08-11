/*Write a C program that counts the number of characters and number of lines in a file.
Code by - Daksh Verma 
Roll No - 231210036*/
#include <stdio.h>
#include <string.h>

int main() {
    char choice[100];
    printf("\n\nWhich file do you want to read? ");
    scanf("%s", choice);

    FILE *file = fopen(choice, "r");
    if (file == NULL) {
        printf("File doesn't exist or cannot be opened!\n");
        return 1; // Exit the program
    }

    int charCount = 0,lineCount = 0;
    int c;
    while ((c = fgetc(file)) != EOF) {
        if (c != '\n') {
            charCount++;} 
        else {
            lineCount++;}
    }

    fclose(file);

    printf("\nNumber of characters in the file: %d\n", charCount);
    printf("Number of lines in the file: %d\n", lineCount + 1); // Add 1 for the last line

    return 0;
}
        
