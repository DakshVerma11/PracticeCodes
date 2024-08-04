/* Write a program for fitting a straight line through a set of points (xi , yi ), i
 * Code by - Daksh Verma
 * Roll No - 231210036*/

#include <stdio.h>

int main() {
    int n, i;
    // Input the number of elements
    printf("Enter the number of elements to be input: ");
    scanf("%d", &n);
    
    float X[50] = {}, Y[50] = {}, m = 0, b = 0, sigmaX = 0, sigmaY = 0, sigmaXsq = 0, sigmaXY = 0;
    
    // Input X and Y values from the user
    for (i = 0; i < n; i++) {
        printf("Enter Element number %d\n\tX - ", i + 1);
        scanf("%f", &X[i]);
        printf("\tY - ");
        scanf("%f", &Y[i]);
    }
    
    // Calculate summations required for linear regression formula
    for (i = 0; i < n; i++) {
        sigmaX += X[i];
        sigmaY += Y[i];
        sigmaXsq += X[i] * X[i];
        sigmaXY += X[i] * Y[i];
    }
    
    // Calculate slope (m) and intercept (b) for the regression line equation Y = mX + b
    m = (n * sigmaXY - sigmaX * sigmaY) / (n * sigmaXsq - sigmaX * sigmaX);
    b = (sigmaY - m * sigmaX) / n;
    
    // Display the regression line equation
    printf("\nY = %.2f X + (%.2f)\n", m, b);
    
    float x, y;
    // Input a value of X to predict the corresponding value of Y
    printf("Enter value of X to predict value of Y: ");
    scanf("%f", &x);
    // Calculate the predicted value of Y using the regression equation
    y = m * x + b;
    // Display the predicted value of Y
    printf("Y = %.2f (Predicted for X = %.2f)\n\n", y, x);
    
    return 0;
}

