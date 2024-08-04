#include <stdio.h>

int main(){
	int num1, num2;

	// Prompt the user to enter two numbers
	printf("Enter two numbers :\n");
	scanf("%d %d",&num1,&num2);

	// Perform Bitwise AND operation on num1 and num2 and display the result
	printf("\n\nPerforming Bitwise AND function on num1(%d)  and num2(%d) \n%d",num1,num2,num1&num2);
	
	// Perform Bitwise OR operation on num1 and num2 and display the result
	printf("\n\nPerforming Bitwise Or function on num1(%d)  and num2(%d) \n%d",num1,num2,num1|num2);
	
	// Perform Bitwise XOR operation on num1 and num2 and display the result
	printf("\n\nPerforming Bitwise XOR function on num1(%d) and num2(%d) \n%d",num1,num2,num1^num2);
	
	// Perform Bitwise complement operation on num1 and num2 and display the result
	printf("\n\nPerforming Bitwise complement function on num1(%d) - %d and num2(%d) - %d",num1,~num1,num2,~num2);
	
	// Perform Shift right operation on num1 and num2 and display the result
	printf("\n\nPerforming Shift right function on num1(%d) - %d and num2(%d) - %d ", num1,(num1>>1),num2,(num2>>1));
	
	// Perform Shift Left operation on num1 and num2 and display the result
	printf("\n\nPerforming Shift Left function on num1(%d) - %d and num2(%d) - %d\n\n ", num1,(num1<<1),num2,(num2<<1));
	
	return 0;
}

