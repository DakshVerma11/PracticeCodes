/* Write a program that read your name and then displays the ASCII Value of each character in your name on a separate Line.
 * Code by - Daksh Verma
 * Roll No - 231210036*/

#include <stdio.h>

int main() {
    char name[30];
    printf("\nEnter your name: "); 
    scanf(" %[^\n]s", name); // Read the input string until a newline character is encountered
    
    int i = 0;
    while (name[i] != '\0') {
        // Print the ASCII code of each character along with its position
        printf("ASCII Code of %d character - %d\n", i + 1, name[i]); 
        i++; 
    }
    
    printf("End\n\n");
    return 0;
}

