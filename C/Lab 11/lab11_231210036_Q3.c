/*Write a program using file handling concepts in C, as discussed in lab 8 problem 2, store the following details of COVID-19 cases in Delhi for last one week, as an 2 Dimension array elements of size 7x4 and display the sum and average of respective column.
Code by - Daksh Verma 
Roll No - 231210036*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define RECORD_COUNT 7

// Structure to store Covid records
struct CovidRecord {
    char date[11];
    int hospitalized;
    int recovered;
    int deceased;
};

// Function to add a record to the file
void addRecord(FILE *file, char *date, int hospitalized, int recovered, int deceased) {
    fprintf(file, "%s %d %d %d\n", date, hospitalized, recovered, deceased);
}

// Function to display all records
void showAllRecords(FILE *file) {
    printf("\nDATE\t\tHOSPITALIZED\tRECOVERED\tDECEASED");
    struct CovidRecord covid19[RECORD_COUNT];
    for (int i = 0; i < RECORD_COUNT; i++) {
        fscanf(file, "%s %d %d %d", covid19[i].date, &covid19[i].hospitalized, &covid19[i].recovered, &covid19[i].deceased);
        printf("\n%s\t\t%d\t\t%d\t\t%d", covid19[i].date, covid19[i].hospitalized, covid19[i].recovered, covid19[i].deceased);
    }
}

// Function to calculate total of a specific column
int columnTotal(FILE *file, int columnNo) {
    int sum = 0, temp;
    struct CovidRecord record;
    for (int i = 0; i < RECORD_COUNT; i++) {
        fscanf(file, "%s %d %d %d", record.date, &record.hospitalized, &record.recovered, &record.deceased);
        switch (columnNo) {
            case 1:
                temp = record.hospitalized;
                break;
            case 2:
                temp = record.recovered;
                break;
            case 3:
                temp = record.deceased;
                break;
        }
        sum += temp;
    }
    return sum;
}

int main() {
    FILE *file = fopen("covid_data.txt", "w+");
    if (file == NULL) {
        printf("Error opening file!");
        return 1;}
    char date[11];
    int hospitalized, recovered, deceased, choice;
    // Input records and save to file
    do {
        printf("Enter Date (DD/MM/YYYY): ");
        scanf("%s", date);
        printf("Enter Number of Hospitalized Patients: ");
        scanf("%d", &hospitalized);
        printf("Enter Number of Recovered Patients: ");
        scanf("%d", &recovered);
        printf("Enter Number of Deceased Patients: ");
        scanf("%d", &deceased);
        addRecord(file, date, hospitalized, recovered, deceased);
        printf("Do you want to add more records? (1-Yes, 0-No): ");
        scanf("%d", &choice);
    } while (choice == 1);
    rewind(file); // Reset file pointer to the beginning
    // Output hospital statistics
    printf("\n\nHospital Statistics for One Week");
    showAllRecords(file);
    printf("\n\nTotal Hospitalized Patients: %d", columnTotal(file, 1));
    printf("\nTotal Recovered Patients     : %d", columnTotal(file, 2));
    printf("\nTotal Deceased Patients      : %d", columnTotal(file, 3));
    printf("\nAverage Hospitalized Patients: %.2f", (float)columnTotal(file, 1) / RECORD_COUNT);
    printf("\nAverage Recovered Patients   : %.2f", (float)columnTotal(file, 2) / RECORD_COUNT);
    printf("\nAverage Deceased Patients    : %.2f\n", (float)columnTotal(file, 3) / RECORD_COUNT);
    fclose(file);
    return 0;
}

