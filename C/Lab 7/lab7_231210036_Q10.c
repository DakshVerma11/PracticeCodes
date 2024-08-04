/* Write a c program to solve the tower of Hanoi problem. Take the number of rings as input from the user and Display the number of the step required to solve that problem.
 * Code by - Daksh Verma
 * Roll No - 231210036  */
 
 #include <stdio.h>

void towerofHanoi(int n,char fromRod,char toRod,char midRod){
	if (n == 1)
    {
        printf("\n Transfer ring 1 from rod %c to rod %c", fromRod, toRod);
        return;
    }
	towerofHanoi(n-1,fromRod,midRod,toRod);
	printf("\n Transfer ring %d from rod %c to rod %c",n,fromRod, toRod);
	towerofHanoi(n-1,midRod,toRod,fromRod);
}

int main(){
	int n;
	char fromRod,midRod,toRod;
	FILE *file;
	// Open the text file for reading
	file = fopen("input_Q10.txt", "r");
	// Read the decimal from the file
	 fscanf(file, "%d", &n);
	 fscanf(file," %c %c %c",&fromRod,&toRod,&midRod);
	// Close the file after reading
	fclose(file);
	towerofHanoi(n,fromRod,midRod,toRod);	
	printf("\n\n Task Complete\n\n");
	return 0;
}
