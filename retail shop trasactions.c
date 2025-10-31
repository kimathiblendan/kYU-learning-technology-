#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    float amount, total = 0.0;

    // Open the file for reading
    file = fopen("sales.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open sales.txt\n");
        return 1;
    }

    // Read all transaction amounts and calculate total
    while (fscanf(file, "%f", &amount) == 1) {
        total += amount;
    }

    // Display the total sales for the day
    printf("Total Sales for the Day: %.2f\n", total);

    // Ensure the file is properly closed
    fclose(file);

    return 0;
}
