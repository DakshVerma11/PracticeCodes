/*Define a structure “complex” (typedef) to read two complex numbers and perform addition, subtraction of these two complex numbers and display the result.
Code by - Daksh Verma 
Roll No - 231210036*/

#include <stdio.h>

// Define the structure for complex numbers
typedef struct {
    float real;
    float imag;
} complex;

// Function to add two complex numbers
complex add(complex num1, complex num2) {
    complex result;
    result.real = num1.real + num2.real;
    result.imag = num1.imag + num2.imag;
    return result;
}

// Function to subtract two complex numbers
complex subtract(complex num1, complex num2) {
    complex result;
    result.real = num1.real - num2.real;
    result.imag = num1.imag - num2.imag;
    return result;
}

int main() {
    complex num1, num2, result_add, result_sub;

    // Read the first complex number
    printf("Enter the real and imaginary parts of the first complex number  (with space between them): ");
    scanf("%f %f", &num1.real, &num1.imag);

    // Read the second complex number
    printf("Enter the real and imaginary parts of the second complex number (with sapce between them): ");
    scanf("%f %f", &num2.real, &num2.imag);

    // Perform addition and subtraction
    result_add = add(num1, num2);
    result_sub = subtract(num1, num2);

    printf("\nSum: %.2f + %.2fi\n", result_add.real, result_add.imag);
    printf("Difference: %.2f + %.2fi\n", result_sub.real, result_sub.imag);

    return 0;
}

