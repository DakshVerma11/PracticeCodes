/*Create a structure named company which has name, address, phone and noOfEmployee as member variables. Read name of company, its address, phone and noOfEmployee. Finally display these members’ value.
Code by - Daksh Verma 
Roll No - 231210036*/

#include <stdio.h>

struct company{
	char name[30];
	char address[100];
	long long unsigned int phone;
	unsigned int noOfEmployees;
};

int main(){
	struct company company1;
	FILE *f1;
	f1=fopen("Input_Q2.txt","r");
	fgets(company1.name,30,f1);
	fgets(company1.address,100,f1);
	fscanf(f1,"%llu",&company1.phone);
	fscanf(f1,"%u",&company1.noOfEmployees);


	printf("Company Name : %s\nAddress : %s\nPhone : %llu\nNumber of Employees : %u\n\n",company1.name,company1.address,company1.phone,company1.noOfEmployees);
	return 0;
}
	
