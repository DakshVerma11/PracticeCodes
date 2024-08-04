/*Write name, age and height of a person into a data file “person.txt” and read it (use fprintf() and fscanf() function)
Code by - Daksh Verma 
Roll No - 231210036*/

#include <stdio.h>
#include <string.h>

struct person {
    char name[50];
    int age;
    float height;
};

void inputIntoFile(struct person s, FILE *f) {
    fprintf(f, " %s , %d , %f \n", s.name, s.age, s.height);
}

void displayFile() {
    FILE *f;
    struct person s;
    f = fopen("Q7.txt", "r");
    if (f == NULL) {
        printf("File doesn't exist or cannot be opened!");
        return;
    }

    char line[256]; // Assuming each line in the file is not longer than 255 characters

    while (fgets(line, sizeof(line), f) != NULL) {
        sscanf(line, " %[^,], %d , %f ", s.name, &s.age, &s.height);
        printf("\nName - %s\nAge - %d\nHeight - %.2f\n",s.name, s.age, s.height);
    }
    fclose(f);
}

int main() {
    int choice;
    do {
        printf("\n\nWhat do you want to do?:\n1. Add Person Details\n2. Display Person Details\n3. Exit\n");
        scanf("%d", &choice);
	printf("\nChoice = %d\n\n",choice);
        switch (choice) {
            case 1: {
                struct person s;
                FILE *f;
                int n;
                printf("\nEnter the number of Persons : ");
                scanf("%d", &n);
                f = fopen("Q7.txt", "a");
                if (f == NULL) {
                    printf("File cannot be opened!");
                    return 1;
                }
                for (; n > 0; n--) {
                    printf("\n\nEnter Name: ");
                    scanf(" %[^\n]", s.name);
                    printf("Enter Age: ");
                    scanf(" %d", &s.age);
                    printf("Enter Height (in cm): ");
                    scanf(" %f", &s.height);
                    inputIntoFile(s, f);
                }
                fclose(f);
                break;}
            case 2: {
                displayFile();
                break;}
            case 3: {
                printf("\nExiting Program\n");
                break; }
            default: {
                printf("\nUnexpected Input\n");
                break; }
        }
    } while (choice != 3);
    return 0;
}
