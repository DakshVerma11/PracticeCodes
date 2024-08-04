/* Write a program to print the reverse of a number. And display sum of its digit. It should illustrates the use of local, global and static variables. 
 * Code by - Daksh Verma
 * Roll No - 231210036  */

#include <stdio.h>

int globalSum = 0; // Global variable to store the sum of digits

void reverseAndSum(int num) {
    static int staticSum = 0; // Static variable to store the sum of digits
    int localSum = 0; // Local variable to store the sum of digits
    int reversedNum = 0;

    while (num > 0) {
        int digit = num % 10;
        reversedNum = reversedNum * 10 + digit;
        localSum += digit;
        staticSum += digit;
        globalSum += digit;
        num /= 10;
    }

    printf("Reversed Number: %d\n", reversedNum);
    printf("Local Sum of Digits: %d\n", localSum);
    printf("Static Sum of Digits: %d\n", staticSum);
    printf("Global Sum of Digits: %d\n", globalSum);
}

int main() {
        int num;
        FILE *file;
	// Open the text file for reading
	file = fopen("input_Q6.txt", "r");
	// Read the decimal from the file
	 fscanf(file, "%d", &num);
	// Close the file after reading
	fclose(file);
	
	printf("Orignal Number : %d",num);

	reverseAndSum(num);	
	// printf("Local Sum of Digits: %d\n", localSum); This gives error as there is no variable name localSum	
	//printf("Static Sum of Digits: %d\n", staticSum); This is an undeclared variable as there is no return value in reversedAndSum()
	printf("\nNow in Main\nGlobal Sum of Digits: %d\n", globalSum);
        return 0;
}

