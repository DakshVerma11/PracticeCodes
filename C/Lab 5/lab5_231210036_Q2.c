/* Write a program to enter a character and then determines whether the entered character is an alphabet or not. (using if- else statement )
 *
 * Code by : Daksh Verma
 * Roll No : 231210036*/
 
#include <stdio.h>

int main() {
    char c;

    // Prompt the user to enter a character
    printf("Enter a character: ");
    scanf(" %c", &c);  // Note: There is a space before %c to consume the newline character from previous input

    // Check if the character is an uppercase or lowercase alphabet using the known ASCII Code
    if (((int)c >= 65 && (int)c <= 90) || ((int)c >= 97 && (int)c <= 122)) {
        printf("Alphabet\n");
    } else {
        printf("Not an Alphabet\n");
    }

    return 0;
}
