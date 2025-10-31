#include <stdio.h>

// Function to calculate fare based on distance
float calculateFare(float distance) {
    float rate = 50.0;  // fare rate per kilometer
    float totalFare = distance * rate;
    return totalFare;
}

int main() {
    float distance, fare;

    printf("Enter distance traveled (in km): ");
    scanf("%f", &distance);

    fare = calculateFare(distance);

    printf("Total Fare: KSh. %.2f\n", fare);

    return 0;
}
