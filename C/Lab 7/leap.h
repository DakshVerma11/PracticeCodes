#include <stdio.h>

void printLeap(int x, int y){

	for(int i=x;i<=y;i++){
		if ((i%4==0 && i%100!=0)||(i%400==0))
			printf("%d\n",i);

	}
}
