/* Write a program to enter a text. Then enter a pattern and count the number of times the patterns is repeated in the text.
 * Code by - Daksh Verma
 * Roll No - 231210036*/

#include <stdio.h>

// Function to count the occurrences of a substring in a given string
int countSubString(char *string, char *search) {
    int i = 0, count = 0, j = 0, k;
    while (string[i] != '\0') {
        k = 0;
        j = 0;
        // If the current character in the main string matches the first character of the search string
        if (string[i] == search[0]) {
            // Loop through the search string to check for a mismatch
            while (search[j] != '\0') {
                if (string[i + j] != search[j])
                    k = 1;
                j++;
            }
            if (k == 0)
                count++;
        }
        i++;
    }
    return count;
}

int main() {
    char string[100], search[15];
    printf("\nEnter your String: \n");
    scanf(" %[^\n]s", string);

    printf("\nEnter String to search for: \n");
    scanf(" %[^\n]s", search);

    printf("\nOccurrences - %d\n\n", countSubString(string, search));
    return 0;
}

