/*Write a C program to count occurrences of all words in a file. Classify the file as Sales, Medical Report or Tales, etc.
Code by - Daksh Verma 
Roll No - 231210036*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 50

// Function to classify the file based on word frequency
void classifyFile(int salesCount, int medicalCount, int talesCount) {
    if (salesCount > medicalCount && salesCount > talesCount) {
        printf("The file is classified as 'Sales'.\n");
    } else if (medicalCount > salesCount && medicalCount > talesCount) {
        printf("The file is classified as 'Medical Report'.\n");
    } else if (talesCount > salesCount && talesCount > medicalCount) {
        printf("The file is classified as 'Tales'.\n");
    } else {
        printf("The file does not match a specific category.\n");
    }
}

int main() {
    FILE *file = fopen("sample.txt", "r");
    if (file == NULL) {
        printf("File does not exist or cannot be opened!\n");
        return 1;
    }

    char word[MAX_WORD_LEN];
    //char words[MAX_WORDS][MAX_WORD_LEN];
    int salesCount = 0, medicalCount = 0, talesCount = 0;
    int wordCount = 0;

    while (fscanf(file, "%s", word) != EOF) {
        // Convert the word to lowercase for case-insensitive comparison
        for (int i = 0; word[i]; i++) {
            word[i] = tolower(word[i]);
        }

        //strcpy(words[wordCount], word);
        wordCount++;

        // Check for occurrences of specific words to classify the file
        if (strcmp(word, "sales") == 0 || strcmp(word, "sale") == 0 || strcmp(word, "sell") == 0) {
            salesCount++;}
        else if (strcmp(word, "medical") == 0 || strcmp(word, "report") == 0) {
            medicalCount++;}
        else if (strcmp(word, "tales") == 0 || strcmp(word, "story") == 0) {
            talesCount++;}
    }
    
    fclose(file);

    // Display the counts of occurrences for different categories
    printf("Occurrences of words:\n");
    printf("Sales: %d\n", salesCount);
    printf("Medical Report: %d\n", medicalCount);
    printf("Tales: %d\n", talesCount);

    // Classify the file based on word frequency
    classifyFile(salesCount, medicalCount, talesCount);

    return 0;
}

