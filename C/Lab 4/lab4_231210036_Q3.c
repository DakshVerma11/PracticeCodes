#include <stdio.h>

int main(){
	int month, days;

	// Prompt the user to enter the number of days
	printf("Enter number of days: ");
	scanf("%d", &days);

	// Calculate the number of months and remaining days
	month = days / 30;  // Assuming a month has 30 days
	days = days % 30;   // Calculate the remaining days

	// Display the number of months and remaining days
	printf("Number of Month(s) is %d and number of Days is %d\n\n", month, days);

	return 0;
}

