#include <stdio.h>

float calculateElectricBill(int units) {
    float bill = 0;

    if (units <= 100) {
        bill = units * 10;
    } else if (units <= 200) {
        bill = (100 * 10) + ((units - 100) * 15);
    } else {
        bill = (100 * 10) + (100 * 15) + ((units - 200) * 20);
    }

    return bill;
}

// Example usage
int main() {
    int units = 250;
    float totalBill = calculateElectricBill(units);
    printf("Total bill for %d units is: KSh. %.2f\n", units, totalBill);
    return 0;
}
