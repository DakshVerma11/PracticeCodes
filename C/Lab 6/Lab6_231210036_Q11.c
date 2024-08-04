/*Write a program to enter the marks of a 1st Sem students in 10 subjects. Then calculate the
total, aggregate and display the grades obtained by the student
 * Code by : Daksh Verma
 * Roll No : 231210036*/
 
 
 #include <stdio.h>


int main(){
	int marks, total = 0, i, countAplus = 0, countA = 0, countBplus = 0, countB = 0, countC = 0, countD = 0, countF = 0;
	printf("\nEnter marks of 10 subjects :");
	for (i=0;i<10;i++){
	scanf("%d",&marks);
	total+=marks;
	if (marks >= 94) {
            printf("\nSubject %d: A+\n", i + 1);
            countAplus++;
        } else if (marks >= 85) {
            printf("Subject %d: A\n", i + 1);
            countA++;
        } else if (marks >= 70) {
            printf("Subject %d: B+\n", i + 1);
            countBplus++;
        } else if (marks >= 60) {
            printf("Subject %d: B\n", i + 1);
            countB++;
        } else if (marks >= 50) {
            printf("Subject %d: C\n", i + 1);
            countC++;
        } else if (marks >= 30) {
            printf("Subject %d: D\n", i + 1);
            countD++;
        } else {
            printf("Subject %d: F\n", i + 1);
            countF++;
        }
    }

    // Display total, aggregate, and count of grades
    printf("\n\n\nTotal marks: %d\n", total);
    printf("Aggregate: %.2f\n", total/10.0);
    printf("Grade Point : %d\n",10*countAplus+9*countA+8*countBplus+7*countB+6*countC+5*countD);
    printf("Total Count of A+: %d\n", countAplus);
    printf("Total Count of A: %d\n", countA);
    printf("Total Count of B+: %d\n", countBplus);
    printf("Total Count of B: %d\n", countB);
    printf("Total Count of C: %d\n", countC);
    printf("Total Count of D: %d\n", countD);
    printf("Total Count of F: %d\n\n\n", countF);
    
    //Printing Bar chart usng while loop
    printf("\n\nBar Chart Result:\n");
    printf("\nA+\t|");
    for (i=0;i<countAplus;i++){
    		printf("=");}
    printf("\nA\t|");
    for (i=0;i<countA;i++){
    		printf("=");}
    printf("\nB+\t|");
    for (i=0;i<countBplus;i++){
    		printf("=");}
    printf("\nB\t|");
    for (i=0;i<countB;i++){
    		printf("=");}
    printf("\nC\t|");
    for (i=0;i<countC;i++){
    		printf("=");}
    printf("\nD\t|");
    for (i=0;i<countD;i++){
    		printf("=");}
    printf("\nF\t|");
    for (i=0;i<countF;i++){
    		printf("=");}
	printf("\n\n");
	return 0;
}
