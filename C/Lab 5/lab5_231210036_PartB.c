/* Part B : Perceptron as Logical Operator *
 * Code by : Daksh Verma
 * Roll No : 231210036*/
#include <stdio.h>

// Function to perform OR operation between two inputs
int OR(int x1, int x2) {
    // Define weights and bias
    int w1 = 1, w2 = 1;
    float b = 0.5;
    
    // Calculate the output using the OR logic formula
    float output = x1 * w1 + x2 * w2 - b;
    
    // Return 1 if output is greater than 0, else return 0
    return output > 0 ? 1 : 0;
}

// Function to perform AND operation between two inputs
int AND(int x1, int x2) {
    // Define weights and bias
    int w1 = 1, w2 = 1, b = 1;
    
    // Calculate the output using the AND logic formula
    float output = x1 * w1 + x2 * w2 - b;
    
    // Return 1 if output is greater than 0, else return 0
    return output > 0 ? 1 : 0;
}

// Main function
int main() {
    // Test OR function with different inputs
    printf("OR(0, 0) = %d\n", OR(0, 0));
    printf("OR(0, 1) = %d\n", OR(0, 1));
    printf("OR(1, 0) = %d\n", OR(1, 0));
    printf("OR(1, 1) = %d\n\n", OR(1, 1));
    
    // Test AND function with different inputs
    printf("AND(0, 0) = %d\n", AND(0, 0));
    printf("AND(0, 1) = %d\n", AND(0, 1));
    printf("AND(1, 0) = %d\n", AND(1, 0));
    printf("AND(1, 1) = %d\n", AND(1, 1));
    
    return 0;
}

