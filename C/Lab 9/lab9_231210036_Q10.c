/* Write a program that takes nouns and forms their plurals
 * Code by - Daksh Verma
 * Roll No - 231210036*/

#include <stdio.h>

char *pluralNoun(char *string) {
    int i = 0, j = 0;

    // Find the length of the input string
    while (string[i] != '\0') {
        i++;
    }

    // Create an output array
    static char output[20]; 
    
    // Copy the original string to the output
    for (j = 0; j < i; j++) {
        output[j] = string[j];
    }

    // Check pluralization rules and modify output accordingly
    if (string[i - 1] == 'y') {
        output[i - 1] = 'i';
        output[i] = 'e';
        output[i + 1] = 's';
        output[i + 2] = '\0';
    } else if (string[i - 1] == 's' || (string[i - 2] == 's' && string[i - 1] == 'h') || (string[i - 2] == 'c' && string[i - 1] == 'h')) {
        output[i] = 'e';
        output[i + 1] = 's';
        output[i + 2] = '\0';
    } else {
        output[i] = 's';
        output[i + 1] = '\0';
    }

    return output;
}

int main(){
	char string[100];
	printf("Enter nouns (End with ~) :\n");
	while (string[0]!='~'){
	scanf(" %s",string);
	if (string[0]!='~'){
	printf("Plural of %s\n\t\t- %s\n\n",string,pluralNoun(string));
	}}
	printf("End\n\n");
	
	return 0;
}
