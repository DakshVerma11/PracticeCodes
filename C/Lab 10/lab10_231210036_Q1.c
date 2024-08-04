/*Write a program to store and print the roll no, name , age, height and marks (out of 10) in subject CSB101 of a student using structures.
Code by - Daksh Verma 
Roll No - 231210036*/

#include <stdio.h>

struct student{
	unsigned int rollno;
	char name[30];
	short unsigned int age;
	unsigned int height;
	float marks;
};

int main(){
	struct student st1,st2;
	printf("Enter Student Roll No\t: ");
	scanf("%u",&st1.rollno);
	printf("Enter Student Name : ");
	scanf(" %[^\n]",st1.name);
	printf("Enter Student Age\t: ");
	scanf("%hu",&st1.age);
	printf("Enter Student Height (in cms)\t: ");
	scanf("%u",&st1.height);
	printf("Enter Student Marks\t: ");
	scanf("%f",&st1.marks);
	printf("\n\n");
	printf("Roll No : %u\nName : %s\nAge : %hu Yrs\nHeight : %u cms\nMarks : %.2f / 10",st1.rollno,st1.name,st1.age,st1.height,st1.marks);
	printf("\nSize of structure : %d\n",sizeof(st1));
	
	
	
	return 0;
}
