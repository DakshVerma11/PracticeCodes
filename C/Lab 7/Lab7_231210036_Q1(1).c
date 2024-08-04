#include <stdio.h>
int decitobin(int deci){

	int bin=0,base=1;
	while (deci>0){
	bin+=(deci%2*base);
	deci/=2;
	base*=10;
	}
	
	return bin;
	}
	
	
int main(){
	int n;
	printf("\nEnter Decimal Number\t: ");
	scanf("%d",&n);
	printf("========================================");
	printf("\n\Binary number\t\t: %d",decitobin(n));
	printf("\nOctal number\t\t: %o",n);
	printf("\nHexadecimal number\t: %x\n\n",n);
	return 0;
}
