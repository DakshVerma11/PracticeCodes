/* Write a program to sort the name of the students. Take the count of students from the users.
 * Code by - Daksh Verma
 * Roll No - 231210036*/

#include <stdio.h>
#include <string.h>

// Function to compare two names
int compareNames(char *name1, char *name2) {
    int i = 0;
    // Loop until the end of either name
    while (name1[i] != '\0' && name2[i] != '\0') {
        // Compare characters at the current position
        if (name1[i] < name2[i]) {
            return -1;
        } else if (name1[i] > name2[i]) {
            return 1;
        }
        i++;
    }
    // Check for cases where one name is a prefix of the other
    if (name1[i] == '\0' && name2[i] == '\0') {
        return 0; // Both names are equal
    } else if (name1[i] == '\0') {
        return -1; // name1 is a prefix of name2
    } else {
        return 1; // name2 is a prefix of name1
    }
}

// Function to perform bubble sort on an array of names
void bubbleSortNames(char names[][100], int count) {
    int i, j;
    char temp[100];
    for (i = 0; i < count - 1; i++) {
        for (j = i + 1; j < count; j++) {
            // Compare names using compareNames function and swap if necessary
            if (compareNames(names[i], names[j]) > 0) {
                strcpy(temp, names[i]);
                strcpy(names[i], names[j]);
                strcpy(names[j], temp);
            }}}
}

int main(){
    int count, i;
    
    // Input the number of students
    printf("Enter the number of students: ");
    scanf("%d", &count);
    
    char names[count][100];
    
    // Input names from the user
    printf("Enter the names of students:\n");
    for (i = 0; i < count; ++i) {
        scanf("%s", names[i]);}
    
    // Sort names in alphabetical order using bubble sort
    bubbleSortNames(names, count);
    
    // Display sorted names
    printf("\nSorted Names:\n");
    for (i = 0; i < count; ++i) {
        printf("%s\n", names[i]);}
    printf("\n");
    return 0;
}

