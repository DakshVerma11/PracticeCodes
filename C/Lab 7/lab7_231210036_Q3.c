/* Design a calculator using function this time, that prompt input as a choice for operation to  perform on them(1 for addition, 2 for subtraction, 3 for multiplication, 4 for division, 5 for exit) and two numbers(if required by operation) . The program should not terminate
untill the user don’t choose to close it. 
 * Code by - Daksh Verma
 * Roll No - 231210036  */

#include <stdio.h>

void calculator(int n1,int n2, int choice){
	switch (choice){
		case 1:
			printf("\n\n%d + %d = %d\n",n1,n2,n1+n2);
			break;
		case 2:
			printf("\n\n%d - %d = %d\n",n1,n2,n1-n2);
			break;
		case 3:
			printf("\n\n%d X %d = %d\n",n1,n2,n1*n2);
			break;
		case 4:
			printf("\n\n%d / %d = %d\n",n1,n2,n1/n2);
			break;
		case 5:
			printf("\n\nExiting Program\n");
			break;
		default:
			printf("\n\nChoice Value out of Domain");
			
		}
		}

int main(){
FILE *file;
// Open the text file for reading
file = fopen("input_Q3.txt", "r");
// Read the decimal from the file
int n1,n2,choice;
do{
	
	 fscanf(file, "%d %d %d", &n1,&n2,&choice);
	
	
	calculator(n1,n2,choice);
	}while (choice!=5);
// Close the file after reading
fclose(file);
return 0;
}
