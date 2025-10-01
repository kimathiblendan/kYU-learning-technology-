#include <stdio.h>

int main() {
    int units=45;
    float bill =1025.00;

    printf("Enter water units consumed: ");
    scanf("%d", &units);

    if (units <= 30) {
        bill = units * 20;
    } else if (units <= 60) {
        bill = (30 * 20) + (units - 30) * 25;
    } else {
        bill = (30 * 20) + (30 * 25) + (units - 60) * 30;
    }

    printf("Total water bill: %.2f KES\n", bill);

    return 0;
}