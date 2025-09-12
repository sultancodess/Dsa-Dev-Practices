#include<stdio.h>
int main()
{
    printf("hello Sultan Alam");

}
#include <string.h>
#include <stdlib.h>

#define MAX_ACCOUNTS 100

// Structure to store account information
struct Account {
    int accountNumber;
    char name[50];
    float balance;
};

struct Account accounts[MAX_ACCOUNTS];
int numAccounts = 0;

// Function prototypes
void createAccount();
void deposit();
void withdraw();
void checkBalance();
void displayAllAccounts();

int main() {
    int choice;
    
    while(1) {
        printf("\n=== Banking System Menu ===\n");
        printf("1. Create New Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Check Balance\n");
        printf("5. Display All Accounts\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                createAccount();
                break;
            case 2:
                deposit();
                break;
            case 3:
                withdraw();
                break;
            case 4:
                checkBalance();
                break;
            case 5:
                displayAllAccounts();
                break;
            case 6:
                printf("Thank you for using our banking system!\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}

void createAccount() {
    if(numAccounts >= MAX_ACCOUNTS) {
        printf("Maximum number of accounts reached!\n");
        return;
    }
    
    printf("\nEnter account holder name: ");
    scanf(" %[^\n]s", accounts[numAccounts].name);
    accounts[numAccounts].accountNumber = 1000 + numAccounts;
    accounts[numAccounts].balance = 0;
    
    printf("Account created successfully!\n");
    printf("Your account number is: %d\n", accounts[numAccounts].accountNumber);
    numAccounts++;
}

void deposit() {
    int accNum;
    float amount;
    
    printf("\nEnter account number: ");
    scanf("%d", &accNum);
    
    for(int i = 0; i < numAccounts; i++) {
        if(accounts[i].accountNumber == accNum) {
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);
            accounts[i].balance += amount;
            printf("Deposit successful! New balance: %.2f\n", accounts[i].balance);
            return;
        }
    }
    printf("Account not found!\n");
}

void withdraw() {
    int accNum;
    float amount;
    
    printf("\nEnter account number: ");
    scanf("%d", &accNum);
    
    for(int i = 0; i < numAccounts; i++) {
        if(accounts[i].accountNumber == accNum) {
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);
            if(amount > accounts[i].balance) {
                printf("Insufficient balance!\n");
                return;
            }
            accounts[i].balance -= amount;
            printf("Withdrawal successful! New balance: %.2f\n", accounts[i].balance);
            return;
        }
    }
    printf("Account not found!\n");
}

void checkBalance() {
    int accNum;
    
    printf("\nEnter account number: ");
    scanf("%d", &accNum);
    
    for(int i = 0; i < numAccounts; i++) {
        if(accounts[i].accountNumber == accNum) {
            printf("Account Holder: %s\n", accounts[i].name);
            printf("Current Balance: %.2f\n", accounts[i].balance);
            return;
        }
    }
    printf("Account not found!\n");
}

void displayAllAccounts() {
    if(numAccounts == 0) {
        printf("\nNo accounts exist!\n");
        return;
    }
    
    printf("\n=== All Account Details ===\n");
    for(int i = 0; i < numAccounts; i++) {
        printf("\nAccount Number: %d\n", accounts[i].accountNumber);
        printf("Account Holder: %s\n", accounts[i].name);
        printf("Balance: %.2f\n", accounts[i].balance);
        printf("-------------------------\n");
    }
}
