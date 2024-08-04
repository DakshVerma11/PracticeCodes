/*Create a structure to specify data of customers in a bank. T
 * Code by - Daksh Verma 
 * Roll No - 231210036*/

#include <stdio.h>
#include <string.h>
struct bank {
    long unsigned int accountNo;
    char name[30];
    float balance;
};

struct bank ABCbank[5];

void printBelow1k(struct bank *b, int n) {
    printf("Printing details of Accounts with balance below Rs.1000\n");
    for (int i = 0; i < n; i++) {
        if (b[i].balance < 1000) {
            printf("Account Number: %lu\tCustomer Name: %s\n", b[i].accountNo, b[i].name);
        }
    }
}

void withdraw(struct bank *b, long unsigned int account, int code, int max) {
    int amount;

    if (code) {
        printf("Enter Amount to be deposited: ");
        scanf("%d", &amount);
        for (int i = 0; i < max; i++) {
            if (b[i].accountNo == account) {
                b[i].balance += amount;
                printf("Account Number: %lu\tCurrent Balance: %.2f\n", b[i].accountNo, b[i].balance);
            }
        }
    } else {
        printf("Enter Amount to be Withdrawn: ");
        scanf("%d", &amount);
        for (int i = 0; i < max; i++) {
            if (b[i].accountNo == account) {
                if (b[i].balance - amount < 1000) {
                    printf("The balance is insufficient for the specified withdrawal\n");
                } else {
                    b[i].balance -= amount;
                    printf("Account Number: %lu\tCurrent Balance: %.2f\n", b[i].accountNo, b[i].balance);
                }
            }
        }
    }
}



void initializeBankData() {
  ABCbank[0].accountNo = 1;
  strcpy(ABCbank[0].name, "Aditya Sharma");
  ABCbank[0].balance = 57356.75;

  ABCbank[1].accountNo = 2;
  strcpy(ABCbank[1].name, "Mary Jane");
  ABCbank[1].balance = 161.10;

  ABCbank[2].accountNo = 3;
  strcpy(ABCbank[2].name, "David Kashyap");
  ABCbank[2].balance = 1356.85;

  ABCbank[3].accountNo = 4;
  strcpy(ABCbank[3].name, "Amardeep Singh");
  ABCbank[3].balance = 120.36;

  ABCbank[4].accountNo = 5;
  strcpy(ABCbank[4].name, "Simran Kaur");
  ABCbank[4].balance = 5356.70;
}

int main() {
    int accountno,option;
    initializeBankData();
    printBelow1k(ABCbank, 5);
    printf("\n\n");
    printf("Enter Account Number : ");
    scanf("%d",&accountno);
    printf("Do you want to \n\tDeposit (Press 1)\n\tWithdraw (Press 0)\n- ");
    scanf("%d",&option);
    withdraw(ABCbank,(accountno),option,5);
    printf("\n\n");
    return 0;
}

