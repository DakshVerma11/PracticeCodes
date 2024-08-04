/*Write a program in C to print the following pattern.(The number of rows and columns and
Character to display must be entered by user)
 * Code by : Daksh Verma
 * Roll No : 231210036*/
 
 #include <stdio.h>


int main(){
	int i,j,col,rows;
	char ch;
	//Taking input of the rows, columns and the character for printing the pattern 
	printf("Enter number of columns\t\t: ");
	scanf("%d",&col);
	printf("Enter number of rows\t\t: ");
	scanf("%d",&rows);
	printf("Enter Character to be entered\t: ");
	scanf(" %c",&ch);
	//Outer for loop for different rows
	for (i=1;i<=rows;i++)
	{
		//Inner for loop for printing each line
		for (j=1;j<=col;j++)
		{
			printf("%c\t",ch);
		}
	printf("\n");
	}
	return 0;
}
