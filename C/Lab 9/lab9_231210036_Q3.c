/* Write a program to read multiple lines of text until a * is entered. Then count the number of characters, words, and lines in the text.
 * Code by - Daksh Verma
 * Roll No - 231210036*/

#include <stdio.h>

int main() {
    char string[100];
    printf("\nEnter your String: \n");
    scanf(" %[^\"*\"]s", string); // Read input string until "*" is encountered
    //Counting characters,words and lines
    int i = 0, countchar = 0, countword = 1, countline = 1;
    while (string[i] != '\0') {
        if (string[i] == ' ' && string[i + 1] != ' ') {
            countword++; //counting words by checking for space character
        }
        if (string[i] == '\n') {//checking for newline character using
            countline++;
            countword++;}
         else {
            countchar++;
        }
        i++;
    }
    
    printf("\nPrinting string-\n%s\n", string); // Print input string
    printf("Number of characters - %d\n", countchar); // Print number of characters
    printf("Number of words      - %d\n", countword); // Print number of words
    printf("Number of lines      - %d\n", countline); // Print number of lines

    return 0;
}

