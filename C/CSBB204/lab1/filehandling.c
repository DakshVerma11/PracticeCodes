/* Q. Write a C program on file handling to implement filehandling Functions.
Code by : Daksh Verma*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


FILE *file = NULL;

void openFile(FILE **fp, const char *filename, const char *mode) {
    *fp = fopen(filename, mode);
    if (*fp == NULL) {
        perror("Error opening file");
    } else {
        printf("File opened successfully.\n");
    }
}

void writeData(FILE *fp) {
    char str[100];
    printf("Input text to be written into the file:\n");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0'; // Remove newline character
    if (fprintf(fp, "%s", str) < 0) {
        perror("Error writing data to file");
    } else {
        printf("Data written to file.\n");
    }
}

void readData(FILE *fp) {
    char str[100];
    rewind(fp); // Move to the beginning of the file
    while (fgets(str, sizeof(str), fp) != NULL) {
        printf("Read from file: %s", str);
    }
}

void writeChar(FILE *fp) {
    char ch;
    printf("Enter character to be written into the file:\n");
    ch = getchar();
    while (getchar() != '\n'); // Clear input buffer
    if (fputc(ch, fp) == EOF) {
        perror("Error writing character to file");
    } else {
        printf("Character written to file.\n");
    }
}

void readChar(FILE *fp) {
    int ch = fgetc(fp);
    if (ch != EOF) {
        printf("Read from file: %c\n", ch);
    } else {
        perror("Error reading character from file");
    }
}

void closeFile(FILE *fp) {
    if (fclose(fp) != 0) {
        perror("Error closing file");
    } else {
        printf("File closed successfully.\n");
    }
}

void setFilePointer(FILE *fp) {
    long offset;
    int whence;
    printf("Enter offset: ");
    scanf("%ld", &offset);
    while (getchar() != '\n'); // Clear input buffer
    printf("Enter whence (0 for SEEK_SET, 1 for SEEK_CUR, 2 for SEEK_END): ");
    scanf("%d", &whence);
    while (getchar() != '\n'); // Clear input buffer
    if (fseek(fp, offset, whence) != 0) {
        perror("Error setting file pointer");
    } else {
        printf("File pointer set.\n");
    }
}

void writeInteger(FILE *fp) {
    int num;
    printf("Enter integer to be written into the file:\n");
    scanf("%d", &num);
    while (getchar() != '\n'); // Clear input buffer
    if (putw(num, fp) == EOF) {
        perror("Error writing integer to file");
    } else {
        printf("Integer written to file.\n");
    }
}

void readInteger(FILE *fp) {
    int num = getw(fp);
    if (num != EOF) {
        printf("Read from file: %d\n", num);
    } else {
        perror("Error reading integer from file");
    }
}

void tellFilePosition(FILE *fp) {
    long pos = ftell(fp);
    if (pos == -1L) {
        perror("Error getting file position");
    } else {
        printf("Current position: %ld\n", pos);
    }
}

void rewindFile(FILE *fp) {
    rewind(fp);
    printf("File pointer rewound to the beginning.\n");
}

int main() {
    int choice;
    char filename[100];
    char mode[3];

    while (1) {
        printf("\nMenu:\n");
        printf("1. Open File\n");
        printf("2. Write Data to File\n");
        printf("3. Read Data from File\n");
        printf("4. Write Character to File\n");
        printf("5. Read Character from File\n");
        printf("6. Close File\n");
        printf("7. Set File Pointer Position\n");
        printf("8. Write Integer to File\n");
        printf("9. Read Integer from File\n");
        printf("10. Tell File Position\n");
        printf("11. Rewind File\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        while (getchar() != '\n'); // clear the input buffer

        switch (choice) {
            case 1:
                printf("Enter filename: ");
                fgets(filename, sizeof(filename), stdin);
                filename[strcspn(filename, "\n")] = '\0'; // Remove newline character
                printf("Enter mode (r/w/a/r+): ");
                fgets(mode, sizeof(mode), stdin);
                mode[strcspn(mode, "\n")] = '\0'; // Remove newline character
                openFile(&file, filename, mode);
                break;

            case 2:
                if (file) {
                    writeData(file);
                } else {
                    printf("No file is open.\n");
                }
                break;

            case 3:
                if (file) {
                    readData(file);
                } else {
                    printf("No file is open.\n");
                }
                break;

            case 4:
                if (file) {
                    writeChar(file);
                } else {
                    printf("No file is open.\n");
                }
                break;

            case 5:
                if (file) {
                    readChar(file);
                } else {
                    printf("No file is open.\n");
                }
                break;

            case 6:
                if (file) {
                    closeFile(file);
                    file = NULL;
                } else {
                    printf("No file is open.\n");
                }
                break;

            case 7:
                if (file) {
                    setFilePointer(file);
                } else {
                    printf("No file is open.\n");
                }
                break;

            case 8:
                if (file) {
                    writeInteger(file);
                } else {
                    printf("No file is open.\n");
                }
                break;

            case 9:
                if (file) {
                    readInteger(file);
                } else {
                    printf("No file is open.\n");
                }
                break;

            case 10:
                if (file) {
                    tellFilePosition(file);
                } else {
                    printf("No file is open.\n");
                }
                break;

            case 11:
                if (file) {
                    rewindFile(file);
                } else {
                    printf("No file is open.\n");
                }
                break;

            case 0:
                if (file) {
                    closeFile(file);
                }
                printf("Exiting...\n");
                exit(EXIT_SUCCESS);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
