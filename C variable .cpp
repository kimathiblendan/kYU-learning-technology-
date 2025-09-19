/*
Name:Blendan
Reg:CT100/G/26261/25
Description : variables
*/

#include <stdio.h>

int main() {
    float height=1.8, weight=60.00;
    char phonenumber[20]="0793796740"; 

    // Prompt user for inputs
    printf("Enter your height (in metres): ");
    scanf("%f", &height);

    printf("Enter your phonenumber: ");
    scanf("%s", phonenumber);

    printf("Enter your weight (in kg): ");
    scanf("%f", &weight);

    // Display the entered information
    printf("\n--- Your Details ---\n");
    printf("Height: %.2f inches\n", height);
    printf("phoneNumber: %s\n", phonenumber);
    printf("Weight: %.2f kg\n", weight);

    return 0;
}



