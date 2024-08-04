/* Write a program in C using function to display the multiplication table of n, where n is entered by the user.
 * Code by - Daksh Verma
 * Roll No - 231210036  */

#include <stdio.h>

int main(){

	int i=1,n;
	
	FILE *file;
	// Open the text file for reading
	file = fopen("input_Q5.txt", "r");
	// Read the decimal from the file
	 fscanf(file, "%d", &n);
	// Close the file after reading
	fclose(file);
	
	//starting loop to iterate i from 1 to 10
	while (i<11){
		//printing table
		printf("%d X %d = %d\n",n,i,n*i);
		i++;
		}
	return 0;
	}
