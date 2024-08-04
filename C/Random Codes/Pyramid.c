#include<stdio.h>
int main()
{ 
    printf("start");
    for (int i=0;i<5;i++){
        printf("\n");
        int a=65;
        for (int j=5;j>i;j--)printf(" ");
        
        for (int j=0;j<=i;j++)printf("%c ",a++);

    }
    return 0;
}