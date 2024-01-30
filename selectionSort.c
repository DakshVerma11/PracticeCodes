/* BUBBLE SORT
Coded by : Daksh Verma  - 231210036
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap (int * x, int * y){
	int temp;
	temp = *x;
	*x=*y;
	*y=temp;
}
void selectionSort(int * array, int n){
    int i, j, localMin;

    for(i = 0; i < n - 1; i++){
        localMin = i;
        
        for(j = i + 1; j < n; j++){
           if (array[j] < array[localMin]){
                localMin = j;
            }
        }
        
        if (localMin != i){
            swap(&array[localMin], &array[i]);
        }
        printf("\nPass %d : ",i+1);
        for(int i=0;i<n;i++){
		printf("%d\t",array[i]);
	}
    }
}



int main(){
	int n;
	int * array;
	printf("Enter the Number of Elements in the integer array : ");
	scanf("%d",&n);
	array = (int *)(malloc(n*sizeof(int)));
	for(int i=0;i<n;i++){
		printf("Enter Element no %d - ",i+1);
		scanf("%d",&array[i]);
	}
	clock_t t;
	t = clock(); 
	selectionSort(array,n);
	t = clock() - t; 
	double time_taken = ((double)t)/CLOCKS_PER_SEC;
	printf("\nTime Taken -  %f Seconds\n", time_taken);
	printf("\nSorted List\n");
	for(int i=0;i<n;i++){
		printf("%d\t",array[i]);
	}
	size_t total_memory = sizeof(int) * (n+1); // Size of the array + temp
    	printf("\nTotal Memory Used: %lu bytes\n", total_memory);
	free(array);
	printf("\n\n");
	return 0;
}
//25 3 4 87 29 64 72

