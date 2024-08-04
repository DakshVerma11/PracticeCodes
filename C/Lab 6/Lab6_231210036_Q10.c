/*Write a program to calculate sum of series 1/2+2/3+3/4.....n/n+1
 * Code by : Daksh Verma
 * Roll No : 231210036*/
 
 #include <stdio.h>


int main(){
	float sum=0,i=1,n;
	//taking input
	printf("\nEnter the number to calculate the value of the series : ");
	scanf("%f",&n);
	//iterating through the required values using while loop
	while (i<=n){
		printf("%.0f/%.0f + ",i,(i+1));
		sum+=i/(1+i);
		i++;}

	printf("\nSum of the series is : %.2f\n",sum);


	return 0;

}
