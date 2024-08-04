/*Write a program to display a pyramid . take the input from the user to generating the pyramid
 * Code by : Daksh Verma
 * Roll No : 231210036*/
 
 #include <stdio.h>

int main() {
    int numRows, i, j, k;

    // Prompt the user for the number of rows
    printf("Enter the number of rows for the pyramid: ");
    scanf("%d", &numRows);

    // Outer loop for each row
    for (i = 0; i <= numRows; i++) {
        
        // Print spaces
        for (j = 0; j < numRows - i; j++) {
            printf("  ");
        }
 	

        // Print decreasing numbers
        for (j = i; j >= 0; j--) {
            printf("%d ", j);
        }
        
        
	// Print increasing numbers
        for (k = 1; k <= i; k++) {
            printf("%d ", k);
        }
        
        
        printf("\n");
    }

    return 0; 
  }

