/*rite a program to display Fibonacci series of last term up to 300. In case of
fibonacci series Next number is the sum of previous two numbers for example 0, 1, 1,
2, 3, 5, 8, 13, 21 etc. The first two numbers of fibonacci series are 0 and 1.
 * Code by : Daksh Verma
 * Roll No : 231210036*/
 
 #include <stdio.h>


int main(){
    int i,n1=0,n2=1,sum;
    printf("%d\n",n1);
    //Iterating through the fibanacci sequence while the number is below 300 using while loop
    while (n2<300)
{   
    printf("%d\n",n2);
    sum=n1+n2;
    n1=n2;
    n2=sum;
}


    return 0;
}
