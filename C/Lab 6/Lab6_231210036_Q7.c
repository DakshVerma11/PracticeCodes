/*Write a program to print the multiplication table from 1x1 to 12 x10 as shown below
 * Code by : Daksh Verma
 * Roll No : 231210036*/
 
 #include <stdio.h>


int main(){
	int i,j;
	//outer for loop for rows
	for (i=1;i<=12;i++)
	{
		//inner for loop for values inside each row
		for (j=1;j<=10;j++)
		{
			printf("%d\t",i*j);
		}
	printf("\n");
	}

	return 0;

}
