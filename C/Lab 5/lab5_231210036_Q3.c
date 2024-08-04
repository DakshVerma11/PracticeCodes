/*  Write a program in C to find whether a given year is a leap year or not. (a year is leap if it is divisible by 4 and divisible by 100 or 400.)
 *
 * Code by : Daksh Verma
 * Roll No : 231210036*/

#include <stdio.h>

int main() {
    int yr;
    printf("Enter Year: ");
    scanf("%d", &yr);

    // Check if the year is a leap year using and (&&) and or (||) conditions
    if ((yr % 100 != 0 && yr % 4 == 0) || (yr % 400 == 0)) {
        printf("Leap Year\n");
    } else {
        printf("Not a Leap Year\n");
    }

    
    return 0;
}







