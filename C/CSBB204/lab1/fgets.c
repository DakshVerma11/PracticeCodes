#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    FILE *file;
    char filename[256];
    char text[1024];

    printf("Enter the filename: ");
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = '\0';

    

    file = fopen(filename, "r");

    if (file == NULL) {
        perror("Error opening file");
        return 1; // Return a non-zero value to indicate error
    }
    
    
    char buffer[255];
    rewind(file);
    
    printf("File Text :\n");
    while (fgets(buffer, sizeof(buffer), file)) {
        printf("%s", buffer);
    }
    
    
    
    printf("\n\n**********************************\n");
    fclose(file);

    printf("Data written to file successfully.\n");

    return 0; 
}
