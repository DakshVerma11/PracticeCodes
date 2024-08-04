/* Write a program to read multiple line of text until a ~ is entered using scanset concept.
 * Code by - Daksh Verma
 * Roll No - 231210036*/

#include <stdio.h>

int main() {
    char name[100];
    printf("\nEnter your String: \n"); // Prompt the user to enter a string
    scanf(" %[^\"~\"]s", name); // Read the input string until "~" or "\"" is encountered
    
    printf("\nPrinting string-\n%s\n\n", name); // Print the input string
    
    return 0;
}

