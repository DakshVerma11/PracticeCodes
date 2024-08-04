#include <stdio.h>
int bintodeci(int bin){
	int deci=0, base=1;
	
	while (bin>0){
	deci+=(bin%10*base);
	base*=2;
	bin/=10;
	}	
	
	return deci;
}

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
	printf("Enter Binary Number\n");
	scanf(" %d",&n);
	printf("\nDecimal of binary number %d is %d\n\nEnter Decimal Number\n", n, bintodeci(n));
	scanf("%d",&n);
	printf("\n\Binary of decimal number %d is %d\n\n", n , decitobin(n));
	return 0;
}
