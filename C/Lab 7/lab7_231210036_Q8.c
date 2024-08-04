/* Write a program to calculate sum of series 1/1!+2/2!+...n/n!
 * Code by - Daksh Verma
 * Roll No - 231210036  */

#include <stdio.h>

int fact(int x){
	int fac=1;
	while (x>0)
		fac*=x--;
	return fac;
	}

float nsum(int x){
	float i=1,sum=0;
	while (i<=x){
		sum+=(i/fact(i));
		i++;
		}
	return sum;}
	
int main(){
int n;
FILE *file;
file=fopen("input_Q8.txt","r");
fscanf(file,"%d",&n);
fclose(file);
printf("\nSum of Series = %.2f\n\n",nsum(n));
return 0;
}
