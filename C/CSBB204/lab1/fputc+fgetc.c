/*Write characters into a file “filec.txt”. The set of characters are read form the keyboard until an enter key is pressed (use putc() and getc() function).
Code by - Daksh Verma 
Roll No - 231210036*/

#include <stdio.h>
#include <string.h>

int main() {
    printf("\nReading Input\n");
    FILE *file = fopen("Q4.txt", "w");
    int character;
    while (character!='\n') {
    	scanf("%c",&character);
    	fputc(character,file);
    }
    fclose(file);
    FILE *f = fopen("Q4.txt", "r");
    
    if (f == NULL) {
        printf("File doesn't exist or cannot be opened!\n");
        return 1; // Exit the program
    }
    printf("\nText in file -\n");
    while ((character = fgetc(f)) != EOF) {
        printf("%c",character);
    }
    fclose(f);
    printf("\n");
    return 0;
}
