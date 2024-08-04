#include <stdio.h>

int main(){
	char letter;

	// Prompt the user to enter a character
	printf("Enter a Character: ");
	letter = getchar();

	// Convert the character to lowercase and display it
	// ASCII value of 'A' is 65, and 'a' is 97. To convert to lowercase, add 32.
	printf("Lower Case : %c \n\n", letter + 32);

	return 0;
}

