#include <stdio.h>


int main(){
	int x=2,z=4,y;

	y=x<z ? z:x;
	printf("\n%d\n",y);
	//x is less than z so expression 1 (z) is printed  ->4
	
	x=2;
	z=4;
	y = x++ + ++x;
	printf("%d\n",y);
	// x(2) is added then implemented to 3 and then x is first implemented to 4 and then added => 2+4=6
	
	x=2;
	z=4;
	y = ++x + ++x;
	printf("%d\n",y);
	//++ takes precedence over + operator and hence x is incremented twice to 4 so 4+4=8 is printed
	
	x=2;
	z=4;
	y = ++x + ++x + ++x;
	printf("%d\n",y);
	// ++ takes precedence over + and its associativity is right to left so the statement can be written as ++x + ( ++x + ++x) = ++x +(4+4)=5+4+4=13
	
	x=2;
	z=4;
	y = x>z;
	printf("%d\n",y);
	//x is not greater than 4, hence x>z is false so 0
	
	x=2;
	z=4;
	y = x|z;
	printf("%d\n",y);
	//2=010 and 4=100 so bitwise or results in 110 = 6
	
	x=2;
	z=4;
	y=x>>2+z<<1;
	printf("%d\n",y);
	//+ operator precedes >>  and hence x>>2+z<<1 is computed as x>>6<<1 then 0<<1=0
	
	
	return 0;
	
}
	
