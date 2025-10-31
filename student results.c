#include <stdio.h>
#include <stdlib.h>

// Define the structure to hold student information
typedef struct {
    char name[50];
    char reg_no[20];
    float total_marks;
} Student;

int main() {
    FILE *file;
    Student student = {"Blendan Kimathi", "CT100/G/26261/25", 67.0};

    // Open the binary file for writing (creates or overwrites the file)
    file = fopen("results.dat", "wb");
    if (file == NULL) {
        printf("Error: Could not open results.dat for writing\n");
        return 1;
    }

    // Write the student record to the file
    fwrite(&student, sizeof(Student), 1, file);

    // Close the file
    fclose(file);

    printf("Student record saved successfully to results.dat ?\n");

    return 0;
}
