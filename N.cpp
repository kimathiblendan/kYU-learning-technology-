#include <stdio.h>

int main() {
    float attendance, average;

    printf("Enter attendance percentage: ");
    scanf("%f", &attendance);

    printf("Enter average marks: ");
    scanf("%f", &average);

    if (attendance >= 75 && average >= 40) {
        printf("Eligible for exams.\n");
    } else {
        printf("Not eligible.\n");
    }

    return 0;
}