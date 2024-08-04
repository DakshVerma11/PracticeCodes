/*Define HRA, TA , DA, Incentive , NPS ,Gross Salary & Net Salary as functions and then calculate gross salary and net salary of employee. Print detail of employee along with gross salary and net salary.
Code by - Daksh Verma 
Roll No - 231210036*/

#include <stdio.h>
#include <string.h>

// Function to calculate HRA
float calculateHRA(char city[30], float basicSalary) {
    float hraRate;
    if (strcmp(city, "Hyderabad") == 0 || strcmp(city, "Delhi") == 0 || strcmp(city, "NCR") == 0 ||
        strcmp(city, "Ahmedabad") == 0 || strcmp(city, "Bengaluru") == 0 || strcmp(city, "Greater Mumbai") == 0 ||
        strcmp(city, "Pune") == 0 || strcmp(city, "Chennai") == 0 || strcmp(city, "Kolkata") == 0) {
        hraRate = 0.24;
    } else {
        hraRate = 0.16;
    }

    return hraRate * basicSalary;
}

// Function to calculate DA
float calculateDA(float basicSalary) {
    return 0.17 * basicSalary;
}

// Function to calculate NPS
float calculateNPS(float basicSalary, float da) {
    return 0.1 * (basicSalary + da);
}

// Function to calculate TA
float calculateTA(char city[30], float da) {
    if (strcmp(city, "Hyderabad") == 0 || strcmp(city, "Delhi") == 0 || strcmp(city, "NCR") == 0 ||
        strcmp(city, "Ahmedabad") == 0 || strcmp(city, "Bengaluru") == 0 || strcmp(city, "Greater Mumbai") == 0 ||
        strcmp(city, "Pune") == 0 || strcmp(city, "Chennai") == 0 || strcmp(city, "Kolkata") == 0) {
        return 3600 + da;
    } else {
        return 1800 + da;
    }
}

// Function to calculate Gross Salary
float calculateGrossSalary(float basicSalary, float hra, float da, float ta) {
    return basicSalary + hra + da + ta;
}

// Function to calculate Net Salary
float calculateNetSalary(float grossSalary, float nps) {
    return grossSalary - nps;
}

int main() {
    char name[50], city[30];
    float basicSalary, hra, da, nps, ta, grossSalary, netSalary;

    // Get employee details from the user
    printf("Enter the name of the employee: ");
    scanf("%[^\n]", name);

    printf("Enter the city where the employee is posted: ");
    scanf("%s", city);

    printf("Enter the basic salary of the employee: ");
    scanf("%f", &basicSalary);

    // Calculate HRA, DA, NPS, TA, Gross Salary, and Net Salary
    hra = calculateHRA(city, basicSalary);
    da = calculateDA(basicSalary);
    nps = calculateNPS(basicSalary, da);
    ta = calculateTA(city, da);
    grossSalary = calculateGrossSalary(basicSalary, hra, da, ta);
    netSalary = calculateNetSalary(grossSalary, nps);

    // Print details of the employee along with gross salary and net salary
    printf("\nEmployee Details:\n");
    printf("Name: %s\n", name);
    printf("City: %s\n", city);
    printf("Basic Salary: %.2f\n", basicSalary);
    printf("HRA: %.2f\n", hra);
    printf("DA: %.2f\n", da);
    printf("NPS: %.2f\n", nps);
    printf("TA: %.2f\n", ta);
    printf("Gross Salary: %.2f\n", grossSalary);
    printf("Net Salary: %.2f\n", netSalary);

    return 0;
}
