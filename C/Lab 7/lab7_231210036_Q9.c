/* Write a program to swap first and last digits of any number.
 * Code by - Daksh Verma
 * Roll No - 231210036  */

#include <stdio.h>

int swaplr(int x){
	int i=1,temp,copy=x,l,r,mid;
	while (x>0){
		i*=10;
		x/=10;	
	}
	r=copy%10;
	l=copy/(i/10);
	mid = (copy%(i/10)-copy%10);
	/* Debugging Lines
	printf("\nr=%d",r);
	printf("\ni=%d",i);
	printf("\nl=%d",l);
	printf("\nmid=%d",mid);*/
	temp=r*i/10+mid+l;
	
	return temp;
	}
	
int main(){
int n;
FILE *file;
file=fopen("input_Q9.txt","r");
fscanf(file,"%d",&n);
fclose(file);
printf("Input Number - %d\n",n);
printf("\nAnswer       - %d\n\n",swaplr(n));
return 0;
}
