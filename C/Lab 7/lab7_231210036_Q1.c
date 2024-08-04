/* Write a program to enter a decimal number. Using function , calculate and display the • Binary equivalent • Octal equivalent • Hexadecimal equivalent 
 * Code by - Daksh Verma
 * Roll No - 231210036  */

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

int decitooct(int deci){

	int oct=0,base=1;
	while (deci>0){
	oct+=(deci%8*base);
	deci/=8;
	base*=10;
	}
	
	return oct;
	}

char* decitohex(int deci) {
    static char hex[10];
    int rem, j =9;
    while (deci > 0) {
        rem = deci % 16;
        if (rem < 10)
            hex[j++] = 48 + rem;
        else
            hex[j++] = 55 + rem;
        deci /= 16;
    }
    
    // Reverse the hexadecimal string
    int start = 0;
    int end = j - 1;
    while (start < end) {
        // Swap characters
        char temp = hex[start];
        hex[start] = hex[end];
        hex[end] = temp;
        // Move indices towards the center
        start++;
        end--;
    }
    hex[10] = '\0'; // Null-terminate the string

    return hex;
}
	
int main(){
	int n;
	
	FILE *file;
	// Open the text file for reading
	file = fopen("input_Q1.txt", "r");
	 // Read the decimal from the file
    	fscanf(file, "%d", &n);
    	// Close the file after reading
    	fclose(file);
    	printf("\nInput Number- %d",n);
	printf("\n\nBinary      - %d",decitobin(n));
	printf("\nOctal       - %d",decitooct(n));
	printf("\nHexadecimal - %s",decitohex(n));
	printf("\n\n");

return 0;
}
