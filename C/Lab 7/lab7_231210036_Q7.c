/* Write a program to calculate pow(x,n) i.e to calculate x n , where n is negative or positive.
A) Using recursion b) without recursion
 * Code by - Daksh Verma
 * Roll No - 231210036  */

#include <stdio.h>

int powworec(int x,int y){
int power=1;
for (y;y>0;y--)
	power*=x;
return power;
}

int powrec(int x,int y){
if(y==0) return 1;
return x*powrec(x,y-1);
}

int main(){
int x,y;
FILE *file;
file=fopen("input_Q7.txt","r");
fscanf(file,"%d %d",&x,&y);
fclose(file);
printf("\nWithout Recursion-\n%d^%d = %d\n\n",x,y,powworec(x,y));
printf("\nWith Recursion-\n%d^%d = %d\n\n",x,y,powrec(x,y));
return 0;
}
