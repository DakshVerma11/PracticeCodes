/*Design a calculator which takes input as a choice for operation to perform on them(1 for
addition, 2 for subtraction, 3 for multiplication, 4 for division, 5 for exit) and two
numbers(if required by operation) . The program should not terminate until the user
don’t choose to close it. (Use do while ). Use goto statement to transfer control out of a
loop if an unexpected condition arises. (eg : use goto errorcheck 
 * Code by : Daksh Verma
 * Roll No : 231210036*/
 
 #include <stdio.h>


int main(){
	int n1,n2,choice;

	do{
	start:
	// Display menu and prompt user for choice
	printf("\nEnter\t1 to Add\n\t2 to Subtract\n\t3 to Multiply\n\t4 to Divide\n\t5 to exit\n");
	
	scanf("%d",&choice);
	// Perform operation based on user choice
	switch (choice){
		case 1:
			printf("\nEnter the two numbers\n");
			scanf("%d %d",&n1,&n2);
			printf("\n\n%d + %d = %d\n",n1,n2,n1+n2);
			break;
		case 2:
			printf("\nEnter the two numbers\n");
			scanf("%d %d",&n1,&n2);
			printf("\n\n%d - %d = %d\n",n1,n2,n1-n2);
			break;
		case 3:
			printf("\nEnter the two numbers\n");
			scanf("%d %d",&n1,&n2);
			printf("\n\n%d X %d = %d\n",n1,n2,n1*n2);
			break;
		case 4:
			printf("\nEnter the two numbers\n");
			scanf("%d %d",&n1,&n2);
			printf("\n\n%d / %d = %d\n",n1,n2,n1/n2);
			break;
		case 5:
			printf("\n\nExiting Program\n");
			break;
		default:
			goto errorcheck;
			
		}
	
		
	} while (choice!=5);
	
	return 0;
	
	errorcheck:
		printf("\n\nError: Choice input not in Domain.");
		goto start;
	return 0;
}
