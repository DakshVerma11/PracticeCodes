/*Write a program using structure for railway ticket generation program that uses named initialization in a structure.
Code by - Daksh Verma 
Roll No - 231210036*/

#include <stdio.h>
struct railTicket{
	char passengerName[30];
	char trainName[30];
	char from[15];
	char to[15];
	char date[10];
	char coachNo[4];
	int seatNo;
};

void printTicket(struct railTicket t){
	printf("\n\n***************** Indian Railway Ticket ********************\n");
	printf("\nName of ticket Holder : %s",t.passengerName);
	printf("\nTrain : %s",t.trainName);
	printf("\nFrom  : %s",t.from);
	printf("\nTo    : %s",t.to);
	printf("\nDate  : %s",t.date);
	printf("\nCoach No : %s\t|\tSeat No : %d",t.coachNo,t.seatNo);
	printf("\n\n***********************************************************\n\n");
	
}

int main(){
	struct railTicket t1;
	printf("Enter Passenger Name   : ");
	scanf(" %[^\n]",t1.passengerName);
	printf("Enter Train Name       : ");
	scanf(" %[^\n]",t1.trainName);
	printf("Enter starting station : ");
	scanf(" %[^\n]",t1.from);
	printf("Enter final station    : ");
	scanf(" %[^\n]",t1.to);
	printf("Enter Date(DD/MM/YYYY) : ");
	scanf(" %[^\n]",t1.date);
	printf("Enter Coach Number     : ");
	scanf(" %[^\n]",t1.coachNo);
	printf("Enter Seat Number      : ");
	scanf("%d",&t1.seatNo);
	
	
	printTicket(t1);
	return 0;
}
