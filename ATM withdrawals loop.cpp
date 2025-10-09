#include <stdio.h>

int main() {
    float balance = 10000;   // Initial balance
    float withdrawal;        

    printf("Initial balance: %.2f\n", balance);

    while (balance > 0) {
        printf("Enter amount to withdraw: ");
        scanf("%f", &withdrawal);

        if (withdrawal > balance) {
            printf("Insufficient balance! Try a smaller amount.\n");
        } else {
            balance -= withdrawal;
            printf("Withdrawal successful.\n");
            printf("Remaining balance: %.2f\n", balance);
        }

        if (balance <= 0) {
            printf("Account balance is zero or negative. No more withdrawals allowed.\n");
            break;
        }
    }

    return 0;
    }