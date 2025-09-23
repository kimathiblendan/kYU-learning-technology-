#include <stdio.h>
#include <math.h>   // for M_PI (value of π)

int main() {
    float radius, height, volume, surfaceArea;

    // Prompt user input
    printf("Enter the radius of the cylinder: ");
    scanf("%f", &radius);

    printf("Enter the height of the cylinder: ");
    scanf("%f", &height);

    // Calculations
    volume = M_PI * radius * radius * height;
    surfaceArea = (2 * M_PI * radius * radius) + (2 * M_PI * radius * height);

    // Display results
    printf("Volume of the cylinder = %.2f\n", volume);
    printf("Surface Area of the cylinder = %.2f\n", surfaceArea);

    return 0;
    }